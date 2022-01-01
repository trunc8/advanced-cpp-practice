#include <iostream>
using namespace std;

void mightGoWrong () {
    bool float_error = 0;
    bool primitive_string_error = 1;
    bool string_error = 1;
    if (float_error) 
        throw 8.8f;
    else if (primitive_string_error) 
        throw "Something went wrong";
    else if (string_error) 
        throw string("Something else went wrong");
}

int main() {
    try {
        mightGoWrong();
    }
    catch (float e) {
        cout << "Error code: " << e << endl;
    }
    catch (char const *e) {
        cout << "Error message: " << e << endl;
    }
    catch (string &e) {
        cout << "string error: " << e << endl;
    }
    cout << "Still running" << endl;
    return 0;
}
