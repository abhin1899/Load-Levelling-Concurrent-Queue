#include "ServiceExec.h"


ServiceExec::ServiceExec(int nThreads, Queue<Message> *q1) : nThreads(nThreads),q(q1){};

void ServiceExec::signal_callback_handler(int signum) {
   cout << "Service Executor Stopped" << endl;
   // Terminate program
   exit(signum);
}

void ServiceExec::writeMessage(Message message) {
    FILE *fptr;
    string filename = "temp/"+to_string(message.getClientID())+to_string(message.getMessageID()) + ".txt";
    ofstream out(filename);
    out << message.getMessage();
    out.close();
    usleep(50000);
    cout<<"Processed Message With clientID "<<message.getClientID()<<"---"<<"Processed Message With MessageID "<<message.getMessageID()<<endl;
}

void ServiceExec::checkForRequests() {
    signal(SIGINT, signal_callback_handler);
    while(!q->empty()) {
        if(!q->empty())
        writeMessage(q->pop());
    }
}

