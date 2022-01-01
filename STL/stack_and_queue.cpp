#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test() : 
        name("") {
    }
    Test(string name) :
        name(name) {
    }
    void print() {
        cout << name << flush;
    }

};

int main() {

    // LIFO
    stack<Test> testStack;
    testStack.push(Test("Tintin"));
    testStack.push(Test("Tintin"));
    testStack.push(Test("Kailash"));
    testStack.push(Test("Bruno"));

    while (testStack.size()) {
        Test &person = testStack.top();
        cout << testStack.size() << " ";
        person.print();
        cout << endl;
        testStack.pop();
    }

    cout << endl;

    // FIFO
    queue<Test> testQueue;
    testQueue.push(Test("Tintin"));
    testQueue.push(Test("Tintin"));
    testQueue.push(Test("Kailash"));
    testQueue.push(Test("Bruno"));

    testQueue.back().print();
    cout << endl << endl;

    while (testQueue.size()) {
        Test &person = testQueue.front();
        cout << testQueue.size() << " ";
        person.print();
        cout << endl;
        testQueue.pop();
    }



    return 0;
}
