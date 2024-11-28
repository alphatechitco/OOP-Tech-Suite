#include <iostream>
using namespace std;

// Class to represent a Wall and its dimensions
class Wall {
private:
    double length; // Length of the wall
    double height; // Height of the wall

public:
    // Parameterized constructor to initialize wall dimensions
    Wall(double len, double hgt) {
        if (len <= 0 || hgt <= 0) {
            cout << "Error: Length and height must be positive values." << endl;
            length = 0;
            height = 0;
        } else {
            length = len;
            height = hgt;
        }
    }

    // Function to calculate the area of the wall
    double calculateArea() const {
        return length * height;
    }

    // Function to display wall dimensions
    void displayDimensions() const {
        cout << "Length: " << length << " units, Height: " << height << " units" << endl;
    }
};

int main() {
    // Create wall objects with given dimensions
    Wall wall1(10.5, 8.6);
    Wall wall2(8.5, 6.3);

    // Display wall dimensions and areas
    cout << "Wall 1 dimensions: ";
    wall1.displayDimensions();
    cout << "Area of Wall 1: " << wall1.calculateArea() << " square units" << endl;

    cout << "\nWall 2 dimensions: ";
    wall2.displayDimensions();
    cout << "Area of Wall 2: " << wall2.calculateArea() << " square units" << endl;

    return 0;
}
