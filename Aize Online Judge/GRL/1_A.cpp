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

Vertex V[100005];
ll S[100005];

int main()
{
    ll N, M, R;
    cin >> N >> M >> R;
    REP(i, M)
    {
        ll s, t, d;
        cin >> s >> t >> d;
        V[s].node.push_back(pll(t, d));
    }

    REP(i, N)
    {
        S[i] = INF;
    }
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(R, 0));
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (S[t.first] <= t.second)
            continue;
        S[t.first] = t.second;
        REP(i, V[t.first].node.size())
        {
            pll n = V[t.first].node[i];
            ll cost = t.second + n.second;
            if (S[n.first] <= cost)
                continue;
            q.push(pll(n.first, cost));
        }
    }
    REP(i, N)
    {
        if (S[i] == INF)
            cout << "INF";
        else
            cout << S[i];
        cout << endl;
    }
    return 0;
}