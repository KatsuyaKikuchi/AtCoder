#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[105][100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    memset(dp, 0, sizeof(dp));
    REP(i = 1; i * i <= N; ++i)
    {
        dp[1][i] = 1;
    }
    FOR(i, K, 1)
    {
    }

    return 0;
}