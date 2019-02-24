#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll P[105];
//! [i番目までの問題を][j問解いた時の]=最大点数
ll dp[15][1005];

int main()
{
    ll D, G;
    cin >> D >> G;
    REP(i, D)
    {
        cin >> P[i].first >> P[i].second;
    }
    dp[0][0] = 0;
    ll sum = 0;
    REP(i, D)
    {
        sum += P[i].first;
        REP(j, sum + 1)
        {
            ll max = 0;
            REP(k, P[i].first + 1)
            {
                if (j - k < 0)
                    break;
                ll s = dp[i][j - k] + 100 * (i + 1) * k;
                if (k == P[i].first)
                    s += P[i].second;
                max = std::max(s, max);
            }
            dp[i + 1][j] = max;
        }
    }

    REP(i, sum + 1)
    {
        if (dp[D][i] >= G)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}