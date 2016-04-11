

#ifndef main_leftistHeap_h
#define main_leftistHeap_h


#include <cstdlib>
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    int sVal;
    node(int & data, node *leftPTR = NULL, node *rightPTR = NULL, int np = 0){
        this->data = data;
        right = rightPTR;
        left = leftPTR,
        sVal =  np;
    }
};

class HBLT{
private:
    int size;
    node *root;
    node *meld(node *subT1, node *subT2);
    void destroyTree(node * t);
public:
    HBLT();
    ~HBLT();
    bool isEmpty();
    int getSize();
    void push(int data);    
    int top();
    void pop();
  
};



HBLT::HBLT(){
    root = NULL;
    size = 0;
}



HBLT::~HBLT(){
    destroyTree(root);
    root = NULL;
   
}

void HBLT::destroyTree(node * subtree){
    if (subtree != NULL){
        destroyTree(subtree->left);
        destroyTree(subtree->right);
        delete subtree;
    }
}


bool HBLT::isEmpty(){
    return root == NULL;
}

int HBLT::getSize(){
    return size;
}


node *HBLT::meld(node * subT1, node * subT2){
    if (subT1 == NULL){
        
	return subT2;
    }
    if (subT2 == NULL){
        
        return subT1;
    }

    if (subT1->data < subT2->data){

    if (subT1->left == NULL){
        subT1->left = subT2;
    }
    else{
        subT1->right = meld(subT1->right, subT2);
        if (subT1->left->sVal < subT1->right->sVal){
            
	    node* temp = subT1-> left;
	    subT1-> left = subT1 -> right;
            subT1-> right = temp;  	
	}
        subT1->sVal = subT1->right->sVal + 1;
    }
        return subT1;
    }


    else{
     

    if (subT2->left == NULL){
        subT2->left = subT1;
    }
    else{
        subT2->right = meld(subT2->right, subT1);
        if (subT2->left->sVal < subT2->right->sVal){
            
	    node* temp = subT2-> left;
	    subT2-> left = subT2 -> right;
            subT2-> right = temp;  	
	}
        subT2->sVal = subT2->right->sVal + 1;
    }
        return subT2;
    }
}



void HBLT::push(int data){
    node* insertNode = new node(data);
    root = meld(insertNode, root);
    size++;

}


int HBLT::top(){
    return root->data;
}


void HBLT::pop(){
    node *delRoot = root;
    root = meld(root->left, root->right);
    size--;
    delete delRoot;
}






#endif
