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
    vector<pll> e;
};

Vertex V[100005];
//! Kまでのコスト
ll C[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N - 1)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].e.push_back(pll(b, c));
        V[b].e.push_back(pll(a, c));
    }
    REP(i, N)
    {
        C[i] = INF;
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    C[K] = 0;
    queue<ll> q;
    q.push(K);
    while (!q.empty())
    {
        ll t = q.front();
        q.pop();
        REP(i, V[t].e.size())
        {
            pll e = V[t].e[i];
            if (C[t] + e.second >= C[e.first])
                continue;
            C[e.first] = C[t] + e.second;
            q.push(e.first);
        }
    }

    REP(i, Q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << C[x] + C[y] << endl;
    }
    return 0;
}