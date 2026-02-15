#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student {
private:
    string Name;
    int Age;

public:
    Student(string name, int age) {
        Name = name;
        Age = age;
    }

    void setName(string name) {
        Name = name;
    }

    void setAge(int age) {
        Age = age;
    }

    string getName() {
        return Name;
    }

    int getAge() {
        return Age;
    }

    void printStudentInfo() {
        cout << "Student " << Name << " Age " << Age << endl;
    }
};

int main() {
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch(selection) {
            case 0: {
                string name;
                int age;
                cout << "Student name ? ";
                cin >> name;
                cout << "Student age ? ";
                cin >> age;
                studentList.push_back(Student(name, age));
                break;
            }
            case 1: {
                for (int i = 0; i < studentList.size(); i++) {
                    studentList[i].printStudentInfo();
                }
                break;
            }
            case 2: {
                sort(studentList.begin(), studentList.end(),
                     [](Student a, Student b){ return a.getName() < b.getName(); });
                for (int i = 0; i < studentList.size(); i++) {
                    studentList[i].printStudentInfo();
                }
                break;
            }
            case 3: {
                sort(studentList.begin(), studentList.end(),
                     [](Student a, Student b){ return a.getAge() < b.getAge(); });
                for (int i = 0; i < studentList.size(); i++) {
                    studentList[i].printStudentInfo();
                }
                break;
            }
            case 4: {
                string name;
                cout << "Student to be found name = ? ";
                cin >> name;
                bool found = false;
                for (int i = 0; i < studentList.size(); i++) {
                    if (studentList[i].getName() == name) {
                        cout << "Student found: ";
                        studentList[i].printStudentInfo();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found." << endl;
                }
                break;
            }
            default:
                cout << "Wrong selection, stopping..." << endl;
                break;
        }

    } while (selection < 5);

    return 0;
}