#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[25];
ll dp[50005][30];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> C[i];
    }

    REP(i, N + 1)
    {
        REP(j, M + 1)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP(i, M)
    {
        REP(j, N + 1)
        {
            dp[j][i + 1] = dp[j][i];
            if (j - C[i] >= 0)
                dp[j][i + 1] = std::min(dp[j][i + 1], dp[j - C[i]][i + 1] + 1);
            //cout<<j<<" "<<i<<" "<<dp[j][i+1]<<endl;
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}