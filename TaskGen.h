#ifndef TASKGEN
#define TASKGEN

#include "Queue.h"
#include "Message.h"

#include<iostream>
#include <thread>
#include<time.h>

using namespace std;

class TaskGen {
    
    private :
    //    int nMessages; // Number of messages per thread;
       int clientID;
       int messageID;
       Queue<Message> *q; // The Queue into which messages are inserted
       void pushMessage (Message m1);

    public:
        TaskGen(int clientID, int messageID, Queue<Message> *q1);
        thread startTask();       

};


#endif