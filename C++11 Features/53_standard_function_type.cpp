#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;


// Functor
class Check{
public:
    bool operator()(string &text){
        return text.size() == 5;
    }
};

bool check1(string &text){
    return text.size() == 4;
}

void test(function<bool(string&)> check){
    string s = "four";
    cout << "Checking if four has size 4: " << check(s) << endl; //  Passing "four" directly won't work!
}

int main() {
    // Standard function type
    function<void(int, int)> pFunc = [](int a, int b){
        cout << "Addition is: " << a+b << endl;
    };
    pFunc(10,3);

    // Passing to standard function type
    test(check1);


    // Recap
    vector<string> vec {"one", "two", "three", "four", "five", "six"};

    int count = count_if(vec.begin(), vec.end(), check1);
    cout << "Count is: " << count << endl;

    auto check2 = [](const string &text){
        return text.size() == 3;
    };
    count = count_if(vec.begin(), vec.end(), check2);
    cout << "Count is: " << count << endl;


    count = count_if(vec.begin(), vec.end(), Check());
    cout << "Count is: " << count << endl;

    // You need the additional () for it to work
    // cout << Check()(vec[0]) << endl;
}