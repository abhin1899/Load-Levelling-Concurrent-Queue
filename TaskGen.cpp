#include "TaskGen.h"

TaskGen::TaskGen(int clientID, int messageID, Queue<Message> *q1) : clientID(clientID), messageID(messageID), q(q1) { }

void TaskGen::pushMessage(Message m1) {
    q->push(m1);
}


thread TaskGen::startTask()
{
    vector<Message>v1;
    srand (time(NULL));
    // for(int i=0;i<1;i++) {
        Message m = Message(clientID,"Test",messageID);
        // v1.push_back(m);
    //}

    // std::thread t1(pushMessage,std::ref(v1));
    //pushMessage(v1);
    std::thread t1(&TaskGen::pushMessage,this,m);
    return t1;
    //t1.join();
}







