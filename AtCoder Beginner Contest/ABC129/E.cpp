#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! 3^n%MOD
ll P[100005];

int main()
{
    string L;
    cin >> L;
    ll N = L.length();

    ll ans = 1;
    REP(i, N)
    {
        ans = (ans * 3LL) % MOD;
    }
    P[0] = 1;
    REP(i, N)
    {
        P[i + 1] = (P[i] * 3LL) % MOD;
    }

    ll t = 1;
    REP(i, N)
    {
        if (L[i] == '1')
        {
            t = (t * 2LL) % MOD;
            continue;
        }

        ans = (ans + MOD - (t * 2LL * P[N - 1 - i]) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}