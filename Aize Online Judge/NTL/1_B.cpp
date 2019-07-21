#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N, M;
    cin >> M >> N;

    ll ans = 1;
    ll m = M;
    REP(i, 40)
    {
        if (((N >> i) & 1) == 1)
            ans = (ans * m) % MOD;
        m = (m * m) % MOD;
    }
    cout << ans % MOD << endl;

    return 0;
}