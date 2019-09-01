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

Vertex V[305];
ll S[305];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        V[a].node.push_back(pll(b, l));
        V[b].node.push_back(pll(a, l));
    }

    ll min = INF;
    REP(i, V[0].node.size())
    {
        REP(j, N)
        {
            S[j] = INF;
        }
        ll s = V[0].node[i].first;
        ll c = V[0].node[i].second;
        S[s] = c;
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        REP(j, V[s].node.size())
        {
            ll n = V[s].node[j].first;
            if (n == 0)
                continue;
            ll cost = c + V[s].node[j].second;
            q.push(pll(n, cost));
        }
        while (!q.empty())
        {
            pll t = q.top();
            q.pop();
            if (S[t.first] < t.second)
                continue;
            S[t.first] = t.second;
            REP(j, V[t.first].node.size())
            {
                pll n = V[t.first].node[j];
                ll cost = t.second + n.second;
                if (S[n.first] <= cost)
                    continue;
                S[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
        min = std::min(min, S[0]);
    }

    if (min == INF)
        cout << -1 << endl;
    else
        cout << min << endl;
    return 0;
}