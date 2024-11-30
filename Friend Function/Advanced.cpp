#include <iostream>
using namespace std;

// Forward declaration of classB
class classB;

// classA definition
class classA {
private:
    int numA; // Private member of classA

public:
    // Constructor initializes numA
    classA() : numA(12) {}

    // Declare addclasses as a friend function
    friend int addclasses(classA, classB);
};

// classB definition
class classB {
private:
    int numB; // Private member of classB

public:
    // Constructor initializes numB
    classB() : numB(1) {}

    // Declare addclasses as a friend function
    friend int addclasses(classA, classB);
};

// Friend function definition
// Adds private members of classA and classB
int addclasses(classA objA, classB objB) {
    return objA.numA + objB.numB;
}

int main() {
    // Create objects of classA and classB
    classA objA;
    classB objB;

    // Output the sum of private members
    cout << "Sum: " << addclasses(objA, objB) << endl;

    return 0;
}
