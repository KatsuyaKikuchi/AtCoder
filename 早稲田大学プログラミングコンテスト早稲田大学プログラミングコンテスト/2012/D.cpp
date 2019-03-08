#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105][105];
ll dp[105][105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        REP(j, i + 1)
        {
            cin >> A[i][j];
        }
    }

    dp[0][0] = A[0][0];
    FOR(i, N, 1)
    {
        REP(j, i + 1)
        {
            ll m = 0;
            for (int k = -1; k <= 0; ++k)
            {
                if (j + k < 0)
                    continue;
                m = std::max(m, dp[i - 1][j + k]);
            }
            dp[i][j] = m + A[i][j];
        }
    }

    ll max = 0;
    REP(i, N)
    {
        max = std::max(max, dp[N - 1][i]);
    }
    cout << max << endl;

    return 0;
}