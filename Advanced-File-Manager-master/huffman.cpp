#include "huffman.h"

using namespace std;

namespace Huffman
{

    HuffmanTree::HuffmanTree(const string &inputFile)
    {
        // Count the frequency of each character in the input file
        vector<int> frequencies(256, 0);
        ifstream input(inputFile);
        char c;
        

        while (input.get(c))
        {
            frequencies[c]++;
        }
        input.close();

        buildTree(frequencies);

        buildEncodings(root, "");
    }


    void HuffmanTree::buildTree(const vector<int> &frequencies)
    {
        priority_queue<Node *, vector<Node *>, CompareNodes> pq;
        //Making leafNodes first
        for (int i = 0; i < frequencies.size(); i++)
        {
            if (frequencies[i] > 0)
            {
                pq.push(new Node(i, frequencies[i]));
            }
        }
        cout<<pq.size();
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            pq.push(new Node(left, right));
        }
        root = pq.top();
    }

    void HuffmanTree::buildEncodings(const Node *node, const string &encoding)
    {
        if (node->val != 0)
        {
            encodings[node->val] = encoding;
            return;
        }
        buildEncodings(node->left, encoding + "0");
        buildEncodings(node->right, encoding + "1");
    }

    void compress(const string &inputFile, const string &output_file)
    {
        // Build Huffman tree from text file
        HuffmanTree tree(inputFile);

        // Open input and output files
        ifstream input(inputFile, ios::binary);
        ofstream output(output_file, ios::binary);

        // Write encoding or code bits number in output file
        map<char, string> encodings = tree.encodings;
        int numChars = encodings.size();
        output.write(reinterpret_cast<const char *>(&numChars), sizeof(int));
        for (auto it = encodings.begin(); it != encodings.end(); ++it)
        {
            char val = it->first;
            const string &encoding = it->second;
            output.write(reinterpret_cast<const char *>(&val), sizeof(char));
            int encodingLength = encoding.length();
            output.write(reinterpret_cast<const char *>(&encodingLength), sizeof(int));
            output.write(encoding.c_str(), encodingLength);
        }

        // write input file to the output file in compressed manner
        int bitss = 0;
        char bytes = 0;
        char c;
        while (input.get(c))
        {
            string encoding = encodings[c];
            for (int i = 0; i < encoding.length(); i++)
            {
                if (encoding[i] == '1')
                {
                    bytes |= 1 << (7 - bitss);
                }
                bitss++;
                if (bitss == 8)
                {
                    output.put(bytes);
                    bytes = 0;
                    bitss = 0;
                }
            }
        }
        if (bitss > 0)
        {
            output.put(bytes);
        }

        // Close the input and output files
        input.close();
        output.close();
    }

    void decompress(const string &inputFile, const string &output_file)
    {
        ifstream input(inputFile, ios::binary);
        ofstream output(output_file, ios::binary);

        // Read the encodings from the input file
        int numChars;
        input.read(reinterpret_cast<char *>(&numChars), sizeof(int));
        map<string, char> decodings;
        for (int i = 0; i < numChars; i++)
        {
            char val;
            int encodingLength;
            input.read(reinterpret_cast<char *>(&val), sizeof(char));
            input.read(reinterpret_cast<char *>(&encodingLength), sizeof(int));
            char *encodingChars = new char[encodingLength + 1];
            input.read(encodingChars, encodingLength);
            encodingChars[encodingLength] = '\0';
            string encoding(encodingChars);
            decodings[encoding] = val;
            delete[] encodingChars;
        }

        string currentEncoding = "";
        char c;
        while (input.get(c))
        {
            for (int i = 7; i >= 0; i--)
            {
                if ((c >> i) & 1)
                {
                    currentEncoding += "1";
                }
                else
                {
                    currentEncoding += "0";
                }
                auto it = decodings.find(currentEncoding);
                if (it != decodings.end())
                {
                    output.put(it->second);
                    currentEncoding = "";
                }
            }
        }

        input.close();
        output.close();
    }

    long long fileSize(string &filename) {
        ifstream file(filename, ios::binary | ios::ate);
        return file.tellg();
    }

}

using namespace Huffman;



int main()
{
    string inputFile = "test.txt";
    string compressedFile = "compressed.dat";
    compress(inputFile, compressedFile);
    string decompressedFile = "decompressed.txt";
    decompress(compressedFile, decompressedFile);

    cout<<endl<<fileSize(decompressedFile) - fileSize(compressedFile)<<endl;    

    return 0;
}
