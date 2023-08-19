#include <iostream>
using namespace std;

class Test {
    int id {4};
    string name {"Anonymous"};
public:
    Test() = default;
    Test(const Test&) = delete;
    Test& operator=(const Test&) = delete;

    Test(int id): id(id) {}

    friend ostream& operator<<(ostream&, const Test&);
};

ostream& operator<<(ostream& out, const Test& test) {
    out << test.id << ": " << test.name << flush;
    return out;
}

int main() {

    Test t1;
    cout << "T1: " << t1 << endl;

    // Test t2 = t1; //won't work
    // cout << "T2: " << t2 << endl;

    Test t3(19);
    cout << "T3: " << t3 << endl;
    // t3 = t2; //won't work

    // cout << "T3: " << t3 << endl;
    
    return 0;
}
