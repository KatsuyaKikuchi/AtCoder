#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll solve(ll x, ll y)
{
    if (y < 0)
        return -1;
    if (y % 2 == 1)
        return -1;

    ll z = y / 2;
    if (abs(x) <= z && abs(x) % 2 == z % 2)
        return z;
    return -1;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}