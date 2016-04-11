#ifndef main_minminHeap_h
#define main_minminHeap_h

#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class minHeap {
private:
    vector<int> queue;
    void reorderDel(int index);
    int left(int parentNode){
        int i = ( parentNode * 2 ) + 1; 
	if(i < queue.size()){
	    return i;        
	}
	else{
	    return -1;	
	}
    
    }
    int right(int parentNode){
        int i = ( parentNode * 2 ) + 2; 
	if(i < queue.size()){
	    return i;        
	}
	else{
	    return -1;	
	}
    }
    
    int parentNode(int child){
        if (child != 0){
            int i = floor((child - 1)/2);
            return i;
        }
        else{
            return -1;
        }
    }
public:
    minHeap();
    ~minHeap();
    void push(int element);
    void pop();
    int top();
    int size();
};

minHeap::minHeap(){
}

minHeap::~minHeap(){
}

int minHeap::size(){
 return queue.size(); 
}

int minHeap::top(){
    return queue.front();
}

void minHeap::push(int element){
    queue.push_back(element);
    int index = queue.size() - 1;
     while ((queue[parentNode(index)] > queue[index])&&( index > 0 )&&( parentNode(index) >= 0 )){
        int temp = queue[parentNode(index)];
        queue[parentNode(index)] = queue[index];
        queue[index] = temp;
        index = parentNode(index);
    }
}

void minHeap::pop(){
    int index = 0;
    queue[0] = queue.at(queue.size() - 1);
    queue.pop_back();
    reorderDel(index);
    
}


void minHeap::reorderDel(int index){

    int leftChild = left(index);
    int rightChild = right(index);
    if ( leftChild > 0  && rightChild > 0  &&  queue[leftChild] > queue[rightChild] ){
        leftChild = rightChild;
    }
    if ( leftChild > 0 ){
        int temp = queue[index];
        queue[index] = queue[leftChild];
        queue[leftChild] = temp;
        reorderDel(leftChild);
    }

	
}





#endif
