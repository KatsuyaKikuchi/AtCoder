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
    int H, W, N;
    cin >> W >> H >> N;
    int minx = 0, miny = 0, maxx = W, maxy = H;
    REP(i, N)
    {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a)
        {
        case 1:
            minx = std::max(x, minx);
            break;
        case 2:
            maxx = std::min(x, maxx);
            break;
        case 3:
            miny = std::max(y, miny);
            break;
        case 4:
            maxy = std::min(y, maxy);
            break;
        }
    }
    cout << std::max(maxx - minx, 0) * std::max(maxy - miny, 0) << endl;
    return 0;
}