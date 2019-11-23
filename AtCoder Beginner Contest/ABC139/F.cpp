#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Data
{
    pll g;
    double theta;
};

Data D[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        ll x, y;
        cin >> x >> y;
        double c = x / sqrt(x * x + y * y);
        D[i].g = pll(x, y);
        D[i].theta = acos(c);
        if (y <= 0)
            D[i].theta = 2.0 * M_PI - D[i].theta;
    }

    sort(D, D + N, [](Data a, Data b) { return a.theta < b.theta; });

    double max = 0;
    REP(i, N)
    {
        double x = 0, y = 0;
        REP(j, N)
        {
            x += D[(i + j) % N].g.first;
            y += D[(i + j) % N].g.second;
            max = std::max(max, sqrt(x * x + y * y));
        }
    }
    cout << OF64 << max << endl;
    return 0;
}