#include <iostream>
using namespace std;

class Test {
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};
        // auto lambda_func = [=,this](){
        auto lambda_func = [=, &three](){
            one = 10; // this->one = 10;
            three = 30;
            // four = 40; // not allowed as read-only variable
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };

        lambda_func();

        cout << endl;
        cout << one << endl;
        cout << two << endl;
        cout << three << endl;
        cout << four << endl;
    }
};

int main() {
    Test test;
    test.run();
    
    return 0;
}
