#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Base Astronaut class implementing LSP with a performDuty method
class Astronaut {
protected:
    string name;
    int health;
    int energy;

public:
    Astronaut(string n, int h, int e) : name(n), health(h), energy(e) {}

    virtual void displayStatus() const {
        cout << "Astronaut " << name << " has " << health << "% health and " << energy << "% energy." << endl;
    }

    // Virtual function to be overridden by subclasses
    virtual void performDuty() const = 0; // Pure virtual function for LSP
};

// Scientist class inheriting from Astronaut and implementing performDuty
class Scientist : public Astronaut {
private:
    string experiment;

public:
    Scientist(string n, int h, int e, string exp)
        : Astronaut(n, h, e), experiment(exp) {}

    void performDuty() const override {
        cout << "Scientist " << name << " is conducting experiment: " << experiment << "." << endl;
    }
};

// Commander class inheriting from Astronaut and implementing performDuty
class Commander : public Astronaut {
private:
    string missionObjective;

public:
    Commander(string n, int h, int e, string obj)
        : Astronaut(n, h, e), missionObjective(obj) {}

    void performDuty() const override {
        cout << "Commander " << name << " is leading the mission: " << missionObjective << "." << endl;
    }
};

// Engineer class inheriting from Astronaut and implementing performDuty
class Engineer : public Astronaut {
private:
    string repairTask;

public:
    Engineer(string n, int h, int e, string task)
        : Astronaut(n, h, e), repairTask(task) {}

    void performDuty() const override {
        cout << "Engineer " << name << " is performing repair task: " << repairTask << "." << endl;
    }
};

// Main function to demonstrate LSP-compliant functionality
int main() {
    string name, experiment, objective, task;
    int health, energy, roleChoice;

    // User input for common astronaut details
    cout << "Enter the astronaut's name: ";
    getline(cin, name);
    cout << "Enter the astronaut's health (1-100): ";
    cin >> health;
    cout << "Enter the astronaut's energy (1-100): ";
    cin >> energy;
    cin.ignore();

    // User chooses the role
    cout << "Choose astronaut's role (1: Scientist, 2: Commander, 3: Engineer): ";
    cin >> roleChoice;
    cin.ignore();

    // Create a pointer to base class Astronaut, and assign specific subclass based on choice
    unique_ptr<Astronaut> astronaut;

    if (roleChoice == 1) {
        cout << "Enter the experiment the scientist is conducting: ";
        getline(cin, experiment);
        astronaut = make_unique<Scientist>(name, health, energy, experiment);
    } else if (roleChoice == 2) {
        cout << "Enter the mission objective for the commander: ";
        getline(cin, objective);
        astronaut = make_unique<Commander>(name, health, energy, objective);
    } else if (roleChoice == 3) {
        cout << "Enter the repair task the engineer is performing: ";
        getline(cin, task);
        astronaut = make_unique<Engineer>(name, health, energy, task);
    } else {
        cout << "Invalid role choice!" << endl;
        return 1;
    }

    // Display status and perform the selected duty
    astronaut->displayStatus();
    astronaut->performDuty();

    return 0;
}
