/**
 * http://beet-aizu.hatenablog.com/entry/2019/03/12/171221
 */
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template <typename T>
struct SegmentTree
{
    using F = function<T(T, T)>;
    int n;
    F f;
    T ti;
    vector<T> dat;
    SegmentTree(){};
    SegmentTree(F f, T ti) : f(f), ti(ti) {}
    void init(int n_)
    {
        n = 1;
        while (n < n_)
            n <<= 1;
        dat.assign(n << 1, ti);
    }

    void build(const vector<T> &v)
    {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    // v[k] = x (0-indexed)
    void set(int k, T x)
    {
        dat[k += n] = x;
        while (k >>= 1)
            dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }

    // get F(v[a], v[a + 1], ... , v[b - 1]) (0-indexed)
    T query(int a, int b)
    {
        T vl = ti, vr = ti;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                vl = f(vl, dat[l++]);
            if (r & 1)
                vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
};

int main() {
    SegmentTree<int> segtree(
        [](int a, int b){return a + b;},
        0
    );
    vector<int> a({1, 2, 3, 4, 5});
    segtree.build(a);
    segtree.set(0, 2);
    cout << segtree.query(0, 1) << endl;
    return 0;
}