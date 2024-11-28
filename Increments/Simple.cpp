#include <iostream>
using namespace std;

class Object {
private:
    long long int value; // Using long long int for large values

public:
    // Default constructor
    Object() : value(2157566666LL) {
        cout << "Default constructor called. Value initialized to " << value << endl;
    }

    // Parameterized constructor
    Object(long long int val) : value(val) {
        cout << "Parameterized constructor called. Value initialized to " << value << endl;
    }

    // Prefix increment operator overloading (++Obj)
    void operator++() {
        ++value;
        cout << "Prefix increment called. Value is now " << value << endl;
    }

    // Postfix increment operator overloading (Obj++)
    void operator++(int) {
        value++;
        cout << "Postfix increment called. Value is now " << value << endl;
    }

    // Display method
    void display() const {
        cout << "Object Value: " << value << endl;
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

    return 0;
}
