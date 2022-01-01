#include <iostream>
#include <set>
using namespace std;

class Person {
private:
    string _name;
    int _age;
public:
    Person(string name, int age) 
        : _name(name), _age(age) {
    }
    void print() const {
        cout << _name << ": " << _age << flush;
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
    set<int> numbers;

    numbers.insert(4);
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(1);
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);

    for (set<int>::iterator it=numbers.begin(); it!=numbers.end(); it++) {
        cout << *it << endl;
    }

    set<Person> people;

    people.insert(Person("Tintin", 225));
    people.insert(Person("Tintin", 25));
    people.insert(Person("Kailash", 15));
    people.insert(Person("Kailash", 25));
    people.insert(Person("Bruno", 45));

    for (set<Person>::iterator it=people.begin(); it!=people.end(); it++) {
        (*it).print();
        cout << endl;
    }


    

    return 0;
}
