#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool B[100005];
ll dp[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    memset(B, 0, sizeof(B));
    REP(i, M)
    {
        ll a;
        cin >> a;
        B[a] = true;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    REP(i, N)
    {
        if (B[i + 1])
            continue;
        dp[i + 1] += dp[i];
        if (i > 0)
            dp[i + 1] += dp[i - 1];
        dp[i + 1] %= MOD;
    }
    cout << dp[N] << endl;
    return 0;
}