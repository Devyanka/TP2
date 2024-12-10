#include "Train.h"

Train::Train() : destination(""), trainNumber(0), departureTime("00:00") {
    cout << "Default Train constructor called.\n";
}

Train::Train(const string& destination, int trainNumber, const string& departureTime)
    : destination(destination), trainNumber(trainNumber), departureTime(departureTime) {
    cout << "Parameterized Train constructor called.\n";
}

Train::Train(const Train& other)
    : destination(other.destination), trainNumber(other.trainNumber), departureTime(other.departureTime) {
    cout << "Copy Train constructor called.\n";
}

Train::~Train() {
    cout << "Train destructor called.\n";
}

string Train::getDestination() const { return destination; }
void Train::setDestination(const string& destination) { this->destination = destination; }

int Train::getTrainNumber() const { return trainNumber; }
void Train::setTrainNumber(int trainNumber) { this->trainNumber = trainNumber; }

string Train::getDepartureTime() const { return departureTime; }
void Train::setDepartureTime(const string& departureTime) { this->departureTime = departureTime; }

bool Train::operator>(const Train& other) const {
    return departureTime > other.departureTime;
}

bool Train::operator<(const Train& other) const {
    return departureTime < other.departureTime;
}

ostream& operator<<(ostream& os, const Train& train) {
    os << "Destination: " << train.destination
       << ", Train Number: " << train.trainNumber
       << ", Departure Time: " << train.departureTime;
    return os;
}

istream& operator>>(istream& is, Train& train) {
    cout << "Enter destination: ";
    is >> train.destination;

    cout << "Enter train number: ";
    while (!(is >> train.trainNumber) || train.trainNumber <= 0) {
        is.clear(); // Очистка флага ошибки
        is.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование некорректного ввода
        cout << "Invalid train number. Please enter a positive integer: ";
    }

    cout << "Enter departure time (HH:MM): ";
    while (true) {
        is >> train.departureTime;
        if (train.departureTime.size() == 5 && train.departureTime[2] == ':' &&
            isdigit(train.departureTime[0]) && isdigit(train.departureTime[1]) &&
            isdigit(train.departureTime[3]) && isdigit(train.departureTime[4])) {
            int hours = stoi(train.departureTime.substr(0, 2));
            int minutes = stoi(train.departureTime.substr(3, 2));
            if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60) {
                break; // Валидное время
            }
        }
        cout << "Invalid time format. Please enter in HH:MM format: ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return is;
}