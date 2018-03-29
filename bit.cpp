/*
Implementation of Binary Indexed Tree (BIT)

Nodes of the array are 0-indexed

Unverifyed
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class BIT {
private:
    vector<T> v;
    const int n;

public:
    BIT(int _n) : v(_n + 1, 0), n(_n) {}

    // a[0] + a[1] + ... + a[i - 1]
    // O(log n)
    T sum (int i) {
        assert(0 <= i && i < n + 1);
        T s = 0;
        while(i > 0) {
            s += v[i - 1];
            i -= i & -i;
        }
        return s;
    }

    // a[i] + a[i + 1] + ... + a[j - 1]
    // O(log n)
    T sum (int i, int j) {
        return sum(j) - sum(i);
    }

    // a[i] += x
    // O(log n)
    void add(int i, T x) {
        assert(0 <= i && i < n);
        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += i & -i;
        }
    }

};
