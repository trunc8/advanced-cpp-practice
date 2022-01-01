#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in_file;

    string input_filename = "text.txt";
    in_file.open(input_filename);

    if (in_file.is_open()) {
        cout << "Opened" << endl;
        string line;
        while (in_file) {
            getline(in_file, line);
            cout << line << endl;
        }
        in_file.close();
    }
    else {
        cout << "Could not open " << input_filename << endl;
    }
    
    return 0;
}
