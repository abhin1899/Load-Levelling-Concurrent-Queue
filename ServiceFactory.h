#ifndef SERVICEFACTORY
#define SERVICEFACTORY

#include "Queue.h"
#include "Message.h"
#include "ServiceExec.h"
#include "AsyncServiceExec.h"
#include "SyncServiceExec.h"
#include "ServiceExec.h"

#include<iostream>
using namespace std;

class ServiceFactory {
    private:
        int nThreads;
        Queue<Message> *q;
    
    public:
        ServiceFactory(int nThreads, Queue<Message> *q1);
        ServiceExec* makeService();

};

#endif 