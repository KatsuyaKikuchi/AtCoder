#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[105][30];
ll A[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[1][A[0]] = 1LL;
    FOR(i, N - 1, 1)
    {
        for (int j = 0; j <= 20; ++j)
        {
            if (j - A[i] >= 0)
                dp[i + 1][j] += dp[i][j - A[i]];
            if (j + A[i] <= 20)
                dp[i + 1][j] += dp[i][j + A[i]];
        }
    }
    cout << dp[N - 1][A[N - 1]] << endl;
    return 0;
}