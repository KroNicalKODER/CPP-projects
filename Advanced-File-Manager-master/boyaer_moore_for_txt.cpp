#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


#define ASCII_SIZE 256
int ok=0;


void badCharHeuristic(char* pattern, int patternLength, int badChar[ASCII_SIZE]) {
    
    memset(badChar, -1, sizeof(int) * ASCII_SIZE);

   
    for (int i = 0; i < patternLength; i++)
        badChar[pattern[i]] = i;
}


void searchPattern(char* pattern, char* textFile) {
   
    ifstream file(textFile);
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

   
    int patternLength = strlen(pattern);
    int textLength;
    file.seekg(0, ios::end);
    textLength = file.tellg();
    file.seekg(0, ios::beg);

    
    char* text = new char[textLength];
    file.read(text, textLength);
    file.close();

   
    int badChar[ASCII_SIZE];
    badCharHeuristic(pattern, patternLength, badChar);

  
    int i = 0;
    while (i <= (textLength - patternLength)) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[i+j]) {
            j--;
        }
        if (j < 0) {
           ok=1;
           break;
        } else {
            i += max(1, j - badChar[text[i+j]]);
        }
    }

    delete[] text;
}

int main() {
    char pattern[] = "magni";
    char textFile[] = "test.txt";
    searchPattern(pattern, textFile);
    if(ok==0)
    cout<<"patter not fount"<<endl;
    else
    cout<< pattern<<" fount at file at" <<textFile<<endl;
    return 0;
}
