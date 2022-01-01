#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> numbers(3);

    cout << "Size: " << numbers.size() << endl;
    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;
    
    for (int i=1; i<=10000; i++) {
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << capacity << endl;
        }
        numbers.push_back(i);
    }

    numbers.resize(100);
    cout << numbers[200] << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;


    return 0;
}
