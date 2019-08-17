#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll D[105];
ll dp[105][100005];

int main()
{
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    REP(i, N)
    {
        cin >> D[i];
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N)
    {
        REP(j, 100005)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - B >= 0)
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - B] + D[i]);
        }
    }
    ll max = 0;
    FOR(i, 100005, A)
    {
        max = std::max(max, (dp[N][i - A] + C) / i);
    }
    cout << max << endl;
    return 0;
}