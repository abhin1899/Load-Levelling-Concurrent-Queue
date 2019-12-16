#include "ServiceFactory.h"

ServiceFactory::ServiceFactory(int nThreads, Queue<Message> *q1): nThreads(nThreads), q(q1) {}


ServiceExec* ServiceFactory::makeService() {
    if(nThreads==1) {
        return new SyncServiceExec(q);
    }
    else if(nThreads>1) {
        return new AsyncServiceExec(nThreads,q);
    }
}
