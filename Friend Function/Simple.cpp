#include <iostream>
using namespace std;

// Forward declaration
class classB;

class classA {
private:
    int numA;

public:
    classA() : numA(12) {}

    // Declare friend function
    friend int addclasses(classA, classB);
};

class classB {
private:
    int numB;

public:
    classB() : numB(1) {}

    // Declare friend function
    friend int addclasses(classA, classB);
};

// Friend function to add private members of classA and classB
int addclasses(classA objA, classB objB) {
    return objA.numA + objB.numB;
}

int main() {
    classA objA;
    classB objB;
    cout << "Sum: " << addclasses(objA, objB) << endl;
    return 0;
}
