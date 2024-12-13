#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFileName; // Имя файла для чтения
    cout << "Enter name of file: ";
    cin >> inputFileName;
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << inputFileName << endl;
        return 1;
    }

    cout << "Quotes found in the file:\n\n";

    char ch;              
    bool insideQuote = false; 
    string currentQuote;      

    while (inputFile.get(ch)) { 
        if (ch == '\"') {       
            if (insideQuote) {
                cout << "\"" << currentQuote << "\"" << endl;
                currentQuote.clear();
            }
            insideQuote = !insideQuote;
        } else if (insideQuote) {
            currentQuote += ch;
        }
    }

    inputFile.close();
    return 0;
}