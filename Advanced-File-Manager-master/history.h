#ifndef HISTORY_H
#define HISTORY_H

#include<bits/stdc++.h>
#include<ctime>

using namespace std;

class HistoryStruct{
    public:
        string operation;
        string file;
        chrono::system_clock::time_point timestamp;
        void* fromPtr;
        void* toPtr;
};

class History{
    public: 
        void addRecord(string filename, chrono::system_clock::time_point timestamp, void* frmPointer, void* toPointer, string action);
        vector<HistoryStruct> getRecords() const;
        void undo();
        void redo();
        void saveToFileHistory(string filename) const;
        void loadFromFileHistory(string filename);
        vector<HistoryStruct> records_;
        int currentRecordIndex_ = -1;
};

#endif