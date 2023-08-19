#include <iostream>
#include <vector>
using namespace std;

// int myCountIf(vector<string>::iterator start,
//               vector<string>::iterator end,
//               bool (*match)()) {

// }


int myCount(vector<int>::iterator start,
            vector<int>::iterator end,
            bool (*match)(int)) {
    int matches = 0;
    for (vector<int>::iterator it=start; it!=end; it++) {
        matches += (match(*it));
    }
    return matches;
}

bool isZero(int num) {
    return (num == 0);
}

int main() {
    vector<int> numbers = {0,1,0,2,3,2,5,0,9};

    cout << "Using function pointer for counting 0's: " << flush;
    cout << myCount(numbers.begin(), numbers.end(),
        isZero) << endl;

    cout << "Using lambda functions for counting 2's: " << flush;
    cout << myCount(numbers.begin(), numbers.end(),
        [](int n){return n==2;}) << endl;
        
    return 0;
}
