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

    // calculate sum a[0] + a[1] + ... + a[i - 1]
    T sum (int i) {
        assert(0 <= i && i < n + 1);
        //i++;
        T s = 0;
        while(i > 0) {
            s += v[i - 1];
            i -= i & -i;
        }
        return s;
    }

    // calculate sum a[i] + a[i + 1] + ... + a[j - 1]
    T sum (int i, int j) {
        return sum(j) - sum(i);
    }

    void add(int i, T x) {
        assert(0 <= i && i < n);
        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += i & -i;
        }
    }

    void dump() {
        int i = 1;
        for (T vi : v) {
            cout << vi << "(" << (i & (-i)) << ") ";
            ++i;
        }
        cout << endl;
    }
};
