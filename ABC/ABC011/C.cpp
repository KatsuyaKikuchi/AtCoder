#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool dp[105][305];

int main()
{
    ll N, G[3];
    cin >> N;
    REP(i, 3)
    {
        cin >> G[i];
    }

    REP(j, N + 1)
    {
        dp[0][j] = false;
    }

    dp[0][N] = true;
    REP(i, 100)
    {
        REP(j, N + 1)
        {
            dp[i + 1][j] = false;
            if (j == G[0] || j == G[1] || j == G[2])
                continue;
            FOR(k, 4, 1)
            {
                if (k + j > N)
                    continue;
                if (k + j == G[0] || k + j == G[1] || k + j == G[2])
                    continue;
                dp[i + 1][j] |= dp[i][k + j];
            }
        }
    }

    REP(i, 101)
    {
        if (dp[i][0])
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}