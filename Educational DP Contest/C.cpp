#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [i日めに][a/b/cを選んだときの]=幸福度最大値
ll dp[100005][3];

int main()
{
    int N;
    cin >> N;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    REP(i, N)
    {
        REP(j, 3)
        {
            int n;
            cin >> n;
            REP(k, 3)
            {
                if (j == k)
                    continue;
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][k] + n);
            }
        }
    }
    ll max = 0;
    REP(i, 3)
    {
        max = std::max(max, dp[N][i]);
    }
    cout << max << endl;
    return 0;
}