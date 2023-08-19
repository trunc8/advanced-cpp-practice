#ifndef RING_H_
#define RING_H_

#include <iostream>

using namespace std;

template<typename T>
class ring {

private:
    int m_size;
    int m_pos;
    T *m_values;

public:
    class iterator;

public:
    ring(int size) :
            m_size(size), m_pos(0), m_values(nullptr) {
        m_values = new T[size];
    }

    ring(const ring& other) : m_size(other.m_size),
                              m_pos(other.m_pos),
                              m_values(nullptr) {
        m_values = new T[m_size];
        for (int i=0; i<m_size; i++) {
            m_values[i] = other.m_values[i];
        }
    }

    ring operator=(const ring& other) {
        if (this != &other) { // comparing pointer addresses
            m_size = other.m_size;
            m_pos = other.m_pos;
            delete [] m_values;
            m_values = new T[m_size];
            for (int i=0; i<m_size; i++) {
                m_values[i] = other.m_values[i];
            }
        }

        return *this;
    }

    ~ring() {
        delete [] m_values;
    }

    int size() {
        return m_size;
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T value) {
        m_values[m_pos] = value;
        m_pos = (m_pos+1)%m_size;
    }

    T& get(int pos) {
        if (pos < m_size) {
            return m_values[pos];
        } else {
            cout << "Out of bounds. Returning last element" << endl;
            return m_values[m_size-1];
        }
    }
};


template<typename T>
class ring<T>::iterator {
private:
    int m_pos;
    ring m_ring;
public:
    iterator(int pos, ring& ring_obj) : m_pos(pos), m_ring(ring_obj) {

    }

    iterator& operator++() { // Prefix
        m_pos++;
        return *this;
    }

    iterator operator++(int) { // Postfix
        iterator old = *this;
        // return iterator(m_pos+1, m_ring);
        // m_pos++;
        ++(*this);
        return old;
    }

    bool operator==(const iterator& other) const {
        return m_pos == other.m_pos;
    }

    bool operator!=(const iterator& other) const {
        // cout << "Equality test: " << m_ring.m_values << "\t" << other.m_ring.m_values << endl;
        // return (m_ring.m_values != other.m_ring.m_values) ||
        //     (m_pos != other.m_pos);
        // return m_ring.m_values + m_pos != other.m_ring.m_values + other.m_pos;
        return !(*this==other);
    }

    T& operator*() {
        return m_ring.get(m_pos);
    }
};

#endif /* RING_H_ */



