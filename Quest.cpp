#include <iostream>
#include <string>
using namespace std;

// Base Class with SRP for managing general astronaut details
class Astronaut {
protected:
    string name;
    int health;
    int energy;

public:
    Astronaut(string n, int h, int e) : name(n), health(h), energy(e) {}

    void displayStatus() const {
        cout << "Astronaut " << name << " has " << health << "% health and " << energy << "% energy." << endl;
    }
};

// Scientist class (Inherits from Astronaut with SRP for scientific tasks)
class Scientist : public Astronaut {
private:
    string experiment;

public:
    Scientist(string n, int h, int e, string exp)
        : Astronaut(n, h, e), experiment(exp) {}

    void conductExperiment() const {
        cout << "Scientist " << name << " is conducting experiment: " << experiment << "." << endl;
    }
};

// Commander class (Inherits from Astronaut with SRP for mission management)
class Commander : public Astronaut {
private:
    string missionObjective;

public:
    Commander(string n, int h, int e, string obj)
        : Astronaut(n, h, e), missionObjective(obj) {}

    void leadMission() const {
        cout << "Commander " << name << " is leading the mission: " << missionObjective << "." << endl;
    }
};

// New MonitoringSystem class (SRP for monitoring external threats)
class MonitoringSystem {
private:
    string threatType;
    int threatDistance;

public:
    MonitoringSystem(string threat, int distance) : threatType(threat), threatDistance(distance) {}

    void checkForThreat() const {
        if (threatDistance < 100) {
            cout << "Warning: " << threatType << " detected at " << threatDistance << " km distance. Take evasive actions!" << endl;
        } else {
            cout << "No immediate threats. " << threatType << " is at a safe distance of " << threatDistance << " km." << endl;
        }
    }
};

// Main function to demonstrate SRP-compliant functionality
int main() {
    string name, experiment, objective, threatType;
    int health, energy, roleChoice, threatDistance;

    // User input for common astronaut details
    cout << "Enter the astronaut's name: ";
    getline(cin, name);
    cout << "Enter the astronaut's health (1-100): ";
    cin >> health;
    cout << "Enter the astronaut's energy (1-100): ";
    cin >> energy;
    cin.ignore();

    // Role selection
    cout << "Choose astronaut's role (1: Scientist, 2: Commander): ";
    cin >> roleChoice;
    cin.ignore();

    if (roleChoice == 1) {
        cout << "Enter the experiment the scientist is conducting: ";
        getline(cin, experiment);

        Scientist scientist(name, health, energy, experiment);
        scientist.displayStatus();
        scientist.conductExperiment();
    } else if (roleChoice == 2) {
        cout << "Enter the mission objective for the commander: ";
        getline(cin, objective);

        Commander commander(name, health, energy, objective);
        commander.displayStatus();
        commander.leadMission();
    } else {
        cout << "Invalid role choice!" << endl;
        return 1;
    }

    // Monitoring for threats
    cout << "\nEnter the type of threat (e.g., Asteroid): ";
    getline(cin, threatType);
    cout << "Enter the distance of the threat from the spaceship (in km): ";
    cin >> threatDistance;

    MonitoringSystem monitoringSystem(threatType, threatDistance);
    monitoringSystem.checkForThreat();

    return 0;
}
