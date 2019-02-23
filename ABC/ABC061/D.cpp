#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e16;

struct Vertex
{
    vector<pll> n;
    int count = 0;
};

ll S[1005];
Vertex V[1005];
//! 各頂点に戻ってくるコストが正のループが存在するか
bool L[1005] = {false};

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].n.push_back(pll(b, c));
        V[b].count++;
    }
    REP(i, N)
    {
        S[i] = -INF;
    }
    queue<pll> q;
    q.push(pll(0, 0));
    S[0] = 0;
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        REP(i, V[t.first].n.size())
        {
            pll node = V[t.first].n[i];
            ll c = t.second + node.second;
            V[node.first].count--;
            if (S[node.first] >= c)
                continue;
            if (L[node.first])
                continue;
            S[node.first] = c;
            if (V[node.first].count < 0)
                L[node.first] = true;
            q.push(pll(node.first, c));
        }
    }

    if (L[N - 1])
        cout << "inf" << endl;
    else
        cout << S[N - 1] << endl;

    return 0;
}