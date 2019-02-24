#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[10];
//! [bitで表される竹を使って][長さiの竹を作るための]=MP
ll dp[300][5];
//! bitで表される竹を全て足した和
ll T[300];
int N, K[3];

int main()
{
    cin >> N >> K[0] >> K[1] >> K[2];
    int m = pow(2, N);
    REP(i, N)
    {
        cin >> L[i];
    }
    sort(L, L + N);
    REP(i, m)
    {
        ll sum = 0;
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
                sum += L[j];
        }
        T[i] = sum;
        REP(j, 3)
        {
            dp[i][j] = INF;
        }
    }

    FOR(i, m, 1)
    {
        int n = 0;
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
                n++;
        }
        REP(j, 3)
        {
            dp[i][j] = std::min(dp[i][j], 10 * (n - 1) + abs(T[i] - K[j]));
        }
    }

    ll min = INF;
    FOR(i, m, 1)
    {
        FOR(j, m, 1)
        {
            FOR(k, m, 1)
            {
                bool f = false;
                REP(l, N)
                {
                    int s = 0;
                    s = ((i >> l) & 1) + ((j >> l) & 1) + ((k >> l) & 1);
                    if (s > 1)
                    {
                        f = true;
                        break;
                    }
                }
                if (f)
                    continue;
                min = std::min(min, dp[i][0] + dp[j][1] + dp[k][2]);
            }
        }
    }
    cout << min << endl;
    return 0;
}