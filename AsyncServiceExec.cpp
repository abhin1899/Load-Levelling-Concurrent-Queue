#include "AsyncServiceExec.h"


AsyncServiceExec:: AsyncServiceExec(int nThreads,Queue<Message> *q1) : ServiceExec(nThreads, q1) { }


void AsyncServiceExec::startService() {
    cout<< "Asynchronous Service Started"<<endl;
    vector<thread> threads;
    // checkForRequests();

    for(int i=0; i<nThreads; i++) {
        
        threads.push_back(std::thread(&AsyncServiceExec::checkForRequests,this));
    }

    for(int i=0;i< threads.size(); i++){
        threads[i].join();
    }
}