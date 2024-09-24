#include <iostream>
#include <string>
using namespace std;

// Astronaut Class
class Astronaut {
private:
    string name;
    string role;
    int health;
    int energy;

public:
    // Default Constructor
    Astronaut() {
        name = "";
        role = "";
        health = 100;
        energy = 100;
    }

    // Parameterized Constructor
    Astronaut(string n, string r, int h, int e) {
        name = n;
        role = r;
        health = h;
        energy = e;
    }

    // Destructor
    ~Astronaut() {
        cout << "Astronaut " << name << " is no longer part of the mission." << endl;
    }

    // Getter and Setter Methods
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

    void reportStatus() const {
        cout << "Astronaut " << name << " (" << role << ") has " 
             << health << " health and " << energy << " energy remaining." << endl;
    }
};

// Spaceship Class
class Spaceship {
private:
    string name;
    int fuel;
    int oxygen;

public:
    // Parameterized Constructor
    Spaceship(string n, int f, int o) {
        name = n;
        fuel = f;
        oxygen = o;
        cout << "Spaceship " << name << " created with fuel: " << fuel << " and oxygen: " << oxygen << "." << endl;
    }

    // Destructor
    ~Spaceship() {
        cout << "Spaceship " << name << " is decommissioned." << endl;
    }

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

    void checkStatus() const {
        cout << "Spaceship " << name << " has " << fuel << " units of fuel and " 
             << oxygen << " units of oxygen remaining." << endl;
    }
};

// Main Function to Run the Simulation
int main() {
    // Collect user input for parameterized constructor
    string astronautName, astronautRole;
    int astronautHealth, astronautEnergy;

    cout << "\nEnter the astronaut's name: ";
    getline(cin, astronautName);
    cout << "Enter the astronaut's role: ";
    getline(cin, astronautRole);
    cout << "Enter the astronaut's health (1-100): ";
    cin >> astronautHealth;
    cout << "Enter the astronaut's energy (0-100): ";
    cin >> astronautEnergy;

    // Parameterized constructor call
    Astronaut astronaut2(astronautName, astronautRole, astronautHealth, astronautEnergy);
    astronaut2.reportStatus();

    // Create spaceship with parameterized constructor
    Spaceship spaceship("Apollo", 500, 1000);
    spaceship.checkStatus();

    return 0;
}
