#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll solve(ll a, ll b)
{
    return 0;
}

int main()
{
    ll Q;
    cin >> Q;
    REP(q, Q)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}