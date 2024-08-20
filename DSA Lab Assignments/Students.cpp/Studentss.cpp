#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for Student Database
struct Student
{
    unsigned int roll_no;
    string name;
    float sgpa;
};

class StudentDatabase
{
    vector<Student> students;

    public:
    void accept_details(int n)
    {
        students.resize(n);
        for(int i = 0; i < n; ++i)
        {
            cout << "Enter name of the student: ";
            cin >> students[i].name;
            cout << "Enter Roll Number of the student: ";
            cin >> students[i].roll_no;
            cout << "Enter SGPA of the student: ";
            cin >> students[i].sgpa;
        }
    }

    void display()
    {
        cout << "Serial Number" << setw(15) << "Name" << setw(15) << "Roll Number" << setw(15) << "SGPA" << endl;
        for (int i = 0; i < students.size(); ++i)
        {
            cout << i + 1 << "." << setw(15) << students[i].name 
                 << setw(15) << students[i].roll_no 
                 << setw(15) << students[i].sgpa << endl;
        }
    }

    void roll_call_list()
    {
        // Bubble Sort by roll number
        for(size_t i = 0; i < students.size() - 1; ++i)
        {
            for(size_t j = 0; j < students.size() - i - 1; ++j)
            {
                if(students[j].roll_no > students[j + 1].roll_no)
                {
                    swap(students[j], students[j + 1]);
                }
            }
        }
        display();
    }

    void alpha_order()
    {
        // Insertion Sort by name
        for(size_t i = 1; i < students.size(); ++i)
        {
            Student key = students[i];
            size_t j = i - 1;
            while(j >= 0 && students[j].name > key.name)
            {
                students[j + 1] = students[j];
                if(j == 0) break; // To avoid underflow
                --j;
            }
            students[j + 1] = key;
        }
        display();
    }

    void toppers()
    {
        // Quick Sort by SGPA
        quick_sort(0, students.size() - 1);
        cout << "Top 10 Toppers:" << endl;
        size_t count = min(students.size(), size_t(10));
        for(size_t i = 0; i < count; ++i)
        {
            cout << i + 1 << "." << setw(15) << students[i].name 
                 << setw(15) << students[i].roll_no 
                 << setw(15) << students[i].sgpa << endl;
        }
    }

    void search_sgpa(float target)
    {
        bool found = false;
        for(const auto& student : students)
        {
            if(student.sgpa == target)
            {
                if(!found) 
                {
                    cout << "Students with SGPA " << target << ":" << endl;
                    found = true;
                }
                cout << setw(15) << student.name 
                     << setw(15) << student.roll_no 
                     << setw(15) << student.sgpa << endl;
            }
        }
        if(!found)
        {
            cout << "No student found with SGPA " << target << "." << endl;
        }
    }

    void search_by_name(const string& name)
    {
        // Ensure the list is sorted by name
        alpha_order();
        size_t left = 0, right = students.size() - 1;
        bool found = false;

        while(left <= right)
        {
            size_t mid = left + (right - left) / 2;
            if(students[mid].name == name)
            {
                cout << "Students with name " << name << ":" << endl;
                found = true;
                // Search for all instances
                size_t i = mid;
                while(i < students.size() && students[i].name == name)
                {
                    cout << setw(15) << students[i].name 
                         << setw(15) << students[i].roll_no 
                         << setw(15) << students[i].sgpa << endl;
                    ++i;
                }
                i = mid - 1;
                while(i >= 0 && students[i].name == name)
                {
                    cout << setw(15) << students[i].name 
                         << setw(15) << students[i].roll_no 
                         << setw(15) << students[i].sgpa << endl;
                    if(i == 0) break;
                    --i;
                }
                break;
            }
            else if(students[mid].name < name)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if(!found)
        {
            cout << "No student found with name " << name << "." << endl;
        }
    }

    private:
    void quick_sort(size_t low, size_t high)
    {
        if(low < high)
        {
            size_t pi = partition(low, high);
            if (pi > 0) quick_sort(low, pi - 1);
            quick_sort(pi + 1, high);
        }
    }

    size_t partition(size_t low, size_t high)
    {
        float pivot = students[high].sgpa;
        size_t i = low;
        for(size_t j = low; j < high; ++j)
        {
            if(students[j].sgpa > pivot)
            {
                swap(students[i], students[j]);
                ++i;
            }
        }
        swap(students[i], students[high]);
        return i;
    }
};

int main()
{
    StudentDatabase SDB;
    int choice, n;

    cout << "Enter number of students: ";
    cin >> n;
    SDB.accept_details(n);

    while(true)
    {
        cout << "\n1. Arrange list of students according to roll numbers." << endl;
        cout << "2. Arrange list of students alphabetically." << endl;
        cout << "3. Search students according to SGPA." << endl;
        cout << "4. Search a student by its name." << endl;
        cout << "5. Arrange list of students to find out first ten toppers from a class." << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                SDB.roll_call_list();
                break;
            case 2:
                SDB.alpha_order();
                break;
            case 3:
                {
                    float sgpa;
                    cout << "Enter SGPA to search: ";
                    cin >> sgpa;
                    SDB.search_sgpa(sgpa);
                }
                break;
            case 4:
                {
                    string name;
                    cout << "Enter name to search: ";
                    cin >> name;
                    SDB.search_by_name(name);
                }
                break;
            case 5:
                SDB.toppers();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}