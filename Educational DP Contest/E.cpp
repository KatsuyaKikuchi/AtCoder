#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [i番目まで見たとき][価値がvとなるような]=重さの最小値
ll dp[105][100005];

int main()
{
    ll N, W;
    cin >> N >> W;
    REP(i, 100005)
    {
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    REP(i, N)
    {
        ll w, v;
        cin >> w >> v;
        REP(j, 100005)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - v < 0)
                continue;
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j - v] + w);
        }
    }

    ll max = 0;
    REP(i, 100005)
    {
        if (dp[N][i] > W)
            continue;
        max = std::max(max, i);
    }

    cout << max << endl;
    return 0;
}