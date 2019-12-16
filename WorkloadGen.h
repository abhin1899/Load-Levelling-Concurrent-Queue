#ifndef WORKLOADGEN
#define WORKLOADGEN

#include "TaskGen.h"
#include<iostream>
#include<unistd.h>

using namespace std;

class WorkloadGen {

    private:
    int nThreads;
    int clientID;
    Queue<Message> *q; // The Queue into which messages are inserted

    public:
    WorkloadGen(int nThreads, Queue<Message> *q1, int clientID);
    void startService();
    
};

#endif