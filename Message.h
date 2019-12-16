#ifndef MESSAGE
#define MESSAGE

#include<iostream>
using namespace std;

class Message {
    
    private :
       int client_id;
       string message;
       int message_id;

    public:
        Message(int client_id, string message, int message_id);
        Message();
        string getMessage();
        int getMessageID();
        int getClientID();

};


#endif