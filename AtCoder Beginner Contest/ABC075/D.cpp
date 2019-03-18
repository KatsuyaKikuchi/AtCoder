#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[60], Y[60];

int main()
{
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> X[i] >> Y[i];
    }

    ll min = (1e18 * 5);
    REP(fx, N)
    {
        FOR(lx, N, fx)
        {
            REP(fy, N)
            {
                FOR(ly, N, fy)
                {
                    ll maxx = std::max(X[fx], X[lx]);
                    ll minx = std::min(X[fx], X[lx]);
                    ll maxy = std::max(Y[fy], Y[ly]);
                    ll miny = std::min(Y[fy], Y[ly]);
                    int n = 0;
                    REP(i, N)
                    {
                        ll x = X[i], y = Y[i];
                        if (x >= minx && x <= maxx && y >= miny && y <= maxy)
                            n++;
                    }
                    if (n < K)
                        continue;
                    min = std::min(min, (maxx - minx) * (maxy - miny));
                }
            }
        }
    }
    cout << min << endl;
    return 0;
}