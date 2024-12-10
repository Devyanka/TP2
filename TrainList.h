#ifndef TRAINLIST_H
#define TRAINLIST_H

#include "Train.h"

class TrainList {
private:
    Train* trains;
    int size;
    int capacity;

    void resize();

public:
    TrainList();
    ~TrainList();

    void addTrain(const Train& train);
    void printTrains() const;
    void findTrainsByDestination(const string& destination) const;
};

#endif