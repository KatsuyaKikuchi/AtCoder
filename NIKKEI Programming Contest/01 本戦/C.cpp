#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll g[100005];
ll HN[100005];
ll WN[100005];
ll HS[100005][2];
ll WS[100005][2];

int main()
{
    ll H, W, K;
    cin >> H >> W >> K;
    REP(i, H)
    {
        HN[i] = W;
    }
    REP(i, W)
    {
        WN[i] = H;
    }
    REP(i, K)
    {
        cin >> g[i].first >> g[i].second;
        HN[--g[i].first]--;
        WN[--g[i].second]--;
    }

    //! 重心
    pll center(0, 0);
    {
        ll h = 0;
        HS[0][0] = 0;
        FOR(i, H, 1)
        {
            h += HN[i - 1];
            HS[i][0] = HS[i - 1][0] + h;
        }
        h = 0;
        HS[H - 1][1] = 0;
        for (int i = H - 2; i >= 0; --i)
        {
            h += HN[i + 1];
            HS[i][1] = HS[i + 1][1] + h;
        }
        int m = 0;
        REP(i, H)
        {
            ll sm = HS[m][0] + HS[m][1];
            ll k = HS[i][0] + HS[i][1];
            if (sm > k)
                m = i;
        }
        center.first = m;
    }
    {
        ll w = 0;
        WS[0][0] = 0;
        FOR(i, W, 1)
        {
            w += WN[i - 1];
            WS[i][0] = WS[i - 1][0] + w;
        }
        w = 0;
        WS[W - 1][1] = 0;
        for (int i = W - 2; i >= 0; --i)
        {
            w += WN[i + 1];
            WS[i][1] = WS[i + 1][1] + w;
        }
        int m = 0;
        REP(i, W)
        {
            ll sm = WS[m][0] + WS[m][1];
            ll k = WS[i][0] + WS[i][1];
            if (sm > k)
                m = i;
        }
        center.second = m;
    }

    ll hs = 0;
    REP(i, H)
    {
        hs += abs(i - center.first);
    }
    ll ws = 0;
    REP(i, W)
    {
        ws += abs(i - center.second);
    }
    //! 全ての駒を中央に持ってくるのにかかる最短手数
    ll sum = hs * W + ws * H;
    REP(i, K)
    {
        sum -= abs(g[i].first - center.first) + abs(g[i].second - center.second);
    }
    cout << sum << endl;
    return 0;
}