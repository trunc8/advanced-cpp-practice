#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> strings;
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    cout << "Printing using square bracket operator:\n";
    for (int i=0; i<strings.size(); i++) {
        cout << strings[i] << endl;
    }

    cout << "Printing using vector iterator:\n";
    for (vector<string>::iterator it=strings.begin(); it!=strings.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
