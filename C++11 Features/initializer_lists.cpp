#include <iostream>
#include <initializer_list>
using namespace std;

class Test {
public:
    Test(initializer_list<string> texts) {
        for (auto &s: texts) {
            cout << s << endl;
        }
    }
    void print(initializer_list<string> texts) {
        for (auto &s: texts) {
            cout << s << endl;
        }
    }
};

int main() {
    Test test{"one", "two", "three"};
    test.print({"1", "2", "3", "4", "5"});
    
    return 0;
}
