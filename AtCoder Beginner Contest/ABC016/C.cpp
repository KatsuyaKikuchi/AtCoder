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

Vertex V[15];
bool U[15];

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

    REP(i, N)
    {
        ll sum = 0;
        queue<pll> q;
        q.push(pll(i, 0));
        memset(U, 0, sizeof(U));
        U[i] = true;
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(j, V[t.first].node.size())
            {
                ll n = V[t.first].node[j];
                if (U[n])
                    continue;
                U[n] = true;
                if (cost >= 2)
                {
                    sum++;
                    continue;
                }
                q.push(pll(n, cost));
            }
        }
        cout << sum << endl;
    }
    return 0;
}