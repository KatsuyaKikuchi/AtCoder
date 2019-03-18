#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, S;

ll func(ll b, ll n)
{
    if (n < b)
    {
        return n;
    }
    return func(b, n / b) + n % b;
}

int main()
{
    cin >> N >> S;
    if (N == 1)
    {
        if (S == 1)
            cout << 2 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    ll i = 2;
    //! sqrt(N)はまでは直で計算
    for (; i * i <= N; ++i)
    {
        if (func(i, N) == S)
        {
            cout << i << endl;
            return 0;
        }
    }

    //! ここからは2桁の数、商で分類
    for (ll j = i; j > 1; --j)
    {
        ll min = N / j + 1;
        ll max = N / (j - 1);
        ll upper = func(min, N);
        ll lower = func(max, N);
        if (upper >= S && S >= lower)
        {
            if ((upper - S) % (j - 1) == 0)
            {
                cout << min + (upper - S) / (j - 1) << endl;
                return 0;
            }
        }
    }

    if (N == S)
        cout << N + 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}