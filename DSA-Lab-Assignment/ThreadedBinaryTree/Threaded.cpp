/*
============================================================================
 Name : Construct an Expression Tree.
 Programmer : Lavya Jain
 Description : DSA Lab Assignment No. 4
============================================================================
*/
/*PROBLEM STATEMENT-:
Implement Heap sort to sort given set of values using max or min heap.*/

#include <iostream>
using namespace std;

struct Node{
Node *lc;
int lt;
int data;
int rt;
Node *rc;
};

class Threaded
{
private:
Node * head;

public:
Threaded(void){
head=new Node;
head->lc=head->rc=head;
head->data=32767;
head->lt=1;
head->rt=0;
}
void CreateTree(void);
void InorderTree(void);
};

void Threaded::CreateTree(void)
{
Node *temp,*newp;
temp=head;
int i,n;
cout << "How many nodes to be inserted:";
cin >> n;

for(i=0;i<n;++i)
{
newp=new Node;
cout << "Enter data of node:";
cin >> newp->data;

while(1)
{
if(newp->data < temp->data)
{
if(temp->lt==1)
{
newp->lc=temp->lc;
newp->lt=newp->rt=1;
newp->rc=temp;
temp->lc=newp;
temp->lt=0;
break;
}
else
temp=temp->lc;
}

if(temp->rt==1)
{
newp->rc=temp->rc;
newp->lt=newp->rt=1;
newp->lc=temp;
temp->rc=newp;
temp->rt=0;
break;
}
else
temp=temp->rc;
}
}
}//end of fucntion

Node *successor(Node * temp)
{
if(temp->rt==1)
return (temp->rc);

else{
temp=temp->rc;
while(temp->lt != 1){
temp=temp->lc;
}
return(temp);
}//end of else
}

void Threaded::InorderTree(void)
{
Node *temp;
temp=head;
do{
temp=successor(temp);

if(temp==head)
break;

else
cout << temp->data << endl;
}while(true);
}//end of function

int main()
{
Threaded Tree;
Tree.CreateTree();
Tree.InorderTree();
}
