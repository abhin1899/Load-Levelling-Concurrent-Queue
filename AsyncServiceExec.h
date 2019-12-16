#ifndef ASYNCSERVICEEXEC
#define ASYNCSERVICEEXEC

#include "ServiceExec.h"
#include<iostream>

using namespace std;


class AsyncServiceExec : public ServiceExec {    
        
    public:
        AsyncServiceExec(int nThreads,Queue<Message> *q1);
        void startService();    // keep on checking for requests in the queue and make an write if there is an incoming message       
};


#endif
