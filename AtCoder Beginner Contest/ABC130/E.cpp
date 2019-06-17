#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[10000];
ll T[10000];

ll dp[2005][2005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> S[i];
    }
    REP(i, M)
    {
        cin >> T[i];
    }
    memset(dp, 0, sizeof(dp));
    //! 空文字列同士ok
    REP(i, std::max(N, M) + 1)
    {
        dp[i][0] = dp[0][i] = 1;
    }
    REP(i, N)
    {
        REP(j, M)
        {
            dp[i + 1][j + 1] = MOD + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            if (S[i] == T[j])
            {
                dp[i + 1][j + 1] += dp[i][j];
            }
            dp[i + 1][j + 1] %= MOD;
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}