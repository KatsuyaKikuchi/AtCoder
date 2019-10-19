#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll solve(ll n, ll d)
{
    ll a = d;
    ll s = 0;
    REP(i, n - 1)
    {
        s += 127;
        a ^= 127;
    }
    return s + a;
}

int main()
{
    ll T;
    cin >> T;
    REP(i, T)
    {
        ll n, d;
        cin >> n >> d;
        cout << solve(n, d) << endl;
    }
    return 0;
}