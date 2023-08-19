#include <iostream>
using namespace std;

struct Check {
    int max_size = 2;
    int curr_size = 0;
    virtual bool operator()(int i)=0;
};

struct SizeCheck: public Check {
    bool operator()(int i) {
        if (i==1) {
            curr_size++;
        } else if (i==-1) {
            curr_size--;
        }
        return (curr_size < max_size);
    }
};

void addElement (int i, Check &functor) {
    bool ret = functor(i);
    if (!ret) {
        cout << "Overfull" << endl;
    } else {
        cout << "Not full. Slots left: " << 
            functor.max_size - functor.curr_size
             << endl;
    }
}

int main() {
    SizeCheck size_check_obj;
    addElement(1, size_check_obj);
    addElement(1, size_check_obj);
    addElement(-1, size_check_obj);
    addElement(-1, size_check_obj);
    return 0;
}
