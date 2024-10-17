#include <iostream>
#include <string>
using namespace std;

// Base Class
class Astronaut {
protected:
    string name;
    int health;
    int energy;

public:
    // Constructor
    Astronaut(string n, int h, int e) : name(n), health(h), energy(e) {}

    // Function to display status
    virtual void displayStatus() const {
        cout << "Astronaut " << name << " has " << health << "% health and " << energy << "% energy." << endl;
    }

    // Virtual Destructor
    virtual ~Astronaut() {
        cout << "Astronaut " << name << " has finished the mission." << endl;
    }
};

// Derived Class 1 (Single Inheritance)
class Scientist : public Astronaut {
protected:
    string experiment;

public:
    Scientist(string n, int h, int e, string exp)
        : Astronaut(n, h, e), experiment(exp) {}

    // Overriding display function
    void displayStatus() const override {
        Astronaut::displayStatus();
        cout << "Scientist " << name << " is conducting experiment: " << experiment << "." << endl;
    }

    ~Scientist() {
        cout << "Scientist " << name << " has completed their experiment." << endl;
    }
};

// Derived Class 2 (Multilevel Inheritance)
class Commander : public Scientist {
private:
    string missionObjective;

public:
    Commander(string n, int h, int e, string exp, string obj)
        : Scientist(n, h, e, exp), missionObjective(obj) {}

    // Overriding display function
    void displayStatus() const override {
        Scientist::displayStatus();
        cout << "Commander " << name << " has the mission objective: " << missionObjective << "." << endl;
    }

    ~Commander() {
        cout << "Commander " << name << " has accomplished the mission objective." << endl;
    }
};

// Main function
int main() {
    string astronautName, experiment, objective;
    int health, energy;

    // Get Astronaut details from the user
    cout << "\nEnter the astronaut's name: ";
    getline(cin, astronautName);
    cout << "Enter the astronaut's health (1-100): ";
    cin >> health;
    cout << "Enter the astronaut's energy (1-100): ";
    cin >> energy;
    cin.ignore();  // Clear the newline character left by cin

    // Get Scientist-specific details
    cout << "Enter the experiment the scientist is conducting: ";
    getline(cin, experiment);

    // Get Commander-specific details
    cout << "Enter the mission objective for the commander: ";
    getline(cin, objective);

    // Create a Commander object (which inherits from Scientist and Astronaut)
    Commander commander1(astronautName, health, energy, experiment, objective);

    // Display the status
    commander1.displayStatus();

    return 0;
}
