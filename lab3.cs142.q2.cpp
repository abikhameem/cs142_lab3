// circular linked list
//LOAD THE LIBRARY
#include<iostream>
//using namespace
using namespace std;
class Node
{public:
		int data;
        //pointer to move to next node
		Node *next;
        //constructor to initialize next pointer to NULL;
		Node()
		{next = NULL;}
};
class CircularLL
{public:
		//head pointer to point to first node
		Node *head;
		//tail pointer to point to node just before head
		Node *tail;
     //constructor
		CircularLL()
		{head = NULL;
         tail = NULL;
		}
    //inserts node at the end of the linked list
		void insert(int value)
		{//create new node
         Node *temp = new Node;
        //sets value as data for temp
        temp->data = value;
        //condition
        if(head == NULL)
			{head = temp;}
        else
			{temp->next = head;
            tail->next = temp;}
            tail = temp;
			cout<<endl;}
           //deletes node from the end
		void deletion()
		{//set temp to delete
			Node *temp = tail;
           //node just before temp should point to head
			Node *current = head;
			while(current->next != tail)
			{current = current->next;}                                     /
			current->next = head;
			tail = current;
           //delete temp
			delete temp;}
//inserts nodes at a given position
		void insertAt(int pos, int value)
		{int count = 1;
        //move current pointer till node just before last node
			Node *current = head;
			while(current != tail)
			{count++;
            current = current->next;}
            if(pos>count+1)
			{cout<<endl;
            cout<<"Linked List does not have that many elements\n";}
            else
			{//to add node at first
				if(pos == 1)
				{//create new node
                Node *temp = new Node;
                //set data of new node
                temp->data = value;
                // tail pointer to point to new node
                tail->next = temp;
                //linking to head
                temp->next = head;
                //update head
                head = temp;}
                else
				{// new node
                Node *temp = new Node;
                //data of the node as value
                temp->data = value;
                //move current pointer upto node just before position
                Node *current = head;
                int i = 1;
                while(i<pos-1){i++;
						current = current->next;}
					temp->next = current->next;
					current->next = temp;
				}
			 }
		  }
//deletes node at a position
		void deletionAt(int pos)
		{if(pos == 1)
			{//create temp pointer and initialize it with head
            Node *temp = head;
            // tail pointer to point to node next to head
            tail->next = head->next;
            head = head->next;
            //delete temp
            delete temp;
			}
            else
			{// current pointer upto node just before position
            Node *current = head;
            int i = 1;
            while(i<pos-1){i++;
					current = current->next;}
            //create new node and set it as the node to be deleted
            Node *temp = new Node;
            temp = current->next;
            current->next = temp->next;
            //delete temp
            delete temp;}
		}
//returns the number of nodes
		int countItems()
		{// counter variable to store number of nodes
			int count = 0;
			// current pointer and move it to last node and  increment count
			Node *current = head;
			while(current->next != head)
			{count++;
            current = current->next;}
            //returns count
			return count+1;}
			//displays the contents of the linked list
		void display()
		{// current pointer and initialize it as node next to head
        Node *current = head->next;
        // content of first node
        cout<<head->data<<"->";
        //move current pointer upto last node and display the contents of each node
        while(current != head)
			{cout<<current->data<<"->";
            current = current->next;}
            cout<<"NULL";
			cout<<endl;}
};
//main function
int main()
{CircularLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.display();
	l1.deletion();
	l1.display();
	l1.insertAt(3,14);
	l1.display();
	l1.deletionAt(4);
	l1.display();
	l1.insertAt(1,25);
	l1.display();
	l1.deletionAt(2);
	l1.display();
	cout<<"Number of nodes are "<<l1.countItems()<<endl;
    l1.insertAt(10,57);
	l1.display();
//closing program
	return 0;
}
