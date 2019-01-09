#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
//! [i番目までの薬品しかない時の]=効用の和の最大値
ll dp[200005];
ll m[200005];

int main()
{
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    dp[0] = m[0] = 0;
    REP(i, N)
    {
        dp[i + 1] = dp[i] + A[i];
        if (i - (K - 1) >= 0)
        {
            dp[i + 1] = std::max(dp[i + 1], m[i - (K - 1)]);
        }
        m[i + 1] = std::max(m[i], dp[i + 1]);
    }
    cout << dp[N] << endl;
    return 0;
}