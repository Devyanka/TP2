#include "TrainList.h"
#include <iostream>

TrainList::TrainList() : trains(nullptr), size(0), capacity(2) {
    trains = new Train[capacity];
    cout << "TrainList created.\n";
}

TrainList::~TrainList() {
    delete[] trains;
    cout << "TrainList destroyed.\n";
}

void TrainList::resize() {
    capacity *= 2;
    Train* newTrains = new Train[capacity];
    for (int i = 0; i < size; ++i) {
        newTrains[i] = trains[i];
    }
    delete[] trains;
    trains = newTrains;
    cout << "TrainList resized to capacity " << capacity << ".\n";
}

void TrainList::addTrain(const Train& train) {
    if (size == capacity) {
        resize();
    }

    int i;
    for (i = size - 1; i >= 0 && trains[i] > train; --i) {
        trains[i + 1] = trains[i]; // Shift elements to the right
    }
    trains[i + 1] = train; // Insert new train
    ++size;

    cout << "Train added and automatically sorted.\n";
}

void TrainList::printTrains() const {
    for (int i = 0; i < size; ++i) {
        cout << trains[i] << endl;
    }
}

void TrainList::findTrainsByDestination(const string& destination) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (trains[i].getDestination() == destination) {
            cout << trains[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No trains found for destination: " << destination << endl;
    }
}