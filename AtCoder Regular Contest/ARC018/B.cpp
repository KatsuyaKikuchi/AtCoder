#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll G[105];

bool solve(ll a, ll b, ll c)
{
    pll n = pll(G[b].first - G[a].first, G[b].second - G[a].second);
    pll m = pll(G[c].first - G[a].first, G[c].second - G[a].second);

    ll S = abs(n.first * m.second - n.second * m.first);
    return S % 2 == 0 && S != 0;
}

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
    }

    ll ans = 0;
    REP(a, N)
    {
        FOR(b, N, a + 1)
        {
            FOR(c, N, b + 1)
            {
                if (solve(a, b, c))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}