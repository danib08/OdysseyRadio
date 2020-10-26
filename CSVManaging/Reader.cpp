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
    ifstream file;
    file.open("../Metadata/" + file_name);
    int line_counter = 1;
    int column_counter = 1;
    string one;
    string two;
    string three;
    string four;
    string five;
    string six;
    string seven;

    if (last_row % pagination == 0) {
        if (scroll_down) {
            page_before = page_now;
            page_now = page_after;
            page_after->clear();
        }
        else {
            page_after = page_now;
            page_now = page_before;
            page_before->clear();
        }

        while (file.good()) {
            if (scroll_down && line_counter == last_row + 41) {
                break;
            }
            if (!scroll_down && line_counter == last_row - 39) {
                break;
            }
            string line;
            getline(file, line, ',');

            if (scroll_down && line_counter < last_row + 41 && line_counter > last_row + 20) {
                switch (column_counter) {
                    case 1:
                        one = line;
                    case 2:
                        two = line;
                    case 3:
                        three = line;
                    case 4:
                        four = line;
                    case 5:
                        five = line;
                    case 6:
                        six = line;
                    case 7:
                        seven = line;
                        page_now->append(one, two, three);
                }
            }
            if (!scroll_down && line_counter <= last_row - 40 && line_counter > last_row - 60) {
                switch (column_counter) {
                    case 1:
                        one = line;
                    case 2:
                        two = line;
                    case 3:
                        three = line;
                    case 4:
                        four = line;
                    case 5:
                        five = line;
                    case 6:
                        six = line;
                    case 7:
                        seven = line;
                        page_now->append(one, two, three);
                }
            }

            column_counter++;
            if (column_counter % 7 == 0) {
                column_counter = 1;
                line_counter++;
            }
        }
    }
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

std::string Reader::getNowPage() {
    return page_now->get();
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

std::string Reader::getAfterPage() {
    return page_after->get();
}
