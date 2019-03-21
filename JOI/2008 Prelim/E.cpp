#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int M[15][10005];

int main()
{
    int R, C;
    cin >> R >> C;
    REP(i, R)
    {
        REP(j, C)
        {
            cin >> M[i][j];
        }
    }

    ll max = 0;
    REP(i, pow(2, R))
    {
        ll m = 0;
        REP(c, C)
        {
            ll n = 0;
            REP(r, R)
            {
                n += (M[r][c] + ((i >> r) & 1)) % 2;
            }
            m += std::max(n, R - n);
        }
        max = std::max(m, max);
    }
    cout << max << endl;
    return 0;
}