#include "CSVManaging/Reader.h"

using namespace std;

int main() {
    Reader* reader = new Reader();
    reader->Read("raw_tracks-edited.csv");
}
