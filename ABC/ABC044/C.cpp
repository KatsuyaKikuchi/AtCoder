#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int X[55];
//! [i枚目までの中で][j枚選んで][和をkにする]=組み合わせの数
ll dp[55][55][2505];

int main()
{
    int N, A;
    cin >> N >> A;
    REP(i, N)
    {
        cin >> X[i];
    }
    dp[0][0][0] = 1;
    FOR(i, N + 1, 1)
    {
        REP(j, i + 1)
        {
            REP(k, 2505)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k - X[i - 1] >= 0 && j > 0)
                {
                    dp[i][j][k] += dp[i - 1][j - 1][k - X[i - 1]];
                }
            }
        }
    }

    ll sum = 0;
    REP(i, N)
    {
        sum += dp[N][i + 1][(i + 1) * A];
    }
    cout << sum << endl;
    return 0;
}