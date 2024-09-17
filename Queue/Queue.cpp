/*
============================================================================
 Name : Implement Circular Queue using Array.
 Programmer : Lavya Jain
 Description : DSA Lab Assignment No. 3
============================================================================
*/
/*PROBLEM STATEMENT-:
Implement Circular Queue using Array.Perform following operations on it.
a) Insertion (Enqueue).
b) Deletion (Dequeue).
c) Display.*/

#include<iostream> 
using namespace std; 

struct Queue 
{ 
private: 
	int rear,front,size; 
public: 
	Queue(int n) 
	{ 
		size=n; 
		front=-1; 
		rear=-1; 
	} 
	void enqueue(int a[]); 
	void dequeue(int a[]); 
	void display(int a[]); 
};
void Queue::enqueue(int a[]) //INSERTION IN QUEUE 
{ 
	if((rear+1)%size == front) 
	{ 
		cout<<"\n QUEUE FULL!!\n"; 
	} 
	else 
	{ 
		int x; 
		cout<<"\n ENTER THE ELEMENT TO BE INSERTED: "; 
		cin>>x; 
		if(rear ==-1) 
		{ 
			front=0; 
			rear=0; 

		} 
		else 
		{ 
			rear=(rear+1)%size; 
		} 
		a[rear]=x; 
	} 
} 
void Queue::dequeue(int a[]) //DELETION FROM QUEUE
{ 
	if(rear == -1 && front == -1) 
	{ 
		cout<<"\n EMPTY QUEUE! (nothing to delete) \n "; 
		return; 
	} 
	else 
	{ 
		cout<<"Deleted element from queue is "<<a[front]<<"\n"; 
		if(rear == front) 
		{ 
			rear= -1; 
			front= -1; 
		} 
		else 
		{ 
			front=(front+1)%size; 
		} 
	} 
} 
void Queue::display(int a[]) //DISPLAY OF ELEMENTS 
{
	if(front == -1)
	{ 
		cout<<"\n QUEUE IS EMPTY! (nothing to show )) \n"; 
		return; 
	} 
	else 
	{ 
		int x=front; 
		while(x != rear) 
		{ 
			cout<<a[x]<<"\t"; 
			x=(x+1)%size; 
		} 
		cout<<a[rear]<<"\t"; 
	} 
} 
/*===================================main function===================================*/

int main()
{ 
	int n,ch; 
	cout<<"Enter the size of the array: "; 
	cin>>n; 
	int a[n]; 
	Queue s(n);

    do
    {
	cout<<" \n [1] INSERTION "; 
	cout<<" \n [2] DELETION "; 
	cout<<" \n [3] DISPLAY \n"; 

		cout<<" \n *****Enter your choice***** (want to exit? enter 0) \n"; 
		cin>>ch; 
		switch(ch) 
		{ 
			case 1: 
			{ 
				s.enqueue(a); 
				break; 
			} 
			case 2: 
			{ 
				s.dequeue(a); 
				break; 
			} 
			case 3: 
			{ 
				s.display(a); 
				break; 
			}
            default:
            {
            cout<<"\n \t OPERATION COMPLETED!! THANK YOU (: \t \n";
            break;
            }
		}
	} 
	while(ch>0 && ch<4); 
	return 0; 
}
/*Output-:
Enter the size of the array: 5
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 2
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 4
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 5
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 6
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 9
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
3
2       4       5       6       9        
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 QUEUE FULL!!
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
2
Deleted element from queue is 2
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
2
Deleted element from queue is 4
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
3
5       6       9        
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
0

         OPERATION COMPLETED!! THANK YOU (:
*/         

