#include <iostream>
#include <string>
using namespace std;

// Ye base class hai jo common cheezen rakhti hai
class Person {
protected:
    string name;
    int age;

public:
    // Name aur age input lene ke liye
    void setData() {
        cout << "Enter Name: ";
        cin >> ws;              // extra space hatane ke liye
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
    }

    // Name aur age display karne ke liye
    void display() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// Student class jo Person se inherit karti hai
class Student : public Person {
private:
    int rollNo;
    float marks[5];     // 5 subjects ke marks

public:
    // Student ka pura data lene ke liye
    void setStudentData() {
        setData();     // Person ka function call

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter 5 Marks: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    // Average nikalne ka function
    float getAverage() const {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum / 5;
    }

    // Student ka data show karne ke liye
    void displayStudent() const {
        display();   // Person ka display
        cout << ", Roll No: " << rollNo << ", Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << ", Average: " << getAverage() << endl;
    }
};

// Teacher class bhi Person se inherit ho rahi hai
class Teacher : public Person {
private:
    string subject;
    float salary;

public:
    // Teacher ka data lene ke liye
    void setTeacherData() {
        setData();   // Name aur age

        cout << "Enter Subject: ";
        cin >> ws;
        getline(cin, subject);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Teacher ka data show karne ke liye
    void displayTeacher() const {
        display();
        cout << ", Subject: " << subject << ", Salary: " << salary << endl;
    }
};

// Saare students ko display karne ka function
void displayAllStudents(Student* s, int n) {
    for (int i = 0; i < n; i++) {
        s[i].displayStudent();
    }
}

// Saare teachers ko display karne ka function
void displayAllTeachers(Teacher* t, int n) {
    for (int i = 0; i < n; i++) {
        t[i].displayTeacher();
    }
}

// Top student find karne ka function
Student* topStudent(Student* s, int n) {
    int index = 0;
    float maxAvg = s[0].getAverage();

    for (int i = 1; i < n; i++) {
        if (s[i].getAverage() > maxAvg) {
            maxAvg = s[i].getAverage();
            index = i;
        }
    }
    return &s[index];
}

int main() {
    int numStudents, numTeachers;

    cout << "Enter number of students: ";
    cin >> numStudents;

    cout << "Enter number of teachers: ";
    cin >> numTeachers;

    // Dynamic memory use ki hai
    Student* students = new Student[numStudents];
    Teacher* teachers = new Teacher[numTeachers];

    cout << "\n_Enter Student Data_\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].setStudentData();
    }

    cout << "\n_Enter Teacher Data_\n";
    for (int i = 0; i < numTeachers; i++) {
        cout << "\nTeacher " << i + 1 << ":\n";
        teachers[i].setTeacherData();
    }

    cout << "\n_All Students_\n";
    displayAllStudents(students, numStudents);

    cout << "\n_All Teachers_\n";
    displayAllTeachers(teachers, numTeachers);

    cout << "\n_Top Student_\n";
    topStudent(students, numStudents)->displayStudent();

    // Memory free kar rahe hain
    delete[] students;
    delete[] teachers;

    return 0;
}
