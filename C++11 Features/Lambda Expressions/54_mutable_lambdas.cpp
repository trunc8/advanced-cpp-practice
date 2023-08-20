#include<iostream>
using namespace std;

int main() {
    int val1 = 5;
    int val2 = 10;

    auto pFunc = [=, &val2]() mutable {
        val1 = 500; // Doesn't throw error because of mutable!
        val2 = 1000;
        cout << "Finished running lambda" << endl;
    };

    cout << val1 << ", " << val2 << endl;
    pFunc();
    cout << val1 << ", " << val2 << endl;
}