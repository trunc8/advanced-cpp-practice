#include <iostream>
using namespace std;

class Test {
private:
    string name;
    int id;
public:
    Test() : id(0), name(""){
    }
    Test(int id, string name) :
        id(id), name(name) {
    }
    friend ostream &operator<<(ostream &out, const Test &test) {
        out << test.id << ": " << test.name;
        return out;
    }
};

int main() {
    Test t1(10, "Micky");
    Test t2(22, "Kyara");
    cout << t1 << " " << t2 << endl;

    return 0;
}
