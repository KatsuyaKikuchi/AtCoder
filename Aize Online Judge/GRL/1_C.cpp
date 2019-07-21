#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[105][105];

int main()
{
    ll V, E;
    cin >> V >> E;

    REP(i, V)
    {
        REP(j, V)
        {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }
    REP(i, E)
    {
        ll s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    REP(k, V)
    {
        REP(i, V)
        {
            REP(j, V)
            {
                if (dp[i][k] == INF || dp[k][j] == INF)
                    continue;
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool neg = false;
    REP(i, V)
    {
        if (dp[i][i] != 0)
            neg = true;
    }
    if (neg)
        cout << "NEGATIVE CYCLE" << endl;
    else
    {
        REP(i, V)
        {
            REP(j, V)
            {
                if (dp[i][j] == INF)
                    cout << "INF";
                else
                    cout << dp[i][j];

                if (j < V - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}