#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

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
    //! i番目の素数を取得
    int get(int i)
    {
        return mPrimeList[i];
    }
    vector<int> mPrimeList;
};

int P[105] = {0};

int main()
{
    int N;
    cin >> N;
    PrimeList pl;
    pl.init(N);

    FOR(i, N + 1, 2)
    {
        int n = i;
        int j = 0;
        while (n > 1)
        {
            if (n % pl.get(j) == 0)
            {
                P[pl.get(j)]++;
                n /= pl.get(j);
                continue;
            }
            ++j;
        }
    }

    int sum = 0;
    //! a^74で構成される数
    REP(i, N + 1)
    {
        if (P[i] >= 74)
            sum++;
    }
    //! a^2*b^24で構成される数
    REP(i, N + 1)
    {
        REP(j, N + 1)
        {
            if (i == j)
                continue;
            if (P[i] >= 2 && P[j] >= 24)
                sum++;
        }
    }
    //! a^4*b^14で構成される数
    REP(i, N + 1)
    {
        REP(j, N + 1)
        {
            if (i == j)
                continue;
            if (P[i] >= 4 && P[j] >= 14)
                sum++;
        }
    }
    //! a^2*b^4*c^4で構成される数
    REP(i, N + 1)
    {
        REP(j, N + 1)
        {
            FOR(k, N + 1, j + 1)
            {
                if (j == i || k == i)
                    continue;
                if (P[i] >= 2 && P[j] >= 4 && P[k] >= 4)
                    sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}