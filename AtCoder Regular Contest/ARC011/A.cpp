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
    ll m, n, N;
    cin >> m >> n >> N;
    ll ans = N;
    ll M = N;
    while (M >= m)
    {
        ll t = M / m;
        M -= t * (m - n);
        ans += t * n;
    }
    cout << ans << endl;
    return 0;
}