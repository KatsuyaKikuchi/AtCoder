#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[100005];
//! [足場iに行くまでの]=最小コスト
ll dp[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i + 1];
    }
    H[0] = H[1];

    dp[0] = dp[1] = 0;
    FOR(i, N + 1, 2)
    {
        dp[i] = std::min(dp[i - 1] + abs(H[i] - H[i - 1]), dp[i - 2] + abs(H[i] - H[i - 2]));
    }
    cout << dp[N] << endl;
    return 0;
}