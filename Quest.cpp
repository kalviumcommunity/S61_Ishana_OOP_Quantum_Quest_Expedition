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
    static int totalAstronauts; // Static variable to track the total number of astronauts

public:
    // Constructor
    Astronaut(string n = "", string r = "", int h = 100, int e = 100)
        : name(n), role(r), health(h), energy(e) {
        totalAstronauts++; // Increment the count when a new astronaut is created
    }

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

    // Static member function to get the total number of astronauts
    static int getTotalAstronauts() {
        return totalAstronauts;
    }
};

// Initialize static variable
int Astronaut::totalAstronauts = 0;

// Class representing the Spaceship
class Spaceship {
private:
    string name;
    int fuel;
    int oxygen;
    static int totalFuelUsed; // Static variable to track the total fuel used across all spaceships

public:
    // Constructor
    Spaceship(string n = "", int f = 1000, int o = 1000)
        : name(n), fuel(f), oxygen(o) {}

    // Member function to allocate resources
    void allocateResource(const string& resource, int amount) {
        if (resource == "fuel") {
            fuel -= amount;
            totalFuelUsed += amount; // Track the total fuel used
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

    // Static function to get the total fuel used across all spaceships
    static int getTotalFuelUsed() {
        return totalFuelUsed;
    }
};

// Initialize static variable
int Spaceship::totalFuelUsed = 0;

int main() {
    // Create an array of dynamically allocated Astronaut objects
    int numAstronauts;
    cout << "Enter the number of astronauts: ";
    cin >> numAstronauts;
    cin.ignore(); // To ignore the newline character

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
        cin >> health;
        cout << "Energy (integer value): ";
        cin >> energy;
        cin.ignore(); // To ignore the newline character

        astronauts[i].updateDetails(name, role, health, energy);
    }

    // Create a dynamically allocated Spaceship object
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
    cin >> amount;
    spaceship->allocateResource(resource, amount);
    spaceship->checkStatus();

    // Output static variables using static member functions
    cout << "Total Astronauts: " << Astronaut::getTotalAstronauts() << endl;
    cout << "Total Fuel Used: " << Spaceship::getTotalFuelUsed() << endl;

    // Clean up dynamically allocated memory
    delete[] astronauts;
    delete spaceship;

    return 0;
}
