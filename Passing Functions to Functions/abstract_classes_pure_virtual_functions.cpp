#include <iostream>
using namespace std;

class Animal {
public:
    int legs, hands;
    virtual void speak() = 0;
    virtual void run() = 0;
    virtual void color() = 0;
};

class Dog: public Animal {
public:
    Dog() {
        legs = 4;
        hands = 0;
    }
    void speak() {
        cout << "Bark" << endl;
    }
    virtual void run() {
        cout << "Dog running" << endl;
    }
};

class Retriever: public Dog {
public:
    void color() {
        cout << "Golden retriever" << endl;
    }
    void run() {
        cout << "Retriever running" << endl;
    }
};

void test(Animal &a) {
    a.run();
}

int main() {
    Retriever retriever;
    cout << retriever.hands << endl;
    retriever.run();
    retriever.speak();
    retriever.color();

    Animal *animals[5];
    animals[0] = &retriever;
    // same as: *animals = &retriever;
    animals[0]->run();

    test(retriever);

    return 0;
}
