#include <iostream>
#include <exception>
using namespace std;

void mightGoWrong () {
    bool error1 = 1;
    bool error2 = 0;
    if (error1) 
        throw bad_alloc();
    else if (error2) 
        throw exception();
}

int main() {
    try {
        mightGoWrong();
    }
    catch (exception &e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (bad_alloc &e) {
        cout << "Caught bad_alloc: " << e.what() << endl;
    }
    cout << "Still running" << endl;
    return 0;
}
