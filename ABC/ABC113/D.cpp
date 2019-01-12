#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [高さHまで見た時に][左からi番目にたどり着くような]=あみだくじの本数
ll dp[105][10];

int H, W, K;
ll S[30];
//! lからrに横線を引く場合の数
ll get(int l, int r)
{
    if (l > r || l < 0 || r >= W)
        return 1;
    return S[r - l];
}

int main()
{
    cin >> H >> W >> K;
    S[0] = 1;
    S[1] = 2;
    FOR(i, 30, 2)
    {
        S[i] = S[i - 1] + S[i - 2];
    }
    REP(i, 105)
    {
        REP(j, 10)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    REP(i, H)
    {
        REP(j, W)
        {
            //! 左からくる
            if (j > 0)
            {
                ll t = dp[i][j - 1] * get(0, j - 2) * get(j + 1, W - 1);
                dp[i + 1][j] += t % MOD;
                dp[i + 1][j] %= MOD;
            }
            //! そのまま降りる
            {
                ll t = dp[i][j] * get(0, j - 1) * get(j + 1, W - 1);
                dp[i + 1][j] += t % MOD;
                dp[i + 1][j] %= MOD;
            }
            //! 右からくる
            if (j < W - 1)
            {
                ll t = dp[i][j + 1] * get(0, j - 1) * get(j + 2, W - 1);
                dp[i + 1][j] += t % MOD;
                dp[i + 1][j] %= MOD;
            }
        }
    }
    cout << dp[H][K - 1] << endl;
    return 0;
}