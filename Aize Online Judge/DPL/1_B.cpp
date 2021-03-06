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
    REP(i, N)
    {
        cin >> V[i] >> U[i];
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N)
    {
        REP(j, W + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - U[i] >= 0)
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - U[i]] + V[i]);
        }
    }

    ll max = 0;
    REP(i, W + 1)
    {
        max = std::max(max, dp[N][i]);
    }
    cout << max << endl;
    return 0;
}