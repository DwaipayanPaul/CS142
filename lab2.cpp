#include<iostream>

using namespace std;

class node{
	public:
		
	       //Data
	int data;
	     //Pointer to the next Node
	node * next;
	                     // constructor the makes the ptr to null
	node(){
		next=NULL;
	}
};
class linkedlist{
	
	public:
	//Head-> Circle(node) type ptr
	node* head;
	node* tail;
	//construct
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	    //Circles inside linked with each other
	
	   //insert
	void insert(int value){
		//if first node is added
		node * temp=new node;
		temp->data=value;//using here
		//1st node only
		if (head==NULL){
			head=temp;
		}
		//any other temp only
		else{
		
			tail->next=temp;
	
		}
		tail = temp;
		
		
	}
	void insertAT(int pos,int value){
		//reach the place before pos
		node* current=head;
	if(pos!=1){
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create a node
		node * temp= new node;
		temp->data=value;
		//moving ptrs
		temp->next=current->next;
		current->next=temp;
		//update the code for 1ast position
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;//assign value
		//link it to the value of head
		temp->next=current;
		//make temp head;
		head=temp;	
	}
		
	}
	//deletion of last element
	void delet(){
		//store the tail in temp
		node * temp = tail;
		// before tail has to point to null
		node * current=head;
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=NULL;
		//update tail
		tail=current;
		delete temp;
	}
	//delete at a given position
		void deletAt(int pos){
			//take one node at the desired position-1
			node *current=head;
				int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			// crate pointer for the file to be deleted
			node * temp=current->next;
			//assign link of the previous element to the next of next element
			current->next=temp->next;
			//deletion
			delete temp;
			
			
		
	}
	//display
	void display(){
		node * current=head;
		while(current !=NULL){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<"Null"<<endl;;
		
		
		
	}
	void countItems(){
		node * current=head;
		int j=0;
		while(current !=NULL){	
			current =current->next;	
			j++;
		}
		cout<<"The number of elements in the linked list is-"<<j<<endl;
	}
};
int main(){
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.countItems();
	l1.insert(9);
	l1.insertAT(2,8);
	l1.display();
	l1.delet();
	l1.display();
	cout<<endl;
	l1.deletAt(2);
	l1.display();
	return 0;
}