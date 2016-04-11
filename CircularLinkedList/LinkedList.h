#ifndef LIST_H
#define LIST_H

template <class T>
class LinkedList{
	private: 
		struct node{
			T data;
			
			node* next;

		};
		int size;
		bool isEmpty;

		typedef struct node* nodePtr;

		nodePtr head;
		nodePtr curr;
		nodePtr temp;

	public:
		LinkedList();
		~LinkedList();
		void DeleteNode(int k);
		void InsertNode(T addData, int k);
		void AddNode(T addData);
		void PrintList();
		void PrintNode(int k);
		int Size();
		void josephus(int k);



};


#endif