#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll dp[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    dp[0] = 0;
    REP(i, N - 1)
    {
        dp[i + 1] = dp[i] + abs(A[i] - A[i + 1]);
        if (i > 0)
        {
            dp[i + 1] = std::min(dp[i + 1], dp[i - 1] + abs(A[i + 1] - A[i - 1]));
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}