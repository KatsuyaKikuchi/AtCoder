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
    ll X, Y;
    cin >> X >> Y;
    ll ans = 0;
    if (X == 1)
        ans += 300000;
    else if (X == 2)
        ans += 200000;
    else if (X == 3)
        ans += 100000;
    if (Y == 1)
        ans += 300000;
    else if (Y == 2)
        ans += 200000;
    else if (Y == 3)
        ans += 100000;

    if (X == 1 && Y == 1)
        ans += 400000;
    cout << ans << endl;
    return 0;
}