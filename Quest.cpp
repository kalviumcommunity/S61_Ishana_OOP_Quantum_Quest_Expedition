#include <iostream>
#include <string>
using namespace std;

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

    // Getters (Accessors) - Public access to private data members
    string getName() const {
        return name;
    }

    string getRole() const {
        return role;
    }

    int getHealth() const {
        return health;
    }

    int getEnergy() const {
        return energy;
    }

    // Setters (Mutators) - Public access to modify private data members
    void setName(const string& newName) {
        name = newName;
    }

    void setRole(const string& newRole) {
        role = newRole;
    }

    void setHealth(int newHealth) {
        if (newHealth > 0 && newHealth <= 100) {
            health = newHealth;
        } else {
            cout << "Invalid health value. Must be between 1 and 100." << endl;
        }
    }

    void setEnergy(int newEnergy) {
        if (newEnergy >= 0 && newEnergy <= 100) {
            energy = newEnergy;
        } else {
            cout << "Invalid energy value. Must be between 0 and 100." << endl;
        }
    }

    // Report function to show astronaut's status
    void reportStatus() const {
        cout << "Astronaut " << name << " (" << role << ") has " 
             << health << " health and " << energy << " energy remaining." << endl;
    }
};

class Spaceship {
private:
    string name;
    int fuel;
    int oxygen;

public:
    // Constructor
    Spaceship(string n = "", int f = 1000, int o = 1000)
        : name(n), fuel(f), oxygen(o) {}

    // Getters for Spaceship
    int getFuel() const {
        return fuel;
    }

    int getOxygen() const {
        return oxygen;
    }

    string getName() const {
        return name;
    }

    // Setters for Spaceship
    void setFuel(int newFuel) {
        if (newFuel >= 0) {
            fuel = newFuel;
        } else {
            cout << "Invalid fuel value. Must be non-negative." << endl;
        }
    }

    void setOxygen(int newOxygen) {
        if (newOxygen >= 0) {
            oxygen = newOxygen;
        } else {
            cout << "Invalid oxygen value. Must be non-negative." << endl;
        }
    }

    // Report function to show spaceship's status
    void checkStatus() const {
        cout << "Spaceship " << name << " has " << fuel << " units of fuel and " 
             << oxygen << " units of oxygen remaining." << endl;
    }
};

// Main function to simulate user interaction
int main() {
    // Creating astronaut object and collecting user input
    Astronaut astronaut;
    string astronautName, astronautRole;
    int astronautHealth, astronautEnergy;

    cout << "Enter the astronaut's name: ";
    getline(cin, astronautName);
    astronaut.setName(astronautName);

    cout << "Enter the astronaut's role: ";
    getline(cin, astronautRole);
    astronaut.setRole(astronautRole);

    cout << "Enter the astronaut's health (1-100): ";
    cin >> astronautHealth;
    astronaut.setHealth(astronautHealth);

    cout << "Enter the astronaut's energy (0-100): ";
    cin >> astronautEnergy;
    astronaut.setEnergy(astronautEnergy);

    // Report astronaut's status
    astronaut.reportStatus();

    // Creating spaceship object and collecting user input
    Spaceship spaceship("Mangalyaan");
    int spaceshipFuel, spaceshipOxygen;

    cout << "Enter fuel for the spaceship: ";
    cin >> spaceshipFuel;
    spaceship.setFuel(spaceshipFuel);

    cout << "Enter oxygen for the spaceship: ";
    cin >> spaceshipOxygen;
    spaceship.setOxygen(spaceshipOxygen);

    // Report spaceship's status
    spaceship.checkStatus();

    return 0;
}
