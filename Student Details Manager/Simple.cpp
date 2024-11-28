#include <iostream>
#include <string> // Use string for safer and more modern input handling
using namespace std;

// Class to store and display student details
class Student {
private:
    string name;  // Student's name
    string address; // Student's address
    int rollNumber; // Roll number
    int zipCode; // Zip code

public:
    // Constructor
    Student();
    
    // Destructor
    ~Student();
    
    // Member function to read student details
    void readDetails();
    
    // Member function to display student details
    void displayDetails() const;
};

// Constructor implementation
Student::Student() {
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
    cin >> rollNumber;
    cin.ignore(); // Clear the input buffer for subsequent getline calls

    cout << "Enter the address of the student: ";
    getline(cin, address);

    cout << "Enter the zip code: ";
    cin >> zipCode;
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

// Main function
int main() {
    // Create a student object
    Student student;

    // Read and display student details
    student.readDetails();
    student.displayDetails();

    return 0;
}
