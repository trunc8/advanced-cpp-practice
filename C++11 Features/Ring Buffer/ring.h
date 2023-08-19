#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ring {
private:
    int m_size;
    int m_pos;
    T *m_values;
public:
    class iterator;

    ring(int size) : m_size(size), m_pos(0), m_values(NULL) {
        m_values = new T[size];
    }

    ~ring() {
        delete [] m_values;
    }

    void add(T value) {
        m_values[m_pos] = value;
        m_pos = (m_pos+1)%m_size;
    }

    T get(int pos) {
        if (pos < m_size) {
            return m_values[pos];
        } else {
            cout << "Out of bounds. Returning last element" << endl;
            return m_values[m_size-1];
        }
    }

    int size() {
        return m_size;
    }
};


template<typename T>
class ring<T>::iterator {
public:
    void print() {
        cout << "Inside iterator class: " << T() << endl;
    }
};
