#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

// Class to store and display student details
class Student {
private:
    string name;      // Student's name
    string address;   // Student's address
    int rollNumber;   // Roll number
    int zipCode;      // Zip code

public:
    // Constructor
    Student();

    // Destructor
    ~Student();

    // Member function to read student details
    void readDetails();

    // Member function to display student details
    void displayDetails() const;

    // Getter functions for encapsulation
    string getName() const;
    int getRollNumber() const;
    int getZipCode() const;

    // Function to validate roll number
    static bool validateRollNumber(int rollNumber);

    // Function to validate zip code
    static bool validateZipCode(int zipCode);

    // Function to save student details to a file
    void saveToFile(ofstream &outFile) const;

    // Function to load student details from a file
    static Student loadFromFile(ifstream &inFile);
};

// Constructor implementation
Student::Student() : name(""), address(""), rollNumber(0), zipCode(0) {
    cout << "Student object created. Ready to store details." << endl;
}

// Destructor implementation
Student::~Student() {
    cout << "Student object destroyed. Resources released." << endl;
}

// Member function to read details
void Student::readDetails() {
    cout << "\nEnter the name of the student: ";
    getline(cin, name); // Use getline for names with spaces

    cout << "Enter the roll number of the student: ";
    while (true) {
        cin >> rollNumber;
        if (validateRollNumber(rollNumber)) break;
        else cout << "Invalid roll number. Please enter a valid roll number: ";
    }
    cin.ignore(); // Clear the input buffer for subsequent getline calls

    cout << "Enter the address of the student: ";
    getline(cin, address);

    cout << "Enter the zip code: ";
    while (true) {
        cin >> zipCode;
        if (validateZipCode(zipCode)) break;
        else cout << "Invalid zip code. Please enter a valid zip code: ";
    }
    cin.ignore(); // Clear the input buffer again
}

// Member function to display details
void Student::displayDetails() const {
    cout << "\n\n--- Student Details ---\n";
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Address: " << address << endl;
    cout << "Zip Code: " << zipCode << endl;
}

// Getter functions
string Student::getName() const { return name; }
int Student::getRollNumber() const { return rollNumber; }
int Student::getZipCode() const { return zipCode; }

// Validate roll number: For simplicity, it checks if roll number is positive
bool Student::validateRollNumber(int rollNumber) {
    if (rollNumber <= 0) {
        cout << "Roll number must be a positive integer.\n";
        return false;
    }
    return true;
}

// Validate zip code: Checks if it's a 5-digit number
bool Student::validateZipCode(int zipCode) {
    if (zipCode < 10000 || zipCode > 99999) {
        cout << "Zip code must be a 5-digit number.\n";
        return false;
    }
    return true;
}

// Save student details to file
void Student::saveToFile(ofstream &outFile) const {
    outFile << name << endl;
    outFile << rollNumber << endl;
    outFile << address << endl;
    outFile << zipCode << endl;
}

// Load student details from file
Student Student::loadFromFile(ifstream &inFile) {
    Student student;
    getline(inFile, student.name);
    inFile >> student.rollNumber;
    inFile.ignore(); // To consume the newline character
    getline(inFile, student.address);
    inFile >> student.zipCode;
    inFile.ignore(); // To consume the newline character
    return student;
}

// Function to save a list of students to a file
void saveStudentListToFile(const vector<Student> &students) {
    ofstream outFile("students.txt", ios::out | ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving!" << endl;
        return;
    }
    for (const auto &student : students) {
        student.saveToFile(outFile);
    }
    outFile.close();
}

// Function to load a list of students from a file
vector<Student> loadStudentListFromFile() {
    vector<Student> students;
    ifstream inFile("students.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for loading!" << endl;
        return students;
    }
    while (inFile) {
        students.push_back(Student::loadFromFile(inFile));
    }
    inFile.close();
    return students;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Save Students to File";
        cout << "\n4. Load Students from File";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume newline character after integer input

        switch (choice) {
        case 1: {
            Student student;
            student.readDetails();
            students.push_back(student);
            break;
        }
        case 2: {
            if (students.empty()) {
                cout << "No students to display." << endl;
            } else {
                for (const auto &student : students) {
                    student.displayDetails();
                }
            }
            break;
        }
        case 3: {
            saveStudentListToFile(students);
            cout << "Students saved to file." << endl;
            break;
        }
        case 4: {
            students = loadStudentListFromFile();
            cout << "Students loaded from file." << endl;
            break;
        }
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
