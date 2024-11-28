#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Base class Animal
class Animal {
public:
    virtual void sound() {
        cout << "Animal creates sound\n";
    }

    virtual void behavior() {
        cout << "General animal behavior.\n";
    }

    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived class Cat
class Cat : public Animal {
public:
    void sound() override {
        cout << "Meows\n";
    }

    void behavior() override {
        cout << "The cat purrs and chases mice.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Barks\n";
    }

    void behavior() override {
        cout << "The dog wags its tail and guards the house.\n";
    }
};

// Derived class Wolf
class Wolf : public Animal {
public:
    void sound() override {
        cout << "Hooowls\n";
    }

    void behavior() override {
        cout << "The wolf hunts in packs.\n";
    }
};

// Derived class Lion
class Lion : public Animal {
public:
    void sound() override {
        cout << "Rooaars\n";
    }

    void behavior() override {
        cout << "The lion is the king of the jungle and leads the pride.\n";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<Animal*> animals;
    animals.push_back(new Animal());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Wolf());
    animals.push_back(new Lion());

    // Dynamic menu-driven program
    int choice;
    do {
        cout << "\nAnimal Sound Simulator:\n";
        cout << "1. Play all animal sounds\n";
        cout << "2. Play a random animal sound\n";
        cout << "3. View animal behaviors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nPlaying all animal sounds:\n";
                for (Animal* animal : animals) {
                    animal->sound();
                }
                break;
            }
            case 2: {
                int randomIndex = rand() % animals.size();
                cout << "\nRandom animal sound:\n";
                animals[randomIndex]->sound();
                break;
            }
            case 3: {
                cout << "\nAnimal behaviors:\n";
                for (Animal* animal : animals) {
                    animal->behavior();
                }
                break;
            }
            case 4:
                cout << "\nExiting program.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    // Cleanup memory
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
