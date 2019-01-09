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
    ll C, D;
    cin >> C >> D;

    ll sum = 0;
    ll b = 140, t = 170;
    while (b < D)
    {
        ll bottom = std::max(b, C);
        ll top = std::min(t, D);
        sum += std::max((ll)0, top - bottom);
        b *= 2;
        t *= 2;
    }
    cout << sum << endl;
    return 0;
}