//
// Created by dani on 16/10/20.
//

#include "Reader.h"
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

Reader::Reader() : pagination(20) {
    page_now = new LinkedList();
    page_before = new LinkedList();
    page_after = new LinkedList();
}

void Reader::Read() {
    
}

void Reader::firstRead() {
    ifstream file;
    file.open("../Metadata/" + file_name);
    int line_counter = 1;

    while (file.good()) {
        if (line_counter == 41) {
            break;
        }

        string line;
        getline(file, line, '\n');

        if (line_counter < 21) {
            splitLine(line, true);
        }
        else {
            splitLine(line, false);
        }

        line_counter++;
    }
}

void Reader::splitLine(string line, bool flag) {
    string one;
    string two;
    string three;
    int counter = 1;

    stringstream check1(line);
    string intermediate;

    while(getline(check1, intermediate, ',')) {
        switch (counter) {
            case 1:
                one = intermediate;
            case 2:
                two = intermediate;
            case 3:
                three = intermediate;
        }
        counter++;
    }
    if (flag) {
        page_now->append(one, two, three);
    }
    else {
        page_after->append(one, two, three);
    }
}

std::string Reader::getNowPage() {
    return page_now->get();
}

std::string Reader::getAfterPage() {
    return page_after->get();
}
