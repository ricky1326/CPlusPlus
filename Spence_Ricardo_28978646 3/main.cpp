#include <iostream>
#include <vector>
#include <list>
#include "minHeap.h"
#include "HBLT.h"
#include <ctime>
using namespace std;

int minimum(vector<int> machines){
    int min = machines.at(0);
    
    int vectIndex = 0;
    
    for(int i = 0; i< machines.size(); i++){
        
        int num1 = machines.at(i);
        
        
        if(num1 == 0){
            min = num1;
            vectIndex = i;
            return vectIndex;
            
        }
        
        else if(num1 < min){
            min = num1;
            vectIndex = i;
        }
        
        
        else{
            continue;
        }
        
        
    }
   

    
    return vectIndex;

    
}


int main(){
    int numMachines;
    int numJobs;
    int processTime;
    vector<int> jobsEntered;
    list<int> jobsOrdered;
    HBLT h1;
    minHeap h2;
    
    
   
    
    cout<<"Enter number of job(s):"<<endl;
    cin>>numJobs;
    
    cout<<"Enter number of machine(s):"<<endl;
    cin>>numMachines;
    vector<int> machines(numMachines,0);
    vector<int> machines1(numMachines,0);
    
    
    
    cout<<"Enter Processing Time(s):"<<endl;
    for(int i = 0; i< numJobs; i++){
        cin>>processTime;
       
        jobsEntered.push_back(processTime);
        
    }
    clock_t startTime = clock();
    for(int i = 0; i<jobsEntered.size(); i++){
        h1.push(jobsEntered.at(i));
    }
    int k = h1.getSize();
    cout<<endl;
    

    for(int i=0; i<numJobs; i++){
        jobsOrdered.push_front(h1.top());
        h1.pop();
    }
  
    
    for(int i = 0 ; i<numJobs; i++){
        int a = minimum(machines);
      //cout<< "Inserting process: "<< jobsOrdered.front() << " at machine: "<< a<<endl; 
        machines.at(a) = machines.at(a)+jobsOrdered.front();
    
        jobsOrdered.pop_front();
        
        
        
        if (i == numJobs-1) {
            clock_t endTime = clock();
	    cout<<"Height Biased Leftist Tree:"<<endl;
            cout <<"Finish Time = "<< machines.at(a)<<endl;
	    
	    clock_t timeElapsed = endTime - startTime;
	   double totalTime = timeElapsed / (double) CLOCKS_PER_SEC;	
	    cout<<"total time: " << totalTime <<endl;
	    
        }
    }
    
    for(int i = 0; i<numMachines; i++){
        cout<<"Machine " << i+1<< "= "<< machines.at(i)<<endl;
    }
    
    clock_t startTime1 = clock();
    for(int i = 0; i<jobsEntered.size(); i++){
        h2.push(jobsEntered.at(i));
    }
    cout<<endl;

    for(int i=0; i<numJobs; i++){
	jobsOrdered.push_front(h2.top());
        h2.pop();
   
    }
  
    
    for(int i = 0 ; i<numJobs; i++){
        int a = minimum(machines1);
	//cout<< "Inserting process: "<< jobsOrdered.front() << " at machine: "<< a<<endl;
        machines1.at(a) = machines1.at(a)+jobsOrdered.front();
        jobsOrdered.pop_front();
        
        
        
        if (i == numJobs-1) {
            clock_t endTime1 = clock();
	    cout<<"min heap:"<<endl;
            cout <<"Finish Time = "<< machines.at(a)<<endl;
	    
	    clock_t timeElapsed1 = endTime1 - startTime1;
	   double totalTime1 = timeElapsed1 / (double) CLOCKS_PER_SEC;	
	    cout<<"total time: " << totalTime1 <<endl;
	    
        }
    }
    
    for(int i = 0; i<numMachines; i++){
        cout<<"Machine " << i+1<< "= "<< machines.at(i)<<endl;
    }
	
    
    
    return 0;
}
