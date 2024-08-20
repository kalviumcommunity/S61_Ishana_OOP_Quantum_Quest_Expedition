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
    Astronaut(string n, string r, int h, int e) : name(n), role(r), health(h), energy(e) {}

    // Member function to perform a task
    void performTask(string task) {
        cout << name << " is performing the task: " << task << " as a " << role << "." << endl;
        energy -= 10;  // Task consumes energy
    }

    // Member function to report the current status of the astronaut
    void reportStatus() {
        cout << "Astronaut " << name << " (Role: " << role << ") has " << health 
             << " health and " << energy << " energy remaining." << endl;
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
    Spaceship(string n, int f, int o) : name(n), fuel(f), oxygen(o) {}

    // Member function to allocate resources
    void allocateResource(string resource, int amount) {
        if (resource == "fuel") {
            if (amount <= fuel && amount > 0) {
                fuel -= amount;
                cout << "Allocated " << amount << " units of fuel. Fuel remaining: " << fuel << "." << endl;
            } else {
                cout << "Error: Invalid fuel amount. Available fuel: " << fuel << "." << endl;
            }
        } else if (resource == "oxygen") {
            if (amount <= oxygen && amount > 0) {
                oxygen -= amount;
                cout << "Allocated " << amount << " units of oxygen. Oxygen remaining: " << oxygen << "." << endl;
            } else {
                cout << "Error: Invalid oxygen amount. Available oxygen: " << oxygen << "." << endl;
            }
        }
    }

    // Member function to check the spaceship's status
    void checkStatus() {
        cout << "Spaceship " << name << " has " << fuel << " units of fuel and " 
             << oxygen << " units of oxygen remaining." << endl;
    }
};

int main() {
    string astronautName, astronautRole, task;
    int astronautHealth, astronautEnergy;

    // User inputs for Astronaut
    cout << "Enter astronaut's name: ";
    getline(cin, astronautName);
    cout << "Enter astronaut's role: ";
    getline(cin, astronautRole);

    cout << "Enter astronaut's health (0 - 100): ";
    cin >> astronautHealth;
    while (astronautHealth < 0 || astronautHealth > 100) {
        cout << "Invalid health value. Please enter a value between 0 and 100: ";
        cin >> astronautHealth;
    }

    cout << "Enter astronaut's energy (0 - 100): ";
    cin >> astronautEnergy;
    while (astronautEnergy < 0 || astronautEnergy > 100) {
        cout << "Invalid energy value. Please enter a value between 0 and 100: ";
        cin >> astronautEnergy;
    }

    // Creating an Astronaut object
    Astronaut astronaut1(astronautName, astronautRole, astronautHealth, astronautEnergy);

    // User inputs for Spaceship
    string spaceshipName;
    int spaceshipFuel, spaceshipOxygen;

    cout << "Enter spaceship's name: ";
    cin.ignore();
    getline(cin, spaceshipName);

    cout << "Enter spaceship's fuel (0 - 1000): ";
    cin >> spaceshipFuel;
    while (spaceshipFuel < 0 || spaceshipFuel > 1000) {
        cout << "Invalid fuel amount. Please enter a value between 0 and 1000: ";
        cin >> spaceshipFuel;
    }

    cout << "Enter spaceship's oxygen (0 - 500): ";
    cin >> spaceshipOxygen;
    while (spaceshipOxygen < 0 || spaceshipOxygen > 500) {
        cout << "Invalid oxygen amount. Please enter a value between 0 and 500: ";
        cin >> spaceshipOxygen;
    }

    // Creating a Spaceship object
    Spaceship spaceship1(spaceshipName, spaceshipFuel, spaceshipOxygen);

    // Performing tasks and allocating resources
    cout << "Enter a task for the astronaut to perform: ";
    cin.ignore();
    getline(cin, task);

    astronaut1.performTask(task);
    astronaut1.reportStatus();

    int fuelToAllocate, oxygenToAllocate;
    cout << "Enter amount of fuel to allocate: ";
    cin >> fuelToAllocate;
    spaceship1.allocateResource("fuel", fuelToAllocate);

    cout << "Enter amount of oxygen to allocate: ";
    cin >> oxygenToAllocate;
    spaceship1.allocateResource("oxygen", oxygenToAllocate);

    spaceship1.checkStatus();

    return 0;
}
