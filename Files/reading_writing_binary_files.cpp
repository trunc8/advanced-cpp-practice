#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main() {
    string filename = "text.bin";


    //// Writing to binary file /////
    Person someone = {"Frodo", 220, 51.1};

    ofstream out_file;
    out_file.open(filename, ios::binary);

    if (out_file.is_open()) {
        // out_file.write((char *)&someone, sizeof(Person));
        out_file.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        out_file.close();
    }
    else {
        cout << "Could not open " + filename << endl;
    }
    
    //// Reading from binary file /////
    Person someone_else = {};

    ifstream in_file;
    in_file.open(filename, ios::binary);

    if (in_file.is_open()) {
        // in_file.read((char *)&someone_else, sizeof(Person));
        in_file.read(reinterpret_cast<char *>(&someone_else), sizeof(Person));

        in_file.close();
    }
    else {
        cout << "Could not read " + filename << endl;
    }
    

    printf("%s, %d, %.2f\n",someone_else.name, 
        someone_else.age, someone_else.weight);

    return 0;
}
