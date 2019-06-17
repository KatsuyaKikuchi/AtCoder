#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
pll G[100005];
bool U[100];

ll solve(ll p, ll q)
{
    ll s = 0;
    memset(U, 0, sizeof(U));
    REP(i, N)
    {
        if (U[i])
            continue;
        s++;
        U[i] = true;
        int n = i;
        FOR(j, N, i + 1)
        {
            if (U[j])
                continue;
            if (G[j].first - p == G[n].first && G[j].second - q == G[n].second)
            {
                U[j] = true;
                n = j;
            }
        }
    }
    return s;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
    }
    sort(G, G + N, [](pll a, pll b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });
    ll ans = N;
    REP(i, N)
    {
        REP(j, N)
        {
            if (i == j)
                continue;

            ll p = G[i].first - G[j].first;
            ll q = G[i].second - G[j].second;
            if (p == 0 && q == 0)
                continue;

            ll s = solve(p, q);
            ans = std::min(ans, s);
        }
    }

    cout << ans << endl;
    return 0;
}