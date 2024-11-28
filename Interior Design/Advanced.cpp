#include <iostream>
#include <string>
using namespace std;

// Class to represent a color for the wall
class WallColor {
private:
    string color; // Color of the wall

public:
    // Constructor to initialize the color
    WallColor(const string& col) : color(col) {}

    // Function to display the color of the wall
    void displayColor() const {
        cout << "Color: " << color << endl;
    }
};

// Class to represent a Wall with dimensions and color
class Wall {
private:
    double length;  // Length of the wall
    double height;  // Height of the wall
    WallColor color;  // Color of the wall

public:
    // Parameterized constructor to initialize wall dimensions and color
    Wall(double len, double hgt, const string& col) : length(len), height(hgt), color(col) {
        if (len <= 0 || hgt <= 0) {
            cout << "Error: Length and height must be positive values." << endl;
            length = 0;
            height = 0;
        }
    }

    // Function to calculate the area of the wall
    double calculateArea() const {
        return length * height;
    }

    // Function to calculate the volume of paint needed (assuming 1 unit of thickness)
    double calculateVolume(double thickness = 1.0) const {
        return length * height * thickness;  // Volume = Area * Thickness
    }

    // Function to display wall details using an overloaded << operator
    friend ostream& operator<<(ostream& os, const Wall& wall) {
        os << "Wall Dimensions: " << "Length = " << wall.length << ", Height = " << wall.height << endl;
        os << "Wall Color: ";
        wall.color.displayColor();
        os << "Area: " << wall.calculateArea() << " square units" << endl;
        return os;
    }
};

int main() {
    // Create wall objects with given dimensions and color
    Wall wall1(10.5, 8.6, "Red");
    Wall wall2(8.5, 6.3, "Blue");

    // Display wall information
    cout << "Wall 1 Details: " << endl;
    cout << wall1 << endl;

    cout << "\nWall 2 Details: " << endl;
    cout << wall2 << endl;

    // Calculate and display volume of paint needed (with default thickness of 1 unit)
    double thickness = 0.05; // Thickness of paint in meters
    cout << "Paint Volume for Wall 1 (thickness " << thickness << "): " << wall1.calculateVolume(thickness) << " cubic units" << endl;
    cout << "Paint Volume for Wall 2 (thickness " << thickness << "): " << wall2.calculateVolume(thickness) << " cubic units" << endl;

    return 0;
}
