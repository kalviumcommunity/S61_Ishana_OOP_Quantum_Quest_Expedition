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

    // Member function to perform a task using 'this' pointer
    void performTask(string task) {
        cout << this->name << " is performing the task: " << task << " as a " << this->role << "." << endl;
        this->energy -= 10;  // Task consumes energy
    }

    // Member function to report the current status of the astronaut using 'this' pointer
    void reportStatus() {
        cout << "Astronaut " << this->name << " (Role: " << this->role << ") has " << this->health 
             << " health and " << this->energy << " energy remaining." << endl;
    }

    // Setters
    void setName(string n) { this->name = n; }
    void setRole(string r) { this->role = r; }
    void setHealth(int h) { this->health = h; }
    void setEnergy(int e) { this->energy = e; }
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

    // Member function to allocate resources using 'this' pointer
    void allocateResource(string resource, int amount) {
        if (resource == "fuel") {
            this->fuel -= amount;
            cout << "Allocated " << amount << " units of fuel. Fuel remaining: " << this->fuel << "." << endl;
        } else if (resource == "oxygen") {
            this->oxygen -= amount;
            cout << "Allocated " << amount << " units of oxygen. Oxygen remaining: " << this->oxygen << "." << endl;
        }
    }

    // Member function to check the spaceship's status using 'this' pointer
    void checkStatus() {
        cout << "Spaceship " << this->name << " has " << this->fuel << " units of fuel and " 
             << this->oxygen << " units of oxygen remaining." << endl;
    }

    // Setters
    void setName(string n) { this->name = n; }
    void setFuel(int f) { this->fuel = f; }
    void setOxygen(int o) { this->oxygen = o; }
};

int main() {
    string name, role, resource;
    int health, energy, fuel, oxygen, amount;

    // Input for Astronaut
    cout << "Enter the name of the astronaut: ";
    getline(cin, name);
    cout << "Enter the role of the astronaut: ";
    getline(cin, role);
    cout << "Enter the health of the astronaut: ";
    cin >> health;
    cout << "Enter the energy of the astronaut: ";
    cin >> energy;
    cin.ignore(); // To ignore the remaining newline character in the input buffer

    // Creating an Astronaut object
    Astronaut astronaut1(name, role, health, energy);
    
    // Performing tasks with astronaut object
    cout << "Enter a task for the astronaut: ";
    getline(cin, role); // Reusing role input for the task description
    astronaut1.performTask(role);
    astronaut1.reportStatus();

    // Input for Spaceship
    cout << "Enter the name of the spaceship: ";
    getline(cin, name);
    cout << "Enter the amount of fuel: ";
    cin >> fuel;
    cout << "Enter the amount of oxygen: ";
    cin >> oxygen;
    cin.ignore(); // To ignore the remaining newline character in the input buffer

    // Creating a Spaceship object
    Spaceship spaceship1(name, fuel, oxygen);
    
    // Allocating resources
    cout << "Enter the resource to allocate (fuel/oxygen): ";
    getline(cin, resource);
    cout << "Enter the amount to allocate: ";
    cin >> amount;
    spaceship1.allocateResource(resource, amount);
    spaceship1.checkStatus();

    return 0;
}
