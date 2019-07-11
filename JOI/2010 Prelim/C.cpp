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

Vertex V[1005];
bool U[1005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    memset(U, 0, sizeof(U));

    ll s = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        if (U[t.first])
            continue;
        U[t.first] = true;
        s++;
        if (t.second >= 2)
            continue;
        REP(i, V[t.first].node.size())
        {
            int n = V[t.first].node[i];
            if (U[n])
                continue;
            q.push(pll(n, t.second + 1));
        }
    }
    cout << s - 1 << endl;
    return 0;
}