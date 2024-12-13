#include "TrainList.h"
#include <iostream>

using namespace std;

int main() {
    TrainList trainList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Train\n";
        cout << "2. Print All Trains\n";
        cout << "3. Find Trains by Destination\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { //Add
                Train train;
                cin >> train;
                trainList.addTrain(train);
                break;
            }
            case 2: //Print
                trainList.printTrains();
                break;
            case 3: { //Search
                string destination;
                cout << "Enter destination: ";
                cin >> destination;
                trainList.findTrainsByDestination(destination);
                break;
            }
            case 4: //Exit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}