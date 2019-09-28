#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll K[10005];
ll dp[1005][5000];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b;
        cin >> K[i].first >> b;
        K[i].second = 0;
        REP(j, b)
        {
            ll c;
            cin >> c;
            K[i].second |= (1LL << (c - 1));
        }
    }

    ll P = pow(2, N);
    REP(i, M + 1)
    {
        REP(j, P)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    REP(i, M)
    {
        REP(j, P)
        {
            dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
            ll s = j | K[i].second;
            dp[i + 1][s] = std::min(dp[i + 1][s], dp[i][j] + K[i].first);
        }
    }

    if (dp[M][P - 1] == INF)
        cout << -1 << endl;
    else
        cout << dp[M][P - 1] << endl;
    return 0;
}