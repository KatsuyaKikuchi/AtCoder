#include "base.hpp"

//!エラトステネスの篩で素数リストを構築
struct PrimeList
{
    PrimeList()
    {
        mPrimeList.clear();
    }

    //! nまでの整数リストを構築
    void init(int n)
    {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; ++i)
        {
            if (!isPrime[i])
                continue;
            mPrimeList.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> mPrimeList;
};