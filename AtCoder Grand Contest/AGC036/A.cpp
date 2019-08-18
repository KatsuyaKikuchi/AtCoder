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
    ll S;
    pll g[3];
    g[0].first = 0;
    g[0].second = 0;

    cin >> S;
    ll sq = (ll)std::ceil(sqrt(S));

    g[1].first = sq;
    g[2].second = sq;
    ll a = sq * sq - S;
    g[1].second = a;
    g[2].first = 1;

    REP(i, 3)
    {
        cout << g[i].first << " " << g[i].second << " ";
    }
    cout << endl;
    return 0;
}