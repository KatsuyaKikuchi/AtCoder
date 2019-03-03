#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! 全点間最短距離
ll D[305][305];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        REP(j, N)
        {
            D[i][j] = INF;
        }
        D[i][i] = 0;
    }
    REP(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        D[a][b] = D[b][a] = c;
    }

    //! ワーシャルフロイド
    REP(k, N)
    {
        REP(i, N)
        {
            REP(j, N)
            {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    ll min = INF;
    REP(i, N)
    {
        ll m = 0;
        REP(j, N)
        {
            m = std::max(m, D[i][j]);
        }
        min = std::min(min, m);
    }
    cout << min << endl;
    return 0;
}