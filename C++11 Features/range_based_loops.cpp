#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto texts = {"one", "two", "three"};
    // cout << texts[0] << endl;
    for (auto text: texts) {
        cout << text << endl;
    }

    vector<int> numbers = {1,2,3,4,10};
    // vector<int> numbers {1,2,3,4,10}; // works too
    for (auto number: numbers) {
        cout << number << " " << flush;
    }
    cout << endl;

    string name = "Babuka";
    for (auto ch: name) {
        cout << ch <<  " " << flush;
    }
    cout << endl;
    return 0;
}
