#include <iostream>
#include <vector>
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
    friend ostream &operator<<(ostream &output, const Person &person) {
        output << person._name << ": " << person._age << endl;
        return output;
    }
};

template<typename T>
class MySet {
private:
    vector<T> my_set;
public:
    MySet() {
        my_set = {};
    }
    void insert(T elem) {
        
        int len = my_set.size();

        if ( len == 0 || my_set[len-1] < elem ) {
            my_set.push_back(elem);
        } 
        else {
            int index = 0;
            while ( !(elem < my_set[index]) ) {
                if ( !(my_set[index] < elem) ) {
                    return;
                }
                index++;
            }

            T prev_elem = elem;
            T next_elem = my_set[index];

            while (index < len-1) {
                my_set[index] = prev_elem;
                prev_elem = next_elem;
                next_elem = my_set[++index];
            }

            my_set[index] = prev_elem;
            my_set.push_back(next_elem);
        }
    }

    void print() {
        for (auto &i: my_set) {
            cout << " " << i;
        }
        cout << endl;
    }

};

int main() {

    MySet<int> numbers;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(10);
    numbers.insert(7);
    numbers.insert(6);
    numbers.insert(-1);
    numbers.print();

    MySet<Person> people;

    people.insert(Person("Tintin", 225));
    people.insert(Person("Tintin", 25));
    people.insert(Person("Kailash", 15));
    people.insert(Person("Kailash", 25));
    people.insert(Person("Bruno", 45));

    people.print();

    return 0;
}
