#include <iostream>
using namespace std;

// Compiler error
// void greetFunction(void (*pGreet)(string)) {
//     pGreet("Alice");
// }

void greetFunction(auto pGreet) {
    pGreet("Alice");
}

void test_mod_mod(int (*pMod)(int, int), int a, int b) {
    cout << pMod(a,b) << endl;
}

int main() {
    int id = 81;
    auto greet = [&](string name){
        id = 80;
        cout << "Hello " << name << endl;
    };
    cout << "ID: " << id << endl;

    greetFunction(greet);
    cout << "ID: " << id << endl;


    auto modified_modulo = [](int a, int b) -> int {
        if (b==0) {
            return 'A';
        }
        return (a%b)*2.f;
    };

    test_mod_mod(modified_modulo, 10, 7);
    test_mod_mod(modified_modulo, 10, 0);

    return 0;
}
