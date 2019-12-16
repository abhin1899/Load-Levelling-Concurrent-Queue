# include "Message.h"
#include "Queue.h"
#include "WorkloadGen.h"
#include "ServiceFactory.h"

#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Please press ctrl+^c to stop the process"<<endl;
    Queue<Message> q1;
    
    auto start = chrono::steady_clock::now();
    WorkloadGen g1 = WorkloadGen(2000,&q1,1); 
    g1.startService();
    // usleep(20000000);
    WorkloadGen g2 = WorkloadGen(2000,&q1,2); 
    g2.startService();
    
    // cout<<q1.size();
    ServiceFactory f1 = ServiceFactory(50,&q1);
    ServiceExec *s1 = f1.makeService();
    s1->startService();
   
   	auto end = chrono::steady_clock::now();
    
    cout << "Elapsed time in nanoseconds : " 
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : " 
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : " 
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec" <<endl;

    cout<<"Average Time --> "<< std::setprecision(10)<<4000/chrono::duration_cast<chrono::seconds>(end - start).count() <<endl;
}


