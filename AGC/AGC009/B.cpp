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
    int depth = 0;
    int par = 0;
};

Vertex V[100005];
int C[100005];

int main()
{
    int N;
    cin >> N;
    FOR(i, N, 1)
    {
        ll a;
        cin >> a;
        V[--a].node.push_back(i);
        V[i].par = a;
    }

    queue<int> q;
    REP(i, N)
    {
        if (V[i].node.size() == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        sort(V[t].node.begin(), V[t].node.end(), [&](int a, int b) { return V[a].depth > V[b].depth; });
        ll maxDep = 0;
        REP(i, V[t].node.size())
        {
            int n = V[t].node[i];
            maxDep = std::max(maxDep, i + 1 + V[n].depth);
        }
        V[t].depth = maxDep;

        int par = V[t].par;
        if (++C[par] == V[par].node.size())
            q.push(par);
    }

    cout << V[0].depth << endl;
    return 0;
}