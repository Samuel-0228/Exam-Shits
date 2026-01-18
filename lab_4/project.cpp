#include <iostream>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_COURSES = 10;
const int MAX_ENROLL = 100;

class Student
{
public:
    string id;
    string name;
    string department;
    int age;
    string phonenumber;

    void inputStudent()
    {
        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter department: ";
        getline(cin, department);

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        cout << "Phone number: ";
        getline(cin, phonenumber);
    }

    void displayStudent()
    {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Dept: " << department
             << ", Age: " << age
             << ", Phone: " << phonenumber << endl;
    }
};

class Course
{
public:
    string courseCode;
    string courseName;
    int creditHours;

    void inputCourse()
    {
        cout << "Enter course code: ";
        cin >> courseCode;
        cin.ignore();

        cout << "Enter course name: ";
        getline(cin, courseName);

        cout << "Enter credit hours: ";
        cin >> creditHours;
        cin.ignore();
    }

    void displayCourse()
    {
        cout << "Code: " << courseCode
             << ", Name: " << courseName
             << ", Credit hours: " << creditHours << endl;
    }
};

class Enrollment
{
public:
    string studentId;
    string courseCode;
};

// global arrays
Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
Enrollment enrollments[MAX_ENROLL];

int studentCount = 0;
int courseCount = 0;
int enrollCount = 0;

// search helpers
int findStudentIndexById(string id)
{
    for (int i = 0; i < studentCount; i++)
        if (students[i].id == id)
            return i;
    return -1;
}

int findCourseIndexByCode(string code)
{
    for (int i = 0; i < courseCount; i++)
        if (courses[i].courseCode == code)
            return i;
    return -1;
}

// student functions
void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        cout << "Student list full!\n";
        return;
    }
    cout << "\n--- Add Student ---\n";
    students[studentCount].inputStudent();
    studentCount++;
    cout << "Student added successfully.\n";
}

void listStudents()
{
    cout << "\n--- All Students ---\n";
    if (studentCount == 0)
    {
        cout << "No students.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++)
        students[i].displayStudent();
}

void searchStudent()
{
    string id;
    cout << "Enter student ID to search: ";
    cin >> id;
    int idx = findStudentIndexById(id);
    if (idx == -1)
        cout << "Student not found.\n";
    else
        students[idx].displayStudent();
}

void addCourse()
{
    if (courseCount >= MAX_COURSES)
    {
        cout << "Course list full!\n";
        return;
    }
    cout << "\n--- Add Course ---\n";
    courses[courseCount].inputCourse();
    courseCount++;
}

void listCourses()
{
    cout << "\n--- All Courses ---\n";
    if (courseCount == 0)
    {
        cout << "No courses.\n";
        return;
    }
    for (int i = 0; i < courseCount; i++)
        courses[i].displayCourse();
}

void enrollStudentInCourse()
{
    if (enrollCount >= MAX_ENROLL)
    {
        cout << "Enrollment list full!\n";
        return;
    }

    string sid, ccode;
    cout << "Enter student ID: ";
    cin >> sid;
    cout << "Enter course code: ";
    cin >> ccode;

    int sIdx = findStudentIndexById(sid);
    int cIdx = findCourseIndexByCode(ccode);

    if (sIdx == -1)
    {
        cout << "Student not found.\n";
        return;
    }
    if (cIdx == -1)
    {
        cout << "Course not found.\n";
        return;
    }

    enrollments[enrollCount].studentId = sid;
    enrollments[enrollCount].courseCode = ccode;
    enrollCount++;

    cout << "Enrollment successful.\n";
}

void listEnrollments()
{
    cout << "\n--- All Enrollments ---\n";
    if (enrollCount == 0)
    {
        cout << "No enrollments.\n";
        return;
    }
    for (int i = 0; i < enrollCount; i++)
    {
        cout << "Student ID: " << enrollments[i].studentId
             << " enroll Course: " << enrollments[i].courseCode << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. List Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Add Course\n";
        cout << "5. List Courses\n";
        cout << "6. Enroll Student in Course\n";
        cout << "7. List Enrollments\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            listStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            addCourse();
            break;
        case 5:
            listCourses();
            break;
        case 6:
            enrollStudentInCourse();
            break;
        case 7:
            listEnrollments();
            break;
        case 0:
            cout << "Goodbye.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
