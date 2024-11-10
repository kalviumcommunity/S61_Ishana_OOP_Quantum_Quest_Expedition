#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Abstract FoodManager class (Interface) to apply DIP
class FoodManager {
public:
    virtual void displayFoodStatus() const = 0;
    virtual void consumeFood(int amount) = 0;
    virtual ~FoodManager() = default;
};

// Concrete FoodManager implementation for basic food supply management
class BasicFoodManager : public FoodManager {
private:
    int foodSupply;

public:
    BasicFoodManager(int initialSupply) : foodSupply(initialSupply) {}

    void displayFoodStatus() const override {
        cout << "Current food supply: " << foodSupply << " units." << endl;
    }

    void consumeFood(int amount) override {
        if (foodSupply >= amount) {
            foodSupply -= amount;
            cout << "Consumed " << amount << " units of food. Remaining supply: " << foodSupply << " units." << endl;
        } else {
            cout << "Insufficient food supply!" << endl;
        }
    }
};

// Base Astronaut class
class Astronaut {
protected:
    string name;
    int health;
    int energy;
    shared_ptr<FoodManager> foodManager; // Dependency on FoodManager interface

public:
    Astronaut(string n, int h, int e, shared_ptr<FoodManager> fm)
        : name(n), health(h), energy(e), foodManager(fm) {}

    virtual void displayStatus() const {
        cout << "Astronaut " << name << " has " << health << "% health and " << energy << "% energy." << endl;
        foodManager->displayFoodStatus();
    }

    virtual void performDuty() const = 0; // Abstract method
};

// Scientist class inheriting from Astronaut and implementing performDuty
class Scientist : public Astronaut {
private:
    string experiment;

public:
    Scientist(string n, int h, int e, shared_ptr<FoodManager> fm, string exp)
        : Astronaut(n, h, e, fm), experiment(exp) {}

    void performDuty() const override {
        cout << "Scientist " << name << " is conducting experiment: " << experiment << "." << endl;
        foodManager->consumeFood(5); // Consumes 5 units of food for task
    }
};

// Commander class inheriting from Astronaut and implementing performDuty
class Commander : public Astronaut {
private:
    string missionObjective;

public:
    Commander(string n, int h, int e, shared_ptr<FoodManager> fm, string obj)
        : Astronaut(n, h, e, fm), missionObjective(obj) {}

    void performDuty() const override {
        cout << "Commander " << name << " is leading the mission: " << missionObjective << "." << endl;
        foodManager->consumeFood(7); // Consumes 7 units of food for task
    }
};

// Main function demonstrating Dependency Inversion Principle
int main() {
    string name, experiment, objective;
    int health, energy, roleChoice;

    // Create a shared FoodManager instance
    shared_ptr<FoodManager> foodManager = make_shared<BasicFoodManager>(100);

    // User input for astronaut details
    cout << "Enter the astronaut's name: ";
    getline(cin, name);
    cout << "Enter the astronaut's health (1-100): ";
    cin >> health;
    cout << "Enter the astronaut's energy (1-100): ";
    cin >> energy;
    cin.ignore();

    // User chooses the role
    cout << "Choose astronaut's role (1: Scientist, 2: Commander): ";
    cin >> roleChoice;
    cin.ignore();

    // Pointer to Astronaut base class
    unique_ptr<Astronaut> astronaut;

    if (roleChoice == 1) {
        cout << "Enter the experiment the scientist is conducting: ";
        getline(cin, experiment);
        astronaut = make_unique<Scientist>(name, health, energy, foodManager, experiment);
    } else if (roleChoice == 2) {
        cout << "Enter the mission objective for the commander: ";
        getline(cin, objective);
        astronaut = make_unique<Commander>(name, health, energy, foodManager, objective);
    } else {
        cout << "Invalid role choice!" << endl;
        return 1;
    }

    // Display status and perform the selected duty
    astronaut->displayStatus();
    astronaut->performDuty();
    astronaut->displayStatus(); // Display updated status

    return 0;
}
