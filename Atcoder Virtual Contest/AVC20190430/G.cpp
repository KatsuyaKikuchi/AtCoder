#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[200005];
ll dp[200005];
ll M[200005];

int main()
{
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> B[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(M, 0, sizeof(M));
    REP(i, N)
    {
        dp[i + 1] = dp[i] + B[i];
        if (i + 1 >= K)
        {
            dp[i + 1] = std::max(dp[i + 1], M[i + 1 - K]);
        }
        M[i + 1] = std::max(M[i], dp[i + 1]);
    }
    cout << dp[N] << endl;
    return 0;
}