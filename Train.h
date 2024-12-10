#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>

using namespace std;

class Train {
private:
    string destination;
    int trainNumber;
    string departureTime;

public:
    Train();
    Train(const string& destination, int trainNumber, const string& departureTime);
    Train(const Train& other);
    ~Train();

    string getDestination() const;
    void setDestination(const string& destination);

    int getTrainNumber() const;
    void setTrainNumber(int trainNumber);

    string getDepartureTime() const;
    void setDepartureTime(const string& departureTime);

    bool operator>(const Train& other) const;
    bool operator<(const Train& other) const;

    friend ostream& operator<<(ostream& os, const Train& train);
    friend istream& operator>>(istream& is, Train& train);
};

#endif