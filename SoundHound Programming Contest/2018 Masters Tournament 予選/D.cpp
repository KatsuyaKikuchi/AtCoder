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
    Node(int t, ll y, ll s) : to(t), y(y), s(s) {}
    int to;
    ll y;
    ll s;
};
struct Vertex
{
    vector<Node> n;
};

Vertex V[100005];

//! Sから都市iまで、yenを使って移動する最小コスト
ll X[100005];
//! Tから都市iまで、snukを使って移動する最小コスト
ll Y[100005];
ll ans[100005];

int main()
{
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    REP(i, M)
    {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        V[u].n.push_back(Node(v, a, b));
        V[v].n.push_back(Node(u, a, b));
    }
    REP(i, N)
    {
        X[i] = Y[i] = INF;
    }
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(S, 0));
        while (!q.empty())
        {
            pll t = q.top();
            q.pop();
            if (t.second >= X[t.first])
                continue;
            X[t.first] = t.second;
            REP(i, V[t.first].n.size())
            {
                int to = V[t.first].n[i].to;
                if (t.second + V[t.first].n[i].y >= X[to])
                    continue;
                q.push(pll(to, t.second + V[t.first].n[i].y));
            }
        }
    }
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(T, 0));
        while (!q.empty())
        {
            pll t = q.top();
            q.pop();
            if (t.second >= Y[t.first])
                continue;
            Y[t.first] = t.second;
            REP(i, V[t.first].n.size())
            {
                int to = V[t.first].n[i].to;
                if (t.second + V[t.first].n[i].s >= Y[to])
                    continue;
                q.push(pll(to, t.second + V[t.first].n[i].s));
            }
        }
    }

    REP(i, N)
    {
        ans[N - 1 - i] = INF - (X[N - 1 - i] + Y[N - 1 - i]);
        if (i > 0)
        {
            ans[N - 1 - i] = std::max(ans[N - 1 - i], ans[N - i]);
        }
    }
    REP(i, N)
    {
        cout << ans[i] << endl;
    }
    return 0;
}