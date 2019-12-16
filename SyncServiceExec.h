#ifndef SYNCSERVICEEXEC
#define SYNCSERVICEEXEC

#include "ServiceExec.h"
#include<iostream>

using namespace std;


class SyncServiceExec : public ServiceExec {    
        
    public:
        SyncServiceExec(Queue<Message> *q1);
        void startService();    // keep on checking for requests in the queue and make an write if there is an incoming message       
};


#endif
