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
    ll C[10];
};
int N, M;
Vertex V[1005];

ll solve(int n)
{
    REP(i, N)
    {
        REP(j, n)
        {
            V[i].C[j] = INF;
        }
    }
    V[0].C[0] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (V[t.first].C[t.second % n] < t.second)
            continue;
        REP(i, V[t.first].node.size())
        {
            pll e = V[t.first].node[i];
            ll cost = t.second + e.second;
            if (V[e.first].C[cost % n] <= cost)
                continue;

            V[e.first].C[cost % n] = cost;
            if (e.first < N - 1)
                q.push(pll(e.first, cost));
        }
    }

    return V[N - 1].C[0];
}

int main()
{
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }
    cout << std::min(solve(4), solve(7)) << endl;
    return 0;
}