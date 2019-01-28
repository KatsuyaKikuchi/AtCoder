#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[610];
//! [数字iを][jこ作る]=組み合わせ
ll dp[610][610];

int main()
{
    int T;
    cin >> T;
    REP(i, T)
    {
        cin >> A[i];
    }
    dp[0][0] = 1;
    FOR(i, 610, 1)
    {
        dp[i][0] = 1;
        FOR(j, 610, 1)
        {
            //! i-1を使ってk個作る
            ll sum = 0;
            REP(k, j + 1)
            {
                if (dp[i - 1][k * 2] == 0)
                    break;
                if (A[i - 1] < j - k)
                    continue;
                sum += dp[i - 1][k * 2];
                sum %= MOD;
            }
            dp[i][j] = sum;
        }
    }

    ll ans = 0;
    REP(i, 610)
    {
        ans += dp[i][1];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}