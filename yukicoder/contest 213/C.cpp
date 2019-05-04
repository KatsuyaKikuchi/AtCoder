#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    vector<int> n;
    ll depth = INF;
};

Vertex V[200005];
ll F;
ll IF[200005];
ll N;

int main()
{
    cin >> N;
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].n.push_back(b);
        V[b].n.push_back(a);
    }

    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        V[t.first].depth = t.second;
        int nd = t.second + 1;
        REP(i, V[t.first].n.size())
        {
            int n = V[t.first].n[i];
            if (nd >= V[n].depth)
                continue;
            q.push(pll(n, nd));
        }
    }
    memset(IF, 0, sizeof(IF));
    FOR(i, N + 2, 1)
    {
        ll f = 1;
        ll t = i;
        for (int j = 0; j <= 30; ++j)
        {
            if ((((MOD - 2) >> j) & 1) == 1)
            {
                f *= t;
                f %= MOD;
            }
            t = (t * t) % MOD;
        }
        IF[i] = f;
    }
    F = 1;
    FOR(i, N + 1, 1)
    {
        F = F * i % MOD;
    }
    ll ans = 0;
    REP(i, N)
    {
        ans += F * IF[V[i].depth + 1];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}