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
    vector<int> node;
};

Vertex V[200005];
ll A[200005];

int main()
{
    ll N, M, S;
    cin >> N >> M >> S;
    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    REP(i, N)
    {
        A[i] = -1;
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });
    q.push(pll(S - 1, S - 1));
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (A[t.first] >= t.second)
            continue;
        A[t.first] = t.second;
        Vertex v = V[t.first];
        REP(i, v.node.size())
        {
            ll a = v.node[i];
            ll n = std::min(t.first, t.second);
            if (A[a] >= n)
                continue;
            q.push(pll(a, n));
        }
    }

    REP(i, N)
    {
        if (A[i] < i)
            continue;
        cout << i + 1 << endl;
    }
    return 0;
}