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
    }
};

int main() {    
    multimap<int, Person> people;

    people.insert(make_pair(10, Person("Sue", 44)));
    people.insert(make_pair(30, Person("Eic", 75)));
    people.insert(make_pair(20, Person("Pu", 22)));
    people.insert(make_pair(20, Person("Bob", 334)));

    for (multimap<int, Person>::iterator it=people.begin(); it!=people.end(); it++) {
        cout << it -> first << ": " << flush;
        it -> second.print();
    }

    cout << endl;

    pair<multimap<int, Person>::iterator, multimap<int, Person>::iterator> its = 
        people.equal_range(20);
    for (multimap<int, Person>::iterator it=its.first; it!=its.second; it++) {
        cout << it -> first << ": " << flush;
        it -> second.print();
    }

    return 0;
}
