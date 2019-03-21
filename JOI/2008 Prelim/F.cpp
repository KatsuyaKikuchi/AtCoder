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
    vector<pll> node;
};
int N, K;
Vertex V[105];

ll solve(ll s, ll g)
{
    vector<ll> cost(N, INF);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(s, 0));
    cost[s] = 0;
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (t.second > cost[t.first])
            continue;
        REP(i, V[t.first].node.size())
        {
            pll n = V[t.first].node[i];
            ll c = t.second + n.second;
            if (c >= cost[n.first])
                continue;
            q.push(pll(n.first, c));
            cost[n.first] = c;
        }
    }

    return cost[g] == INF ? -1 : cost[g];
}

int main()
{
    cin >> N >> K;
    vector<ll> ans;
    REP(i, K)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            int a, b;
            cin >> a >> b;
            ans.push_back(solve(a - 1, b - 1));
        }
        else
        {
            ll c, d, e;
            cin >> c >> d >> e;
            c--;
            d--;
            V[c].node.push_back(pll(d, e));
            V[d].node.push_back(pll(c, e));
        }
    }

    REP(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}