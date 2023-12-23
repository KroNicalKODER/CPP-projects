#include<history.h>
#include<sstream>

using namespace std;

void History :: addRecord(string filename, chrono::system_clock::time_point timestamp, void* frmPointer, void* toPointer, string action){
    time_t now = time(0);
    // Create new record and add to vector
    HistoryStruct record = {action, filename, timestamp, frmPointer, toPointer};
    records_.push_back(record);
}

void copy(string filename, void* frmPointer, void* toPointer){
    ofstream output("copy.txt",ios::binary);
    //READ FILE FROMPOINTER TO TOPOINTER AND COPY IT TO A FILE NAMED COPY.TXT
}

void paste(string filename, void* frmPointer){
    //WRITE THE FILE FROM COPY.TXT to filename.TXT
}

vector<HistoryStruct> History :: getRecords() const {
    vector<HistoryStruct> records = {};
    ifstream input("history.dat",ios::binary);
    if(!input){
        cout << "Error opening the file" << endl;
        return {};
    }
    HistoryStruct readRecord;

    while(!input.eof()) {
        input.read(reinterpret_cast<char *>(&readRecord), sizeof(readRecord));
        records.push_back(readRecord);
    }
    return records;
}


