#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll tmax(ll a, ll b, ll c)
{
    return std::max(a, std::max(b, c));
}
ll tmin(ll a, ll b, ll c)
{
    return std::min(a, std::min(b, c));
}

ll solve(ll H, ll W)
{
    ll m = INF;
    FOR(i, H, 1)
    {
        ll s0 = i * W;
        ll h = H - i;
        {
            ll s1 = h * (W / 2);
            ll s2 = h * (W / 2 + W % 2);
            m = std::min(tmax(s0, s1, s2) - tmin(s0, s1, s2), m);
        }
        {
            ll s1 = (h / 2) * W;
            ll s2 = (h / 2 + h % 2) * W;
            m = std::min(tmax(s0, s1, s2) - tmin(s0, s1, s2), m);
        }
    }
    return m;
}

int main()
{
    int H, W;
    cin >> H >> W;
    ll min = std::min(solve(W, H), solve(H, W));
    cout << min << endl;
    return 0;
}