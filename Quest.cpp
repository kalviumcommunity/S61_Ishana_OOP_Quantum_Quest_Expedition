#include <iostream>
#include <string>
#include <limits> // For numeric_limits

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

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter for role
    string getRole() const {
        return role;
    }

    // Member function to perform a task
    void performTask(const string& task) {
        cout << name << " is performing the task: " << task << " as a " << role << "." << endl;
        energy -= 10; // Task consumes energy
    }

    // Member function to report the current status of the astronaut
    void reportStatus() const {
        cout << "Astronaut " << name << " (Role: " << role << ") has " 
             << health << " health and " << energy << " energy remaining." << endl;
    }

    // Function to update astronaut details
    void updateDetails(const string& n, const string& r, int h, int e) {
        name = n;
        role = r;
        health = h;
        energy = e;
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

    // Member function to allocate resources
    void allocateResource(const string& resource, int amount) {
        if (resource == "fuel") {
            fuel -= amount;
            cout << "Allocated " << amount << " units of fuel. Fuel remaining: " << fuel << "." << endl;
        } else if (resource == "oxygen") {
            oxygen -= amount;
            cout << "Allocated " << amount << " units of oxygen. Oxygen remaining: " << oxygen << "." << endl;
        } else {
            cout << "Unknown resource type." << endl;
        }
    }

    // Member function to check the spaceship's status
    void checkStatus() const {
        cout << "Spaceship " << name << " has " << fuel << " units of fuel and " 
             << oxygen << " units of oxygen remaining." << endl;
    }
};

// Function to get valid integer input from the user
int getValidIntInput() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Clearing the error 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
            cout << "Invalid input. Please enter a valid integer: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding leftover input
            return value;
        }
    }
}

int main() {
    int numAstronauts;
    cout << "Enter the number of astronauts: ";
    numAstronauts = getValidIntInput();

    // Dynamically allocate an array of Astronaut objects
    Astronaut* astronauts = new Astronaut[numAstronauts];

    // Get astronaut details from the user
    for (int i = 0; i < numAstronauts; ++i) {
        string name, role;
        int health, energy;

        cout << "Enter details for Astronaut " << (i + 1) << ":" << endl;

        cout << "Name: ";
        getline(cin, name);
        cout << "Role: ";
        getline(cin, role);

        cout << "Health (integer value): ";
        health = getValidIntInput();

        cout << "Energy (integer value): ";
        energy = getValidIntInput();

        astronauts[i].updateDetails(name, role, health, energy);
    }

    // Dynamically allocate a Spaceship object
    Spaceship* spaceship = new Spaceship("Mangalyaan", 500, 300);

    // Perform tasks with astronaut objects
    for (int i = 0; i < numAstronauts; ++i) {
        string task;
        cout << "Enter a task for " << astronauts[i].getName() << ": ";
        getline(cin, task);
        astronauts[i].performTask(task);
        astronauts[i].reportStatus();
    }

    // Allocate resources and check status of spaceship
    string resource;
    int amount;

    cout << "Enter resource type (fuel/oxygen): ";
    cin >> resource;
    cout << "Enter amount: ";
    amount = getValidIntInput();
    spaceship->allocateResource(resource, amount);
    spaceship->checkStatus();

    // Deallocate dynamically allocated memory
    delete[] astronauts;
    delete spaceship;

    return 0;
}
