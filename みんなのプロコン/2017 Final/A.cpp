#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[100005][10];
string T = "yahoo";

int main()
{
    string S;
    cin >> S;
    ll N = S.length();
    ll M = T.length();
    memset(dp, 0, sizeof(dp));
    REP(i, M)
    {
        dp[0][i] = i;
    }
    REP(i, N)
    {
        REP(j, M)
        {
            dp[i + 1][j + 1] = std::min(dp[i][j + 1], dp[i][j]) + 1;
            if (S[i] == T[j])
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }
        dp[i + 1][0] = dp[i + 1][M];
        REP(j, M)
        {
            dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
        }
        dp[i + 1][0] = dp[i + 1][M];
    }

    ll min = INF;
    REP(i, M)
    {
        min = std::min(min, dp[N][i] + (M - i) % M);
    }
    cout << min << endl;
    return 0;
}