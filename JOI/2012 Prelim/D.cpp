#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 10000;
const ll INF = (ll)1e15;

ll A[105];
ll dp[105][5][5];

int main()
{
    ll N, K;
    cin >> N >> K;
    memset(A, 0, sizeof(A));
    REP(i, K)
    {
        ll n;
        cin >> n;
        cin >> A[n];
    }

    memset(dp, 0, sizeof(dp));
    REP(a, 3)
    {
        if (A[2] != 0 && A[2] != a + 1)
            continue;
        REP(b, 3)
        {
            if (A[1] != 0 && A[1] != b + 1)
                continue;
            dp[2][a][b] = 1;
        }
    }
    FOR(i, N, 2)
    {
        REP(a, 3)
        {
            if (A[i + 1] != 0 && A[i + 1] != a + 1)
                continue;
            REP(b, 3)
            {
                REP(c, 3)
                {
                    if (a == b && b == c)
                        continue;
                    dp[i + 1][a][b] += dp[i][b][c];
                    dp[i + 1][a][b] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 3)
    {
        REP(j, 3)
        {
            ans += dp[N][i][j];
        }
    }
    cout << ans % MOD << endl;
    return 0;
}