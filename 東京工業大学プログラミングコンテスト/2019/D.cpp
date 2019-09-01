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

bool P[1000005];

int main()
{
    ll N;
    cin >> N;
    PrimeList pl(1000005);
    memset(P, 0, sizeof(P));
    REP(i, pl.mPrimeList.size())
    {
        P[pl.get(i)] = true;
    }
    ll x = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        ll n = 1;
        while (P[a - 2])
        {
            n++;
            a -= 2;
        }
        x ^= n;
    }

    if (x == 0)
        cout << "Ai" << endl;
    else
        cout << "An" << endl;
    return 0;
}