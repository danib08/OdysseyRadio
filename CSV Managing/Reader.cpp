//
// Created by dani on 16/10/20.
//

#include "Reader.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Reader::Reader() = default;

string Reader::Read(string file_name) {
    ifstream file;
    file.open("../Metadata/" + file_name);
    int counter = 0;

    while (file.good()) {
        if (counter == 2) {
            break;
        }
        string line;
        getline(file, line, ',');
        cout << line << endl;
        counter++;
    }
    return string();
}
