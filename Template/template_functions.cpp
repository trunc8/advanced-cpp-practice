#include <iostream>
using namespace std;

template<typename T, typename K>
void printDivide(T num1, K num2) {
    cout << num1/num2 << endl;
}

int main() {
    printDivide(2.,4);
    printDivide<>(2,4);
    printDivide<int>(2,4);
    printDivide<double>(2,4);
    return 0;
}
