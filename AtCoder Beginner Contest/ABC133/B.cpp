#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[20][20];

int main()
{
    ll N, D;
    cin >> N >> D;
    REP(i, N)
    {
        REP(j, D)
        {
            cin >> X[i][j];
        }
    }

    ll ans = 0;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            ll s = 0;
            REP(d, D)
            {
                s += (X[i][d] - X[j][d]) * (X[i][d] - X[j][d]);
            }

            ll t = 1;
            while (s >= t * t)
            {
                if (s == t * t)
                    ans++;
                t++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}