#include <iostream>

using namespace std;

template <int MAX>
class Combination
{
  public:
    Combination()
    {
        for (int i = 0; i < MAX; ++i)
        {
            comb[0][i] = 0;
            comb[i][0] = 1;
        }
        for (int i = 1; i < MAX; ++i)
        {
            for (int j = 1; j < MAX; ++j)
            {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }
    }

    long long get(int n, int k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return comb[n][k];
    }

  private:
    long long comb[MAX][MAX];
};

template <int MAX, int MOD>
class ModCombination
{
  public:
    ModCombination()
    {
        fac[0] = fac[1] = 1;
        facinv[0] = facinv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            facinv[i] = facinv[i - 1] * inv[i] % MOD;
            cout << fac[i] << " " << inv[i] << " " << facinv[i] << endl;
        }
    }

    long long get(int n, int k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (facinv[k] * facinv[n - k] % MOD) % MOD;
    }

  private:
    long long fac[MAX];
    long long facinv[MAX];
    long long inv[MAX];
};
