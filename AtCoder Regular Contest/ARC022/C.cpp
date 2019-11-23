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
    vector<ll> node;
};

ll N;
Vertex V[100005];
ll L[100005];

void solve(ll s)
{
    REP(i, N)
    {
        L[i] = INF;
    }
    L[s] = 0;
    queue<pll> q;
    q.push(pll(s, 0));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        ll cost = t.second + 1;
        REP(i, V[t.first].node.size())
        {
            ll n = V[t.first].node[i];
            if (L[n] <= cost)
                continue;
            L[n] = cost;
            q.push(pll(n, cost));
        }
    }
}

int main()
{
    cin >> N;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    solve(0);

    ll s = 0;
    REP(i, N)
    {
        if (L[s] < L[i])
            s = i;
    }

    solve(s);
    ll e = 0;
    REP(i, N)
    {
        if (L[e] < L[i])
            e = i;
    }

    cout << s + 1 << " " << e + 1 << endl;
    return 0;
}