#include <iostream>
using namespace std;

class Object {
private:
    long long int* value; // Using pointer for dynamic memory allocation

public:
    // Default constructor
    Object() {
        value = new long long int(2157566666LL); // Dynamically allocate memory
        cout << "Default constructor called. Value initialized to " << *value << endl;
    }

    // Parameterized constructor
    Object(long long int val) {
        value = new long long int(val); // Dynamically allocate memory
        cout << "Parameterized constructor called. Value initialized to " << *value << endl;
    }

    // Copy constructor (deep copy)
    Object(const Object& other) {
        value = new long long int(*other.value); // Create a deep copy
        cout << "Copy constructor called. Value copied: " << *value << endl;
    }

    // Assignment operator (deep copy)
    Object& operator=(const Object& other) {
        if (this != &other) { // Check for self-assignment
            delete value; // Release old memory
            value = new long long int(*other.value); // Allocate new memory and copy the value
            cout << "Assignment operator called. Value copied: " << *value << endl;
        }
        return *this;
    }

    // Destructor
    ~Object() {
        delete value; // Release the dynamically allocated memory
        cout << "Destructor called. Memory released." << endl;
    }

    // Prefix increment operator overloading (++Obj)
    void operator++() {
        ++(*value);
        cout << "Prefix increment called. Value is now " << *value << endl;
    }

    // Postfix increment operator overloading (Obj++)
    void operator++(int) {
        (*value)++;
        cout << "Postfix increment called. Value is now " << *value << endl;
    }

    // Arithmetic operator overloading (addition)
    Object operator+(const Object& other) {
        return Object(*value + *other.value); // Return a new object with the sum of values
    }

    // Arithmetic operator overloading (subtraction)
    Object operator-(const Object& other) {
        return Object(*value - *other.value); // Return a new object with the difference of values
    }

    // Display method
    void display() const {
        cout << "Object Value: " << *value << endl;
    }

    // Getter for value
    long long int getValue() const {
        return *value;
    }

    // Setter for value
    void setValue(long long int val) {
        *value = val;
    }
};

int main() {
    // Default initialization
    Object Obj1;
    Obj1.display();

    // Prefix increment
    ++Obj1;
    Obj1.display();

    // Postfix increment
    Obj1++;
    Obj1.display();

    // Parameterized initialization
    Object Obj2(1000);
    Obj2.display();

    ++Obj2; // Prefix increment
    Obj2.display();

    Obj2++; // Postfix increment
    Obj2.display();

    // Arithmetic operations
    Object Obj3 = Obj1 + Obj2; // Add two objects
    Obj3.display();

    Object Obj4 = Obj1 - Obj2; // Subtract two objects
    Obj4.display();

    // Copy constructor and assignment operator
    Object Obj5 = Obj2; // Copy constructor
    Obj5.display();

    Object Obj6(500);
    Obj6 = Obj1; // Assignment operator
    Obj6.display();

    return 0;
}
