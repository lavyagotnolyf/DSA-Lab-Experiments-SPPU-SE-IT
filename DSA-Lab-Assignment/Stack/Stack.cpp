/*
============================================================================
 Name : Implement Stack as an Abstract Data Type using Singly Sinked List
 Programmer : Lavya Jain
 Description : DSA Lab Assignment No. 2
============================================================================
*/
/*PROBLEM STATEMENT-:
Implement stack as an abstract data type using singly linked list, use this ADT for
conversion of infix expression to postfix, prefix and evaluation of postfix, and
prefix expression.*/

#define SIZE 10
#include <iostream>
#include <cstring>
using namespace std;

class stack {
    float s[SIZE];
    int top;
public:
    stack(void) { top = -1; }
    int push(float item);
    float pop(void);
    float tope() const;
    bool isEmpty() const;
};

int stack::push(float item) {
    if (top >= SIZE - 1) {
        return -1;
    }
    top++;
    s[top] = item;
    return 0;
}

float stack::pop(void) {
    if (top < 0) {
        return -1;
    }
    return s[top--];
} 
float stack::tope() const {
    if (top < 0) {
        cout << ("Stack is empty") << endl;
    }
    return s[top];
}

bool stack::isEmpty() const {
    return top == -1;
}

class Expression {
private:
    char expr[50];
    int len;
public:
    Expression(void) { len = 0; }
    void acceptexpr(void) {
        cout<<"Enter Infix Expression:";
        cin >> expr;
        len = strlen(expr);
    }
    void dispexpr(void) { cout << "Infix Expression:" << expr << endl; }
    int ICP(char op) const; 
    int ISP(char op) const; 
    void infixtoprefix(char* prefix);
    void reverseString(char* str, int length);
    void infixtopostfix(char* postfix);
    float evalpostfix(const char* postfix);
    float eval_operator(float op1, float op2, char oper);
};
int Expression::ICP(char op) const {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

int Expression::ISP(char op) const {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '(': return 0; 
        default: return 0;
    }
}

void Expression::infixtopostfix(char* postfix) {
    stack s;
    int j = 0;
    s.push('#'); 

    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (isalpha(ch)) { 
            postfix[j++] = ch;
        } else if (ch == '(') { 
            s.push(ch);
        } else if (ch == ')') { 
            while (!s.isEmpty() && s.tope() != '(') {
                postfix[j++] = s.pop();
            }
            if (!s.isEmpty() && s.tope() == '(') {
                s.pop(); 
            }
        } else { 
            while (!s.isEmpty() && ISP(s.tope()) >= ICP(ch)) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty() && s.tope() != '#') {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
}
void Expression::reverseString(char* str, int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void Expression::infixtoprefix(char* prefix) {
    reverseString(expr, len);
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') {
            expr[i] = ')';
        } else if (expr[i] == ')') {
            expr[i] = '(';
        }
    }
    char postfix[50];
    infixtopostfix(postfix);
    reverseString(postfix, strlen(postfix));
    strcpy(prefix, postfix);
}
float Expression::eval_operator(float op1, float op2, char oper) {
    switch (oper) {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        default: return 0;
    }
}

float Expression::evalpostfix(const char* postfix) {
    stack s;
    int i;
    float val;
    for (i = 0; i <= len - 1; i++) {
        if (isalpha(postfix[i])) {
            cout<<"Enter value of" <<" "<<postfix[i] << " :";
            cin >>val;
            s.push(val);
        } else {
            float op2 = s.pop();
            float op1 = s.pop();
            float res = eval_operator(op1, op2, postfix[i]);
            s.push(res);
        }
    }
    return s.pop();
}

int main(void) {
    Expression e;
    e.acceptexpr();
    int choice=1;
    do{
    cout<<"\n-------------Menu-----------";
    cout<<"\n1.Infix Expression\n2.Infix to Postfix Expression\n3.Infix to Prefix Expression\n4. Evaluation of Postfix and Prefix Expression\n5.Exit";
    cout<<"\nWhat operation would you like to perform?:";
    cin>>choice;
    switch(choice){
        case 1:
         e.dispexpr();
         break;
        case 2:
         char postfix[50]; 
         e.infixtopostfix(postfix);
         cout << "\nPostfix Expression: " << postfix << endl;
         break;
        case 3:
         char prefix[50];
         e.infixtoprefix(prefix);
         cout << "Prefix Expression: " << prefix << endl;
         break;
        case 4:
         e.infixtoprefix(prefix);
         cout << "Result:\n " << e.evalpostfix(postfix) << endl;
         break;
         case 5:
          cout<<"\n \t OPERATION COMPLETED!! THANK YOU (: \t \n";
          break;
        default:
          cout<<"Invalid choice. Please try again.";
          break;
    }
    }while(choice!=5);
    return 0;
}
/*Output-:
Enter Infix Expression:A+B*C/D

-------------Menu-----------
1.Infix Expression
2.Infix to Postfix Expression
3.Infix to Prefix Expression
4. Evaluation of Postfix and Prefix Expression
5.Exit
What operation would you like to perform?:1
Infix Expression:A+B*C/D

-------------Menu-----------
1.Infix Expression
2.Infix to Postfix Expression
3.Infix to Prefix Expression
4. Evaluation of Postfix and Prefix Expression
5.Exit
What operation would you like to perform?:2

Postfix Expression: ABC*D/+

-------------Menu-----------
1.Infix Expression
2.Infix to Postfix Expression
3.Infix to Prefix Expression
4. Evaluation of Postfix and Prefix Expression
5.Exit
What operation would you like to perform?:3
Prefix Expression: +A*B/CD

-------------Menu-----------
1.Infix Expression
2.Infix to Postfix Expression
3.Infix to Prefix Expression
4. Evaluation of Postfix and Prefix Expression
5.Exit
What operation would you like to perform?:4
Result:
Enter value of A :4
Enter value of B :5
Enter value of C :3
Enter value of D :6
6.5

-------------Menu-----------
1.Infix Expression
2.Infix to Postfix Expression
3.Infix to Prefix Expression
4. Evaluation of Postfix and Prefix Expression
5.Exit
What operation would you like to perform?:5

         OPERATION COMPLETED!! THANK YOU (: 
*/
