#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out_file;

    string output_filename = "text.txt";
    out_file.open(output_filename);

    if (out_file.is_open()) {
        cout << "Opened" << endl;
        for (int i=1; i<=10; i++) {
            out_file << i << ".\tThis is a line" << endl;
        }
        out_file.close();
    }
    else {
        cout << "Could not open " << output_filename << endl;
    }
    
    return 0;
}
