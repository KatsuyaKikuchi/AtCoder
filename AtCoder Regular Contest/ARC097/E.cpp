#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! 各色i番のindex
int BI[2005], WI[2005];
//! 各色[i番目までにある][jより小さい番号の]=数
ll BN[4005][2005], WN[4005][2005];

ll dpB[4005][2005];
ll dpW[4005][2005];

int main()
{
    ll N;
    cin >> N;
    memset(BN, 0, sizeof(BN));
    memset(WN, 0, sizeof(WN));
    REP(i, 2 * N)
    {
        char c;
        ll n;
        cin >> c >> n;
        if (c == 'W')
        {
            WI[n] = i;
            WN[i][n]++;
        }
        else if (c == 'B')
        {
            BI[n] = i;
            BN[i][n]++;
        }
        REP(j, N + 1)
        {
            BN[i + 1][j] = BN[i][j];
            WN[i + 1][j] = WN[i][j];
        }
    }
    REP(i, 2 * N + 1)
    {
        REP(j, N)
        {
            BN[i][j + 1] += BN[i][j];
            WN[i][j + 1] += WN[i][j];
        }
    }

    memset(dpW, 0, sizeof(dpW));
    memset(dpB, 0, sizeof(dpB));
    REP(i, 2 * N)
    {
        REP(j, N)
        {
            ll w = j;
            ll b = i - w;
            if (w > N || b < 0)
                break;
            if (b > N)
                continue;
            int wi = WI[w + 1];
            ll cost = wi - (BN[wi][b] + WN[wi][w]);
            if (w == 0)
                dpW[i + 1][w + 1] = dpB[i][b];
            else if (b == 0)
                dpW[i + 1][w + 1] = dpW[i][w];
            else
                dpW[i + 1][w + 1] = std::min(dpW[i][w], dpB[i][b]);
            dpW[i + 1][w + 1] += cost;
        }
        REP(j, N)
        {
            ll b = j;
            ll w = i - b;
            if (b > N || w < 0)
                break;
            if (w > N)
                continue;
            int bi = BI[b + 1];
            ll cost = bi - (BN[bi][b] + WN[bi][w]);
            if (w == 0)
                dpB[i + 1][b + 1] = dpB[i][b];
            else if (b == 0)
                dpB[i + 1][b + 1] = dpW[i][w];
            else
                dpB[i + 1][b + 1] = std::min(dpW[i][w], dpB[i][b]);
            dpB[i + 1][b + 1] += cost;
        }
    }
    cout << std::min(dpB[2 * N][N], dpW[2 * N][N]) << endl;
    return 0;
}