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
    auto n_vec = {1,2,3,4};
    initializer_list<int> n_vec2 = {1,2,3,4};
    int n_arr[] {1,2,3,4};
    cout << typeid(numbers).name() << endl;
    cout << typeid(n_vec).name() << endl;
    cout << typeid(n_vec2).name() << endl;
    cout << typeid(n_arr).name() << endl;

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
