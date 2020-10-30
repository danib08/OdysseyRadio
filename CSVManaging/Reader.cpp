//
// Created by dani on 16/10/20.
//

#include "Reader.h"
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

Reader::Reader() : pagination(20) {
    page_now = new SongList();
    page_before = new SongList();
    page_after = new SongList();
    all_songs = new SongList();
    artist_list = new ArtistList();
    artist_songs = new SongList();
}

void Reader::firstRead() {
    all_songs->clear();
    page_now->clear();
    page_before->clear();
    page_after->clear();

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

void Reader::readDown(string last_id) {
    all_songs->clear();
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

void Reader::readUp(string first_id) {
    all_songs->clear();
    page_now->clear();
    page_before->clear();
    page_after->clear();

    int pos = getPosition(first_id);
    ifstream file;
    file.open("../Metadata/" + file_name);
    int line_counter = 1;
    bool range_found = false;

    if (pos > 60) {
        while (file.good()) {
            string line;
            getline(file, line, '\n');
            string id;

            stringstream check1(line);
            getline(check1, id, ',');

            if (line_counter == 61 && range_found) {
                break;
            }
            if (line_counter == pos - (pagination * 3) && !range_found) {
                line_counter = 1;
                range_found = true;
            }
            if (range_found) {
                if (line_counter < pagination + 1) {
                    splitLine(line, 2);
                }
                if (line_counter >= pagination + 1 && line_counter <= 2 * pagination) {
                    splitLine(line, 0);
                }
                if (line_counter > pagination * 2) {
                    splitLine(line, 1);
                }
            }
            line_counter++;
        }
    }
    else {
        while (file.good()) {
            string line;
            getline(file, line, '\n');
            string id;

            stringstream check1(line);
            getline(check1, id, ',');

            if (line_counter == pos - 1) {
                break;
            }
            if (line_counter < pagination + 1) {
                splitLine(line, 2);
            }
            if (line_counter >= pagination + 1 && line_counter <= 2 * pagination) {
                splitLine(line, 0);
            }
            if (line_counter > pagination * 2) {
                splitLine(line, 1);
            }
            line_counter++;
        }
    }
}

void Reader::readAll() {
    all_songs->clear();
    page_now->clear();
    page_before->clear();
    page_after->clear();

    ifstream file;
    file.open("../Metadata/" + file_name);

    while (file.good()) {
        string line;
        getline(file, line, '\n');
        string id;

        stringstream check1(line);
        getline(check1, id, ',');

        splitLine(line, 4);
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
        case 3:
            artist_songs->append(one, two, three);
            break;
        default:
            all_songs->append(one, two, three);
            break;
    }
}

int Reader::getPosition(string first_id) {
    ifstream file;
    file.open("../Metadata/" + file_name);
    int pos = 1;

    while (file.good()) {
        string line;
        getline(file, line, '\n');
        string id;

        stringstream check1(line);
        getline(check1, id, ',');
        if (id == first_id) {
            break;
        }
        pos++;
    }
    return pos;
}

void Reader::readArtists() {
    ifstream file;
    file.open("../Metadata/" + file_name);

    while (file.good()) {
        string line;
        getline(file, line, '\n');
        string artist;

        stringstream check1(line);
        getline(check1, artist, ',');
        getline(check1, artist, ',');

        if (!artist_list->exists(artist)) {
            artist_list->append(artist);
        }
    }
}

void Reader::readArtSongs(string name) {
    artist_songs->clear();
    ifstream file;
    file.open("../Metadata/" + file_name);

    while (file.good()) {
        string line;
        getline(file, line, '\n');
        string artist;

        stringstream check1(line);
        getline(check1, artist, ',');
        getline(check1, artist, ',');

        if (artist == name) {
            splitLine(line, 3);
        }
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

std::string Reader::getAllSongs() {
    return all_songs->get();
}

std::string Reader::getArtists() {
    return artist_list->get();
}

string Reader::getArtSongs() {
    return artist_songs->get();
}
