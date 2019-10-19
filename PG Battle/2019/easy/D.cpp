#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Node
{
    ll to;
    ll cost;
    ll d;
};
struct Vertex
{
    vector<Node> node;
};

Vertex V[100005];
ll S[100005];

int main()
{
    ll N, M, T, K;
    cin >> N >> M >> T >> K;
    REP(i, M)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        V[a].node.push_back(Node{b, c, d});
        V[b].node.push_back(Node{a, c, d});
    }
    REP(i, N)
    {
        S[i] = INF;
    }
    S[0] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (S[t.first] < t.second)
            continue;
        REP(i, V[t.first].node.size())
        {
            auto n = V[t.first].node[i];
            ll start = t.second;
            ll goal = start + n.cost;
            if (goal > T || K < n.d - abs(T - goal))
            {
                //! startをT以降のKになるところにする
                start = n.d - K + T;
                goal = start + n.cost;
            }

            if (S[n.to] <= goal)
                continue;
            S[n.to] = goal;
            q.push(pll(n.to, goal));
        }
    }

    if (S[N - 1] == INF)
        cout << -1 << endl;
    else
        cout << S[N - 1] << endl;
    return 0;
}