#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[1005];
//! [h][w]=まで行くまでの組み合わせすう
ll dp[1005][1005];

int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> M[i];
    }

    REP(i, 1000)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    dp[1][1] = 1;
    REP(h, H)
    {
        REP(w, W)
        {
            if (h == 0 && w == 0)
                continue;
            if (M[h][w] == '#')
            {
                dp[h + 1][w + 1] = 0;
                continue;
            }
            dp[h + 1][w + 1] = dp[h + 1][w] + dp[h][w + 1];
            dp[h + 1][w + 1] %= MOD;
        }
    }
    cout << dp[H][W] << endl;
    return 0;
}