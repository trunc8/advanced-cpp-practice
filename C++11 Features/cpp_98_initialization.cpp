#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1,2,3,4,5};
    cout << numbers[0] << endl;

    struct S {
        string text;
        int id;
    };

    S s1 = {"Hello", 7};
    cout << s1.text << endl;

    struct {
        string text;
        int id;
    } r1 = {"Unnamed", 10}, r2 = {"Unnamed2", 19};

    cout << r1.id << "\t" << r2.id << endl;
    
    return 0;
}
