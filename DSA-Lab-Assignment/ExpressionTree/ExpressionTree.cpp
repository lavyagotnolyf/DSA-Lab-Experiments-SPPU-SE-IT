/*
============================================================================
 Name : Construct an Expression Tree.
 Programmer : Lavya Jain
 Description : DSA Lab Assignment No. 4
============================================================================
*/
/*PROBLEM STATEMENT-:
Construct an Expression Tree from postfix and prefix expression. Perform
recursive and non- recursive In-order, pre-order and post-order traversals.*/

#include <iostream>
#include <cctype> // For isalpha function
#include <cstring>
using namespace std;

#define SIZE 50

struct BTNODE {
    BTNODE* lc;
    char data;
    BTNODE* rc;
};
class STACK {
    int top;
    BTNODE* stk[SIZE];
public:
    STACK() : top(-1) {}
    void push(BTNODE* temp);
    BTNODE* pop(void);
    BTNODE* tope(void);
    friend class BT;
};

void STACK::push(BTNODE* temp) {
    stk[++top] = temp;
}

BTNODE* STACK::pop(void) {
    return stk[top--];
}
BTNODE* STACK::tope(void) {
    return stk[top];
}

class Expression {
    char exp[50];
public:
    int len;
    Expression() : len(0) {}
    void accept(void);
    void display(void);
    friend class BT;
};

void Expression::accept(void) {
    cout << "Enter Expression: ";
    cin >> exp;
    len = strlen(exp); // Set the length of the expression
}

void Expression::display(void) {
    cout << "Expression is: " << exp << endl;
}

class BT {
    BTNODE* root;
public:
    BT() : root(nullptr) {}
    void createexptree(Expression &E);
    void preorder(BTNODE* node);
    void inorder(BTNODE* node);
    void postorder(BTNODE* node);
    void preordernonrec(void);
    void inordernonrec(void);
    void postordernonrec(void);
    void traverse(void);
    void traversenonrec(void);
};

void BT::createexptree(Expression &E) {
    STACK s;
    BTNODE* newnp;
    for (int i = 0; i < E.len; i++) {
        newnp = new BTNODE;
        newnp->data = E.exp[i];
        newnp->lc = newnp->rc = nullptr;

        if (isalpha(E.exp[i])) { // Operand
            s.push(newnp);
        } else { // Operator
            newnp->rc = s.pop();
            newnp->lc = s.pop();
            s.push(newnp);
        }
    }
    root = s.pop();
}

void BT::preorder(BTNODE* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->lc);
        preorder(node->rc);
    }
}

void BT::inorder(BTNODE* node) {
    if (node) {
        inorder(node->lc);
        cout << node->data << " ";
        inorder(node->rc);
    }
}

void BT::postorder(BTNODE* node) {
    if (node) {
        postorder(node->lc);
        postorder(node->rc);
        cout << node->data << " ";
    }
}
void BT::preordernonrec(void)
{
    BTNODE*temp;temp=root;
    STACK s;
    s.push(NULL);
    while(temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->rc!=NULL)
            {s.push(temp->rc);}
            temp=temp->lc;
        }
        temp=s.pop();
    }
}
void BT::inordernonrec(void)
{
    BTNODE*temp;
    temp=root;STACK s;
    s.push(NULL);
    while(temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->lc;
        }
        temp=s.pop();
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->rc!=NULL)
            {
                temp=temp->rc;
                break;
            }
            else{
                temp=s.pop();
            }
        }
    }
}
void BT::postordernonrec(void)
{
    BTNODE*temp;
    temp=root;
    STACK s;
    int flag[50];
    flag[s.top]=0;
    s.push(NULL);
    while(temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            flag[s.top]=1;
            if(temp->rc!=NULL)
            {s.push(temp->rc);
            flag[s.top]=-1;}
            temp=temp->lc;
        }
        while(flag[s.top]==1)
        {
            temp=s.pop();
            cout<<temp->data;
        }
        temp=s.pop();
    }
}
void BT::traverse(void) {
    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << endl;
    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;
}
void BT::traversenonrec(void)
{
    cout << "Pre-order Traversal (Non-Recursive): ";
    preordernonrec();
    cout << endl;
    cout << "In-order Traversal (Non-Recursive): ";
    inordernonrec();
    cout << endl;
   cout << "Post-order Traversal (Non-Recursive): ";
    postordernonrec();
    cout << endl;
}

int main() {
    Expression E;
    E.accept();
    BT T;
    int choice;

    do{
        cout<<"\n-----------Menu------------";
        cout<<"\n1.Recursive traverse\n2.Non Recursive\n3.Exit";
        cout<<"\nWhat operation would you like to perform?:";
        cin>>choice;
       switch(choice)
       {
           case 1:
           {
            T.createexptree(E);
            T.traverse();
            break;
           }
           case 2:
           {
            T.createexptree(E);
            T.traversenonrec();
            break;
           }
           case 3:
           {
            cout<<"\n \t OPERATION COMPLETED!! THANK YOU (: \t \n";
            break;
           }
           default:
           {
            cout<<"Invalid choice.Please try again.";
            break;
           }
       }
    }while(choice!=3);
    return 0;
}

/*Output-:
Enter Expression: AB+C*

-----------Menu------------
1.Recursive traverse
2.Non Recursive
3.Exit
What operation would you like to perform?:1
Pre-order Traversal: * + A B C 
In-order Traversal: A + B * C 
Post-order Traversal: A B + C * 

-----------Menu------------
1.Recursive traverse
2.Non Recursive
3.Exit
What operation would you like to perform?:2
Pre-order Traversal (Non-Recursive): *+ABC
In-order Traversal (Non-Recursive): A+B*C
Post-order Traversal (Non-Recursive): AB+C*

-----------Menu------------
1.Recursive traverse
2.Non Recursive
3.Exit
What operation would you like to perform?:3

         OPERATION COMPLETED!! THANK YOU (:
*/

