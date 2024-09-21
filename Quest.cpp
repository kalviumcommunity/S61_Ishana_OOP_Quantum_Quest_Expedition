#include <iostream>
#include <string>
using namespace std;

// Class representing an Astronaut
class Astronaut {
private:
    string name;
    string role;
    int health;
    int energy;

public:
    // Constructor
    Astronaut(string n = "", string r = "", int h = 100, int e = 100)
        : name(n), role(r), health(h), energy(e) {}

    // Accessor (Getter) for name
    string getName() const {
        return name;
    }

    // Mutator (Setter) for name
    void setName(const string& newName) {
        name = newName;
    }

    // Accessor (Getter) for health
    int getHealth() const {
        return health;
    }

    // Mutator (Setter) for health with validation
    void setHealth(int newHealth) {
        if (newHealth > 0 && newHealth <= 100) {
            health = newHealth;
        } else {
            cout << "Invalid health value. Must be between 1 and 100." << endl;
        }
    }

    // Report astronaut's status
    void reportStatus() const {
        cout << "Astronaut " << name << " (Role: " << role << ") has " 
             << health << " health and " << energy << " energy remaining." << endl;
    }
};

// Class representing the Spaceship
class Spaceship {
private:
    string name;
    int fuel;
    int oxygen;

public:
    // Constructor
    Spaceship(string n = "", int f = 1000, int o = 1000)
        : name(n), fuel(f), oxygen(o) {}

    // Accessor (Getter) for fuel
    int getFuel() const {
        return fuel;
    }

    // Mutator (Setter) for fuel with validation
    void setFuel(int newFuel) {
        if (newFuel >= 0) {
            fuel = newFuel;
        } else {
            cout << "Invalid fuel value. Must be non-negative." << endl;
        }
    }

    // Accessor (Getter) for oxygen
    int getOxygen() const {
        return oxygen;
    }

    // Mutator (Setter) for oxygen with validation
    void setOxygen(int newOxygen) {
        if (newOxygen >= 0) {
            oxygen = newOxygen;
        } else {
            cout << "Invalid oxygen value. Must be non-negative." << endl;
        }
    }

    // Report spaceship's status
    void checkStatus() const {
        cout << "Spaceship " << name << " has " << fuel << " units of fuel and " 
             << oxygen << " units of oxygen remaining." << endl;
    }
};

int main() {
    // Create Astronaut object and prompt user to input details
    Astronaut astronaut;
    string astronautName;
    int astronautHealth;

    cout << "Enter the astronaut's name: ";
    getline(cin, astronautName);
    astronaut.setName(astronautName);

    cout << "Enter the astronaut's health (1-100): ";
    cin >> astronautHealth;
    astronaut.setHealth(astronautHealth);

    // Report astronaut status
    astronaut.reportStatus();

    // Create Spaceship object and prompt user to input fuel and oxygen
    Spaceship spaceship("Mangalyaan");
    int spaceshipFuel, spaceshipOxygen;

    cout << "Enter fuel for the spaceship: ";
    cin >> spaceshipFuel;
    spaceship.setFuel(spaceshipFuel);

    cout << "Enter oxygen for the spaceship: ";
    cin >> spaceshipOxygen;
    spaceship.setOxygen(spaceshipOxygen);

    // Check spaceship status
    spaceship.checkStatus();

    return 0;
}
