#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[200005][2];

int main()
{
    string S;
    cin >> S;
    memset(dp, 0, sizeof(dp));
    ll N = S.length();
    REP(i, N)
    {
        dp[i + 1][0] = dp[i][1] + 1;
        if (i - 1 >= 0 && S[i] != S[i - 1])
            dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][0] + 1);

        if (i - 1 >= 0)
            dp[i + 1][1] = dp[i - 1][0] + 1;
        if (i - 3 >= 0 && (S[i] != S[i - 2] || S[i - 1] != S[i - 3]))
            dp[i + 1][1] = std::max(dp[i + 1][1], dp[i - 1][1] + 1);
    }
    ll max = std::max(dp[N][0], dp[N][1]);
    cout << max << endl;

    return 0;
}