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
    ll M, D;
    cin >> M >> D;
    ll ans = 0;
    REP(i, M)
    {
        REP(j, D)
        {
            ll m = i + 1;
            ll d = j + 1;
            ll d1 = d % 10;
            ll d2 = d / 10;
            if (d1 >= 2 && d2 >= 2 && d1 * d2 == m)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}