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
    PrimeList(ll n)
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

int main()
{
    ll A, B;
    cin >> A >> B;
    PrimeList pl(100005);
    vector<ll> v(pl.mPrimeList.size(), 0);
    FOR(i, A + 1, B + 1)
    {
        ll n = i;
        REP(j, pl.mPrimeList.size())
        {
            ll num = 0;
            while (n % pl.get(j) == 0)
            {
                num++;
                n /= pl.get(j);
            }
            v[j] += num;
        }
        if (n > 1)
            v.push_back(1);
    }
    ll ans = 1;
    REP(i, v.size())
    {
        ans = (ans * (v[i] + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}