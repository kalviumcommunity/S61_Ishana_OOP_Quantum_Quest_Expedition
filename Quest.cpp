#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class (with pure virtual function)
class MissionRole {
protected:
    string name;
    int health;
    int energy;

public:
    // Constructor
    MissionRole(string n, int h, int e) : name(n), health(h), energy(e) {}

    // Pure Virtual Function (making this class abstract)
    virtual void executeMission() = 0;

    // Virtual Destructor
    virtual ~MissionRole() {
        cout << "MissionRole: " << name << " has completed their duty." << endl;
    }
};

// Derived Class: Scientist
class Scientist : public MissionRole {
private:
    string experiment;

public:
    // Constructor
    Scientist(string n, int h, int e, string exp)
        : MissionRole(n, h, e), experiment(exp) {}

    // Overriding the pure virtual function
    void executeMission() override {
        cout << "Scientist " << name << " with " << health << "% health and " 
             << energy << "% energy is conducting experiment: " << experiment << "." << endl;
    }

    ~Scientist() {
        cout << "Scientist " << name << " has concluded the experiment: " << experiment << "." << endl;
    }
};

// Derived Class: Commander
class Commander : public MissionRole {
private:
    string missionObjective;

public:
    // Constructor
    Commander(string n, int h, int e, string objective)
        : MissionRole(n, h, e), missionObjective(objective) {}

    // Overriding the pure virtual function
    void executeMission() override {
        cout << "Commander " << name << " with " << health << "% health and " 
             << energy << "% energy is leading the mission: " << missionObjective << "." << endl;
    }

    ~Commander() {
        cout << "Commander " << name << " has achieved the mission objective: " << missionObjective << "." << endl;
    }
};

// Main function
int main() {
    string astronautName, experiment, missionObjective;
    int health, energy;

    // Input for Astronaut details
    cout << "\nEnter astronaut's name: ";
    getline(cin, astronautName);
    cout << "Enter astronaut's health (1-100): ";
    cin >> health;
    cout << "Enter astronaut's energy (1-100): ";
    cin >> energy;
    cin.ignore();  // Clear newline left in the input buffer

    // Choose Role (Scientist or Commander)
    int roleChoice;
    cout << "Choose astronaut's role (1: Scientist, 2: Commander): ";
    cin >> roleChoice;
    cin.ignore();  // Clear newline left in the input buffer

    // Create pointers to abstract class
    MissionRole* astronaut = nullptr;

    if (roleChoice == 1) {
        // Get Scientist-specific details
        cout << "Enter the experiment the scientist is conducting: ";
        getline(cin, experiment);

        // Create Scientist object dynamically
        astronaut = new Scientist(astronautName, health, energy, experiment);
    } else if (roleChoice == 2) {
        // Get Commander-specific details
        cout << "Enter the mission objective for the commander: ";
        getline(cin, missionObjective);

        // Create Commander object dynamically
        astronaut = new Commander(astronautName, health, energy, missionObjective);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;  // Exit with error
    }

    // Execute the mission (Polymorphism using virtual function)
    astronaut->executeMission();

    // Clean up memory
    delete astronaut;

    return 0;
}
