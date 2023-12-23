#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <bits/stdc++.h>
using namespace std;

namespace Huffman {

    struct Node {
        char val;
        int frequency;
        Node* left;
        Node* right;

        Node(char sym, int freq) {              //FOR MAKING THE LEAF NODES
            val = sym;
            frequency = freq;
            left = NULL;
            right = NULL;
        }

        Node(Node* leftt, Node* rightt) {       //FOR MAKING UPPER NODES WHICH ONLY HAVE FREQUENCIES
            val = 0;
            frequency = leftt->frequency + rightt->frequency;
            left = leftt;
            right = rightt;
        }

        ~Node() {
            delete left;
            delete right;
        }
    };

    struct CompareNodes {
        bool operator()(Node* a, Node* b) {
            return a->frequency > b->frequency;
        }
    };

    class HuffmanTree {
    public:
        HuffmanTree(const string& input_file);
        Node* root;
        map<char, string> encodings;

        void buildTree(const vector<int>& frequencies);
        void buildEncodings(const Node* node, const string& encoding);
    };

    void compress(const string& input_file, const string& output_file);
    void decompress(const string& input_file, const string& output_file);
    long long fileSize(string& filename);
}

#endif
