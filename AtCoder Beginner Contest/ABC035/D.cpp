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
    vector<pll> from;
    vector<pll> to;
};

Vertex V[100005];
ll A[100005];
ll From[100005];
ll To[100005];

int main()
{
    ll N, M, T;
    cin >> N >> M >> T;
    REP(i, N)
    {
        cin >> A[i];
        From[i] = To[i] = INF;
    }
    From[0] = To[0] = 0;
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].to.push_back(pll(b, c));
        V[b].from.push_back(pll(a, c));
    }
    {
        //! 0から各点への最短距離
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(0, 0));
        while (!q.empty())
        {
            pll t = q.top();
            q.pop();
            if (To[t.first] < t.second)
                continue;
            REP(i, V[t.first].to.size())
            {
                pll n = V[t.first].to[i];
                ll cost = t.second + n.second;
                if (To[n.first] <= cost)
                    continue;
                To[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }
    {
        //! 各点から0への最短距離
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(0, 0));
        while (!q.empty())
        {
            pll t = q.top();
            q.pop();
            if (From[t.first] < t.second)
                continue;
            REP(i, V[t.first].from.size())
            {
                pll n = V[t.first].from[i];
                ll cost = t.second + n.second;
                if (From[n.first] <= cost)
                    continue;
                From[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }

    ll max = 0;
    REP(i, N)
    {
        if (From[i] == INF || To[i] == INF)
            continue;
        ll t = From[i] + To[i];
        max = std::max(max, A[i] * (T - t));
    }
    cout << max << endl;
    return 0;
}