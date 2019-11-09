#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll M[1005][1005];
ll S[1005][1005];

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main()
{
    ll H, W;
    cin >> H >> W;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return M[a.first][a.second] < M[b.first][b.second]; });
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> M[i][j];
            q.push(pll(i, j));
        }
    }
    memset(S, 0, sizeof(S));
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        ll h = t.first, w = t.second;
        S[h][w] = 1;
        REP(i, 4)
        {
            ll nh = h + x[i], nw = w + y[i];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W)
                continue;
            if (M[nh][nw] <= M[h][w])
                continue;
            S[h][w] += S[nh][nw];
        }
        S[h][w] %= MOD;
    }

    ll ans = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            ans += S[i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}