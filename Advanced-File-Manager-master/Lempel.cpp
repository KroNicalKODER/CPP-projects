#include "Lempel.h"

Lempel::Lempel(int max_code_length) : max_code_length(max_code_length) {
    initializeDictionary();
}

void Lempel::compressRecycle(const string& input_file, const string& output_file) {
    ifstream input(input_file, ios::binary);
    if (!input.is_open()) {
        cerr << "Error opening input file." << endl;
        return;
    }

    ofstream output(output_file, ios::binary);
    if (!output.is_open()) {
        cerr << "Error opening output file." << endl;
        return;
    }

    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[string(1, (char) i)] = i;
    }

    int next_code = 256;
    string current_string;
    char c;

    while (input.get(c)) {
        string new_string = current_string + c;

        // If the new string is already in the dictionary, update the current string
        if (dictionary.count(new_string)) {
            current_string = new_string;
        }
        // Otherwise, output the code for the current string and add the new string to the dictionary
        else {
            int code = dictionary[current_string];
            output.write(reinterpret_cast<const char*>(&code), sizeof(int));
            dictionary[new_string] = next_code++;
            current_string = string(1, c);
        }
    }

    if (!current_string.empty()) {
        int code = dictionary[current_string];
        output.write(reinterpret_cast<const char*>(&code), sizeof(int));
    }

    input.close();
    output.close();
}

void Lempel::decompressRecycle(const string& compressed_file, const string& output_file) {
    ifstream input(compressed_file, ios::binary);
    if (!input) {
        cerr << "Failed to open file for reading: " << compressed_file << endl;
        return;
    }

    ofstream output(output_file, ios::binary);
    if (!output) {
        cerr << "Failed to open file for writing: " << output_file << endl;
        return;
    }

    // Read the header from the compressed file
    unsigned int dict_size;
    input.read(reinterpret_cast<char*>(&dict_size), sizeof(dict_size));
    vector<string> dictionary(dict_size);
    for (unsigned int i = 0; i < dict_size; i++) {
        getline(input, dictionary[i]);
    }

    for (int i = 0; i < 256; i++) {
        dictionary.push_back(string(1, static_cast<char>(i)));
    }

    unsigned int current_index;
    unsigned int previous_index;
    unsigned int next_index = 256;
    input.read(reinterpret_cast<char*>(&current_index), sizeof(current_index));
    output.write(dictionary[current_index].c_str(), dictionary[current_index].length());
    while (input.read(reinterpret_cast<char*>(&previous_index), sizeof(previous_index))) {
        if (previous_index >= dictionary.size()) {
            dictionary.push_back(dictionary[current_index] + dictionary[current_index][0]);
        }
        else {
            dictionary.push_back(dictionary[current_index] + dictionary[previous_index][0]);
        }
        output.write(dictionary.back().c_str(), dictionary.back().length());
        current_index = previous_index;
    }

    input.close();
    output.close();
}


void Lempel::initializeDictionary() {
    dictionary.clear();
    next_code = 0;

    for (int i = 0; i < 256; i++) {
        string c = string(1, (char)i);
        dictionary[c] = next_code++;
    }
}

void Lempel::resetDictionary() {
    initializeDictionary();
}

void Lempel::addCodeToDictionary(const string& code) {
    dictionary[code] = next_code++;
}
