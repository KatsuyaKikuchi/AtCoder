#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll S[105];
//! [i番目までで][j個入れた時][重さ-w_1の和がkとなるような]=価値の最大値
ll dp[105][105][405];

int main()
{
    ll N, W;
    cin >> N >> W;
    REP(i, N)
    {
        cin >> S[i].first >> S[i].second;
    }
    ll w1 = S[0].first;
    dp[0][0][0] = 0;
    REP(i, N)
    {
        dp[i + 1][0][0] = 0;
        REP(j, i + 1)
        {
            REP(k, 301)
            {
                if ((j + 1) * w1 + k > W)
                    break;
                if (k - (S[i].first - w1) < 0)
                    dp[i + 1][j + 1][k] = dp[i][j + 1][k];
                else
                    dp[i + 1][j + 1][k] = std::max(dp[i][j + 1][k], dp[i][j][k - (S[i].first - w1)] + S[i].second);
            }
        }
    }

    ll max = 0;
    REP(i, N + 1)
    {
        REP(j, 301)
        {
            max = std::max(dp[N][i][j], max);
        }
    }
    cout << max << endl;
    return 0;
}