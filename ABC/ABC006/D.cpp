#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[30005];
//! 長さiの最長部分増加列の最後の値
ll dp[30005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> C[i];
        dp[i] = INF;
    }
    dp[N] = INF;

    REP(i, N)
    {
        ll ok = -1, ng = N;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (dp[mid] < C[i])
                ok = mid;
            else
                ng = mid;
        }
        dp[ok + 1] = std::min(dp[ok + 1], C[i]);
    }

    REP(i, N + 2)
    {
        if (dp[i] == INF)
        {
            cout << N - i << endl;
            break;
        }
    }
    return 0;
}