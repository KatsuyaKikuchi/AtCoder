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
struct Edge
{
    ll from;
    ll to;
    ll cost;
};
Vertex V[3000];
Edge E[5005];
ll A[3000];
bool C[3000];
bool U[3000];

int main()
{
    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        E[i].from = --a;
        E[i].to = --b;
        E[i].cost = -(c - P);
        V[a].node.push_back(b);
    }
    memset(C, 0, sizeof(C));
    REP(i, N)
    {
        memset(U, 0, sizeof(U));
        queue<ll> q;
        q.push(i);
        U[i] = true;
        while (!q.empty())
        {
            ll t = q.front();
            q.pop();
            if (i == 0)
                C[t] = true;
            REP(i, V[t].node.size())
            {
                ll n = V[t].node[i];
                if (U[n])
                    continue;
                U[n] = true;
                q.push(n);
            }
        }
        C[i] = C[i] & U[N - 1];
    }

    REP(i, N)
    {
        A[i] = INF;
    }
    A[0] = 0;
    REP(v, N)
    {
        REP(j, M)
        {
            auto e = E[j];
            A[e.to] = std::min(A[e.to], A[e.from] + e.cost);
        }
    }

    bool loop = false;
    REP(i, M)
    {
        auto e = E[i];
        ll cost = A[e.from] + e.cost;
        if (cost < A[e.to] && C[e.to])
            loop = true;
    }

    if (loop)
        cout << -1 << endl;
    else
        cout << std::max(0LL, -A[N - 1]) << endl;
    return 0;
}