#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll X[55];

int main()
{
    ll N, W;
    cin >> N >> W;
    REP(i, N)
    {
        cin >> X[i].first >> X[i].second;
    }

    ll n = N / 2;
    vector<pll> p, q;
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
        r[i] = std::max(r[i - 1], q[i].first);
    }

    ll max = 0;
    REP(i, p.size())
    {
        pll a = p[i];
        ll ok = -1, ng = q.size();
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (q[mid].second + a.second <= W)
                ok = mid;
            else
                ng = mid;
        }
        if (ok < 0)
            continue;
        max = std::max(max, r[ok] + a.first);
    }
    cout << max << endl;
    return 0;
}