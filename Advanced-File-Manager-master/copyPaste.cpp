

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{  string source_Files,Destination_files;
     cout<<"Enter the Source file Name";
    cin>>source_Files;

     cout<<"Enter the Destination file Name";
    cin>>Destination_files;
    
    ifstream source(source_Files);
    
    if (!source) {
        cout << "Error opening source file.\n";
        return 1;
    }
   
    ofstream dest(Destination_files);
   
    if (!dest) {
        cout << "Error opening destination file.\n";
        return 1;
    }
    
  
    cout << "Enter the option to copy:\n";
    cout << "1. A specific word\n";
    cout << "2. A specific line\n";
    cout << "3. The complete file\n";
    int option;
    cin >> option;
    
    switch (option) {
        case 1:  cout << "Enter the word to copy: ";
          {  string word;
            cin >> word;
           
            string line;
            while (getline(source, line)) {
                if (line.find(word) != string::npos) {
                  
                    dest << word << "\n";
                    break;
                }
            }}
            break;
        case 2:cout << "Enter the line number to copy: ";
           { int line_number;
            cin >> line_number;
       
            string line;
            int current_line = 1;
            while (getline(source, line)) {
               
                if (current_line == line_number) {
                  
                    dest << line << "\n";
                    break;
                }
                current_line++;
            }}
            break;
        case 3:dest << source.rdbuf();
            break;
        default: 
            cout << "Invalid option.\n";
            return 1;
    }
    
   
    source.close();
    dest.close();
    return 0;
}