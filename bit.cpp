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
    T sum (int i, int j) {
        return sum(j) - sum(i);
    }

    // a[i] += x
    void add(int i, T x) {
        assert(0 <= i && i < n);
        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += i & -i;
        }
    }

};
