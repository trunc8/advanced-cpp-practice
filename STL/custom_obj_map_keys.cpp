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
    void print() const {
        cout << _name << ": " << _age << flush;
    }
    Person(const Person &other) {
        _name = other._name;
        _age = other._age;
    }
    bool operator<(const Person &other) const {
        if (_name == other._name) {
            return _age < other._age;
        } else {
            return _name < other._name;
        }
    }
};


int main() {    
    map<Person, int> people;

    people[Person("Tintin", 225)] = 225;
    people[Person("Tintin", 25)] = 25;
    people[Person("Kailash", 15)] = 15;
    people[Person("Bruno", 45)] = 45;


    for (map<Person, int>::iterator it=people.begin(); it!=people.end(); it++) {
        cout << it -> second << ": " << flush;
        it -> first.print();
        cout << endl;
    }

    return 0;
}
