#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll V[105];
ll U[105];

ll dp[105][10005];

int main()
{
    ll N, W;
    cin >> N >> W;
    ll v = 0;
    REP(i, N)
    {
        cin >> V[i] >> U[i];
        v += V[i];
    }
    REP(i, N + 1)
    {
        REP(j, v + 1)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP(i, N)
    {
        REP(j, v + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - V[i] < 0)
                continue;
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j - V[i]] + U[i]);
        }
    }

    REP(i, v + 1)
    {
        if (dp[N][v - i] > W)
            continue;
        cout << v - i << endl;
        break;
    }
    return 0;
}