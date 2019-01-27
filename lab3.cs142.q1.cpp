// doubly linked list
//loading library
#include<iostream>
//namespace
using namespace std;
class Box
{public:
    int data;
//pointers to move to next box and previous box
		Box *next;
		Box *prev;
//default constructor to set both pointers to NULL
		Box()
		{next = NULL;
		prev = NULL;
		 }
} ;
class DoubleLL
{//Head and circles (boxes) linked to one another
public:
//head and tail pointers for DoubleLL
		Box *head;
		Box *tail;
//constuctor
		DoubleLL()
		{head = NULL;
         tail = NULL;
		}
		//inserts new boxes to the DoubleLL at the end
		 void insert(int value)
		{//create new box
			Box *temp = new Box;
			//set value as data of new box
			 temp->data = value;
            //indicates first box being added
			 if(head == NULL)
			{head = temp;}
			else
			{//use tail ptr
             tail->next = temp;
             temp->prev = tail; }
             tail = temp;
			 cout<<endl;}
			 //deletes box present at the end
		 void deletion()
		{//creates temp ptr to store box at end
			Box *temp = tail;
			 //create another pointer to move forward till end but the last node
			 Node *current = head;
			 while(current->next != tail)
			{current = current->next;}
            //modify links to set current as tail and it points to NULL
			 current->next = NULL;
			 current = tail;
            //delete temp
			 delete temp;
			cout<<endl;}
        //inserts box at a specific position in the linked list
		 void insertAt(int pos,int value)
		{int count = 0;     //keeps count of number of boxes in the doubly linked list
			 Box *current = head;     //initializes current pointer with head
			 //move current pointer upto last box and increment count
			 while(current!=NULL)
			 {count++;
             current = current->next;
			 }
            if(pos>count)
			{cout<<endl;
             cout<<"Linked List does not have that many elements\n";
			 }
            else
			{//to add box at first position
				 if(pos == 1)
				{//create new box
					Box *temp = new box;
					//set value as data of the box
					 temp->data = value;
					 //modify links
					 temp->next = head;
					head->prev = temp;          /
					 //update head
					  head = temp;
				 }
                else
				{//set current pointer as head
                  Box*current = head;
                //current pointer goes upto node just before the position (set as parameter)
                int i=1;
                while(i<pos-1)
                {i++;
                current=current->next;}
                //new box is created
                Box *temp = new Box;
               //sets value as data of the box
                temp->data = value;
                //links re-established
					temp->next = current->next;
					current->next = temp;
					temp->next->prev = temp;
					temp->prev = current;
                    }
		     }
             cout<<endl;}
    //deletes boxes at a specific position in the linked list
		void deletionAt(int pos)
		{//extra condition for deleting first box
        if(pos==1)
			{//sets temp pointer as head
				Box *temp = head;
                //update head
				head = head->next;
				 //delete temp
				delete temp;
			}
			else
			{//set current pointer as head
				Box *current = head;
				//move current pointer upto position just before the box to be deleted
				int i=1;
				while(i<pos-1)
				{i++;
                current = current->next;
				}
				//set temp pointer as box to be deleted
				Box *temp = new Box;
                temp = current->next;
                //re-establish link
			        current->next = temp->next;
			        temp->next->prev = current;           /
                    //delete temp
			        delete temp;
		         }
		    cout<<endl;}
         //displays the contents of the linked list
		void display()
		{//set current pointer as head
			box *current = head;
			//keep moving current pointer and printing the contents
			while(current != NULL)
			{cout<<current->data<<"->";
            current = current->next;}
			cout<<"NULL";}
        //displays the number of boxes in the linked list
		void countItems()
		{//counter variable to keep count of number of boxes
			int count = 0;
        //sets current pointer as head
          Box *current = head;
			//move current pointer till last box and simultaneously increase count
			while(current != NULL)
			{count++;
            current = current->next;}
            cout<<"Number of elements: "<<count<<endl;}
};
//using main function
int main()
{
	DoubleLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.display();
	l1.deletion();
	l1.display();
	l1.insertAt(1,12);
	l1.display();
	l1.insertAt(3,36);
	l1.display();
        l1.deletionAt(1);
        l1.display();
        l1.deletionAt(4);
        l1.display();
        l1.insertAt(11,10);
        l1.countItems();
//closing program
	return 0;
}
