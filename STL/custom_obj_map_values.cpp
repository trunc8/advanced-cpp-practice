#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string _name;
    int _age;
public:
    Person()
        : _name(""), _age(0) {

    }
    Person(string name, int age) 
        : _name(name), _age(age) {
    }
    void print() {
        cout << _name << ": " << _age << endl;
    }
    Person(const Person &other) {
        _name = other._name;
        _age = other._age;
        cout << "Copy constructor running" << endl;
    }
};

int main() {    
    map<int, Person> people;

    // Needs default constructor
    people[1] = Person("Tintin", 25);
    people[2] = Person("Bruno", 45);
    people[3] = Person("Kailash", 15);

    // Needs copy constructor
    pair<int, Person> pair1 = make_pair(12, Person("Bob", 24)); // copy called once
    people.insert(pair1); // copy called again
    people.insert(make_pair(13, Person("Sue", 44))); // effectively copy called twice

    for (map<int, Person>::iterator it=people.begin(); it!=people.end(); it++) {
        cout << it -> first << ": " << flush;
        it -> second.print();
    }

    return 0;
}
