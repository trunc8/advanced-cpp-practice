#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Test {
private:
    string name;
    int id;
public:
    Test() : 
        name(""), id(0) {
    }
    Test(string name, int id) :
        name(name), id(id) {
    }
    void print() {
        cout << "Name: " << name << "\tID:" << id << endl;
    }
    // bool operator< (const Test &other) const {
    //     if (name == other.name) {
    //         return id < other.id;
    //     } else {
    //         return name < other.name;
    //     }        
    // }

    friend bool comp (const Test &a, const Test &b);
};

bool comp (const Test &a, const Test &b) {
    if (a.name == b.name) {
        return a.id < b.id;
    } else {
        return a.name < b.name;
    }
}

int main() {

    // LIFO
    vector<Test> people;
    people.push_back(Test("Tintin", 50));
    people.push_back(Test("Tintin", 10));
    people.push_back(Test("Kailash", 90));
    people.push_back(Test("Bruno", 1000));

    for (auto &i: people) {
        i.print();
    }
    cout << endl;
    
    sort(people.begin(), people.begin()+3, comp);

    for (auto &i: people) {
        i.print();
    }

    cout << endl;

    // FIFO



    return 0;
}
