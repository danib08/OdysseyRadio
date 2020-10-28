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

void Reader::read(string last_id) {
    page_now->clear();
    page_before->clear();
    page_after->clear();

    ifstream file;
    file.open("../Metadata/" + file_name);
    int line_counter = 1;
    bool flag = false;

    while (file.good()) {
        string line;
        getline(file, line, '\n');
        string id;

        if (!flag) {
            stringstream check1(line);
            getline(check1, id, ',');
            if (id == last_id) {
                flag = true;
            }
        }
        else {
            if (line_counter < pagination + 1) {
                splitLine(line, 2);
            }
            if (line_counter >= pagination + 1 && line_counter <= 2 * pagination) {
                splitLine(line, 0);
            }
            if (line_counter > pagination * 2) {
                splitLine(line, 1);
            }
            if (line_counter == 61) {
                break;
            }
            line_counter++;
        }
    }
}

void Reader::firstRead() {
    ifstream file;
    file.open("../Metadata/" + file_name);
    int line_counter = 1;

    while (file.good()) {
        if (line_counter == (2 * pagination) + 1) {
            break;
        }

        string line;
        getline(file, line, '\n');

        if (line_counter < pagination + 1) {
            splitLine(line, 0);
        }
        else {
            splitLine(line, 1);
        }

        line_counter++;
    }
}

void Reader::splitLine(string line, int flag) {
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
                break;
            case 2:
                two = intermediate;
                break;
            default:
                three = intermediate;
                break;
        }
        counter++;
    }

    switch (flag) {
        case 0:
            page_now->append(one, two, three);
            break;
        case 1:
            page_after->append(one, two, three);
            break;
        case 2:
            page_before->append(one, two, three);
            break;
    }
}

std::string Reader::getNowPage() {
    return page_now->get();
}

std::string Reader::getAfterPage() {
    return page_after->get();
}

std::string Reader::getBeforePage() {
    return page_before->get();
}
