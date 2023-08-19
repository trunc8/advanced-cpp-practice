#include <iostream>
using namespace std;

int main() {
    auto one = 1;
    auto two = 2;
    auto three = 3;

    // Capture one and two by value
    [one, two](){
        cout << one << ", " << two << endl;
    }();

    // Default Capture by value
    [=](){
        cout << one << ", " << two << endl;
    }();

    // Default Capture by value, three by reference
    [=, &three](){
        three = 8;
        cout << one << ", " << two << endl;
    }();

    cout << "State: " << one << ", " << two << ", " << three << endl;

    // Default Capture by reference
    [&](){
        two = 4;
        cout << one << ", " << two << endl;
    }();

    cout << "State: " << one << ", " << two << ", " << three << endl;
    return 0;
}
