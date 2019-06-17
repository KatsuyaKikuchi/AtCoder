#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    double s = (double)H * (double)W / 2.0;
    int t = 0;
    if (x + x == W && y + y == H)
        t = 1;
    cout << OF64 << s << " " << t << endl;
    return 0;
}