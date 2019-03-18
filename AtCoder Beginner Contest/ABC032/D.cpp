#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll X[205];
ll dp[205][200005];

int main()
{
    ll N, W;
    cin >> N >> W;
    ll v = 0;
    ll w = 0;
    REP(i, N)
    {
        cin >> X[i].first >> X[i].second;
        v = std::max(v, X[i].first);
        w = std::max(w, X[i].second);
    }

    if (N <= 30)
    {
        //! 半分全列挙
        ll n = N / 2;
        vector<pll> p;
        vector<pll> q;
        REP(i, pow(2, n))
        {
            pll t(0, 0);
            REP(j, n)
            {
                if (((i >> j) & 1) == 1)
                {
                    t.first += X[j].first;
                    t.second += X[j].second;
                }
            }
            p.push_back(t);
        }
        REP(i, pow(2, N - n))
        {
            pll t(0, 0);
            REP(j, N - n)
            {
                if (((i >> j) & 1) == 1)
                {
                    t.first += X[j + n].first;
                    t.second += X[j + n].second;
                }
            }
            q.push_back(t);
        }

        sort(q.begin(), q.end(), [](pll a, pll b) { return a.second < b.second; });
        vector<ll> r(q.size());
        r[0] = q[0].first;
        FOR(i, q.size(), 1)
        {
            r[i] = std::max(q[i].first, r[i - 1]);
        }
        ll max = 0;
        REP(i, p.size())
        {
            pll a = p[i];
            ll ok = -1, ng = q.size();
            while (abs(ng - ok) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (q[mid].second + a.second <= W)
                    ok = mid;
                else
                    ng = mid;
            }
            if (ok < 0)
                continue;
            max = std::max(max, a.first + r[ok]);
        }
        cout << max << endl;
    }
    else if (v <= 1000)
    {
        //! 価値のdp
        REP(i, N + 1)
        {
            REP(j, v * N + 1)
            {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        REP(i, N)
        {
            REP(j, v * N + 1)
            {
                dp[i + 1][j] = dp[i][j];
                if (j - X[i].first >= 0)
                    dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j - X[i].first] + X[i].second);
            }
        }

        ll max = 0;
        REP(i, v * N + 1)
        {
            if (dp[N][i] <= W)
                max = i;
        }
        cout << max << endl;
    }
    else
    {
        //! 重さのdp
        REP(i, N + 1)
        {
            REP(j, w * N + 1)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 0;
        REP(i, N)
        {
            REP(j, w * N + 1)
            {
                dp[i + 1][j] = dp[i][j];
                if (j - X[i].second >= 0)
                    dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - X[i].second] + X[i].first);
            }
        }

        ll max = 0;
        REP(i, std::min(W, w * N) + 1)
        {
            max = std::max(max, dp[N][i]);
        }
        cout << max << endl;
    }

    return 0;
}