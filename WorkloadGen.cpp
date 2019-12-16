#include "WorkloadGen.h"

WorkloadGen::WorkloadGen(int nThreads, Queue<Message> *q1, int clientID) : nThreads(nThreads), q(q1), clientID(clientID) {}


void WorkloadGen::startService() {
    vector<thread> threads;
    cout<<"Workload Generator Started"<<endl;
    for(int i=0; i<nThreads; i++) {
        TaskGen t = TaskGen(clientID,i,q);
        threads.push_back(t.startTask());
    }

    for(int i=0;i< threads.size(); i++){
        threads[i].join();
    }

    
    
}

// vector<Message>v1;
//     srand (time(NULL));
//     for(int i=0;i<nMessages;i++) {
//         Message m = Message(1,"TestTestTestTestTestTestTestTestTestTestTest",rand() % 50000 + 1);
//         v1.push_back(m);
//     }

//     // std::thread t1(pushMessage,std::ref(v1));
//     //pushMessage(v1);
//     std::thread t1(&TaskGen::pushMessage,this,v1);
//     return t1;