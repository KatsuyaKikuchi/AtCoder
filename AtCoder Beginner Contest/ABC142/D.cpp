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

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main()
{
    ll A, B;
    cin >> A >> B;

    ll m = gcd(A, B);
    PrimeList pl(1000005);

    vector<pll> v;
    REP(i, pl.mPrimeList.size())
    {
        if (m <= 1)
            break;
        ll pr = pl.get(i);
        pll p(pr, 0);
        ll n = 0;
        while (m % pr == 0)
        {
            m /= pr;
            p.second++;
        }
        if (p.second > 0)
        {
            v.push_back(p);
        }
    }
    if (m > 1)
    {
        pll p(m, 1);
        v.push_back(p);
    }

    ll ans = 1 + v.size();

    cout << ans << endl;

    return 0;
}