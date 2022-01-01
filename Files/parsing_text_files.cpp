#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in_file;

    string input_filename = "stats.txt";
    in_file.open(input_filename);

    if (!in_file.is_open()) {
        return 1;
    }

    cout << "Opened" << endl;

    while (in_file) {
        string line;
        getline(in_file, line, ':');

        if (!in_file) break;

        int population;
        in_file >> population;

        // in_file.get();
        in_file >> ws;

        cout << "'" << line << "' -- '" << population << "'" << endl;
    }

    in_file.close();
    
    return 0;
}
