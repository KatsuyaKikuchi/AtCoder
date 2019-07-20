#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    ll ans = (H - 1) * W + (W - 1) * H;
    vector<pll> v;
    REP(n, N)
    {
        ll r, c;
        cin >> r >> c;
        REP(i, 4)
        {
            ll nx = r + x[i], ny = c + y[i];
            if (nx < 1 || nx > H || ny < 1 || ny > W)
                continue;
            bool t = false;
            REP(j, v.size())
            {
                if (v[j].first == nx && v[j].second == ny)
                    t = true;
            }
            if (t)
                continue;
            ans--;
        }
        v.push_back(pll(r, c));
    }
    cout << ans << endl;
    return 0;
}