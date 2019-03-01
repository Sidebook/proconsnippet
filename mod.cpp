#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long mod(long long a, long long m = MOD)
{
    long long q = a % m;
    if (q < 0)
        q += m;
    return q;
}

long long modadd(long long a, long long b, long long m = MOD)
{
    return (a + b) % m;
}

long long modsub(long long a, long long b, long long m = MOD)
{
    return mod((a % m) - (b % m));
}

long long modmul(long long a, long long b, long long m = MOD)
{
    return (a * b) % m;
}

long long modpow(long long a, long long b, long long m = MOD)
{
    long long c = 1;
    while (b > 0)
    {
        if (b & 1)
            c = modmul(c, a, m);
        a = modmul(a, a, m);
        b >>= 1;
    }
    return c;
}

long long modinv(long long a, long long m = MOD)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        long long tmp;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

long long moddiv(long long a, long long b, long long m = MOD)
{
    return modmul(a, modinv(b, m), m);
}
