/*PROBLEM STATEMENT-:
Consider a student database of SEIT class (at least 15 records). Database contains different
Fields of every student like Roll No, Name and SGPA.(array of structure)
a. Design a roll call list, arrange list of students according to roll numbers in ascending
order (Use Bubble Sort)
b. Arrange list of students alphabetically. (Use Insertion sort)
c. Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d. Search students according to SGPA. If more than one student having same SGPA,
then print list of all students having same SGPA.
e. Search a particular student according to name using binary search without recursion.
(all the student records having the presence of search key should be displayed)*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

//Structure for Student Database
struct Student
{
    public:
    unsigned int roll_no;
    string name;
    float sgpa;
};

class Student_data_base
{
    vector<Student>S;
    int n;
    public:
    void accept_details()
    {
        cout << "Enter Number of students:";
        cin >> n;
        S.resize(n);
        for(int i=0;i<n;++i)
        {
            cout << "Enter name of the student:" << "";
            cin >> S[i].name;
            cout << "Enter Roll Number of the student:" << "";
            cin >> S[i].roll_no;
            cout << "Enter SGPA of the student:" << "";
            cin >> S[i].sgpa;
        }
    }
    void display()
    {
        cout << "Serial Number" << setw(15) << "Name" << setw(15) << "Roll Number" << setw(15) << "SGPA" << endl;
        for (int i=0;i<n;++i)
        {
            cout << i+1 << "." << setw(15);
            cout << setw(15) << S[i].name;
            cout << setw(15) << S[i].roll_no;
            cout << setw(15) << S[i].sgpa << endl;
        }
    }
    void roll_call_list()
    {
        for(int i=0;i<=n-2;++i)
        {
            for(int j=0;j<=n-i-2;++j)
            {
                if(S[j].roll_no>S[j+1].roll_no)
                {
                    Student temp=S[j];
                    S[j]=S[j+1];
                    S[j+1]=temp;
                }
            }
        }
        display();
    }
    void alpha_order()
    {

        for(int i=0;i<=n-2;++i)
        {
            for(int j=0;j<=n-i-2;++j)
            {
                if(S[j].name>S[j+1].name)
                {
                    Student temp=S[j];
                    S[j]=S[j+1];
                    S[j+1]=temp;
                }
            }
        }
        display();
    }
    void toppers()
    {
        int i,j;
        for(i=0;i<n-2;++i)
        {
            for(j=0;j<n-i-2;++j)
            {
                if(S[j].sgpa>S[j+1].sgpa)
                {
                    Student temp=S[j];
                    S[j]=S[j+1];
                    S[j+1]=temp;
                }
            }
        }
        cout << "Serial Number" << setw(15) << "Name" << setw(15) << "Roll Number" << setw(15) << "SGPA" << endl;
        for(int k=0;k<10;++k)
        {
            cout << i+1 << "." << setw(15);
            cout << setw(15) << S[i].name;
            cout << setw(15) << S[i].roll_no;
            cout << setw(15) << S[i].sgpa << endl;
        }

    }
    void search_sgpa(float target)
    {
        float temp=target;
        int i;
        int flag=0;
        for(i=0;i<n;++i)
        {
            if(S[i].sgpa==temp)
            {
                flag=1;
                cout << i+1 << "." << setw(15);
                cout << setw(15) << S[i].name;
                cout << setw(15) << S[i].roll_no;
                cout << setw(15) << S[i].sgpa << endl;   
            }
            else 
            {
                ;
            }
        }
        if(flag==0)
        {
            cout << "No Student Found with SGPA" << target << ".";
        }    
    }
    void search_by_name(string target)
    {

        string temp=target;
        int i;
        int flag=0;
        for(i=0;i<n;++i)
        {
            if(S[i].name==temp)
            {
                flag=1;
                cout << i+1 << "." << setw(15);
                cout << setw(15) << S[i].name;
                cout << setw(15) << S[i].roll_no;
                cout << setw(15) << S[i].sgpa << endl;   
            }
            else 
            {
                ;
            }
        }
        if(flag==0)
        {
            cout << "No Student Found with this name" << target << ".";
        }    
    }  
};
/*===========================================main function=======================================*/

int main ()
{
    Student_data_base SDB;
    int n;
    SDB.accept_details();

    while(true)
    {
    cout << "1.Arrange list of students according to roll numbers." << endl;
    cout << "2.Arrange list of students alphabetically." << endl;
    cout << "3.Search students according to SGPA." << endl;
    cout << "4.Search a student by it's name." << endl;
    cout << "5.Arrange list of students to find out first ten toppers from a class."<< endl;
    cout << "Enter Your Purpose From The Above Choices:";
    cin >> n;

    if(n==1)
    {
        SDB.roll_call_list();
    }
    else if(n==2)
    {
        SDB.alpha_order();
    }
    else if (n==3)
    {
        float s;
        cout << "Enter SGPA you want to search:";
        cin >> s;
        SDB.search_sgpa(s);    
    }
    else if (n==4)
    {
        string s;
        cout << "Enter name you want to search:";
        cin >> s;
        SDB.search_by_name(s);    

    }
    else if (n==5)
    {
        SDB.toppers();
    }
   
    else
    {
        cout << "Invalid Choice.Please try again.";
    }
    }
    return 0;
}
