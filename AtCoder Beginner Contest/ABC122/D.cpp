#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [iまでの中で][1つ前がj][2-k][3-l]=組み合わせ
ll dp[105][5][5][5];

int main()
{
    ll N;
    cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    REP(i, N)
    {
        REP(j, 4)
        {
            if (j == 1)
            {
                //! Cをおきたい
                REP(x, 4)
                {
                    REP(y, 4)
                    {
                        REP(z, 4)
                        {
                            if ((i > 1 && ((x == 2 && y == 0) || (x == 0 && y == 2))) || (i > 2 && ((x == 2 && z == 0) || (y == 2 && z == 0))))
                                continue;
                            dp[i + 1][j][x][y] += dp[i][x][y][z];
                            dp[i + 1][j][x][y] %= MOD;
                        }
                    }
                }
            }
            else if (j == 2)
            {
                //! Gをおきたい
                REP(x, 4)
                {
                    REP(y, 4)
                    {
                        REP(z, 4)
                        {
                            if (i > 1 && x == 1 && y == 0)
                                continue;
                            dp[i + 1][j][x][y] += dp[i][x][y][z];
                            dp[i + 1][j][x][y] %= MOD;
                        }
                    }
                }
            }
            else
            {
                REP(x, 4)
                {
                    REP(y, 4)
                    {
                        REP(z, 4)
                        {
                            dp[i + 1][j][x][y] += dp[i][x][y][z];
                            dp[i + 1][j][x][y] %= MOD;
                        }
                    }
                }
            }
        }
    }
    ll sum = 0;
    REP(x, 4)
    {
        REP(y, 4)
        {
            REP(z, 4)
            {
                sum += dp[N][x][y][z];
                sum %= MOD;
            }
        }
    }
    cout << sum << endl;
    return 0;
}