#ifndef SERVICEEXEC
#define SERVICEEXEC

#include "Queue.h"
#include "Message.h"
#include <cstdlib>
#include <signal.h>
#include <unistd.h>
#include <thread>
#include <fstream>
#include<iostream>
using namespace std;


class ServiceExec {
    protected:
        // int operations_supported;
        Queue<Message> *q;
        virtual void checkForRequests(); 
        virtual void writeMessage(Message message);
        static void signal_callback_handler(int signum);
        int nThreads;
    public:
        ServiceExec(int nThreads,Queue<Message> *q1);
        virtual void startService() = 0;    // keep on checking for requests in the queue and make an write if there is an incoming message
       
};


#endif
