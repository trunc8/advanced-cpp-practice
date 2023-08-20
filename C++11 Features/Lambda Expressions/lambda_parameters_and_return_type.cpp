#include <iostream>
using namespace std;

// We can declare a lambda outside
auto greet = [](string name){
    int id = 80;
    cout << "Hello " << name << endl;
};

void greetFunction(decltype(greet) pGreet) {
    pGreet("Alice");
}

void test_mod_mod(int (*pMod)(int, int), int a, int b) {
    cout << pMod(a,b) << endl;
}

int main() {
    int id = 81;

    // Works
    // auto greet = [&](string name){
    //     id = 80;
    //     cout << "Hello " << name << endl;
    // };

    /***
     * Doesn't work because its special lambda features can't be matched
     * by a function pointer, e.g, stuff inside [], mutable, etc.
    
    void (*greet)(string) = [&](string name) -> void {
        id = 80;
        cout << "Hello " << name << endl;
    };

    */
    cout << "ID: " << id << endl;

    greetFunction(greet);

    cout << "ID: " << id << endl;


    // Both versions work

    // auto modified_modulo = [](int a, int b) -> int {
    //     if (b==0) {
    //         return 'A';
    //     }
    //     return (a%b)*2.f;
    // };

    int (*modified_modulo)(int, int) = [](int a, int b) -> int {
        if (b==0) {
            return 'A';
        }
        return (a%b)*2.f;
    };

    test_mod_mod(modified_modulo, 10, 7);
    test_mod_mod(modified_modulo, 10, 0);

    return 0;
}
