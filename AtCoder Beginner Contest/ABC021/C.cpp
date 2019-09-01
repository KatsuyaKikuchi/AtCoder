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

Vertex V[105];
pll S[105];
bool U[105];

int main()
{
    ll N;
    cin >> N;
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    ll M;
    cin >> M;
    REP(i, M)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        V[x].node.push_back(y);
        V[y].node.push_back(x);
    }
    REP(i, N)
    {
        S[i] = pll(INF, 0);
    }
    {
        queue<pll> q;
        q.push(pll(a, 0));
        S[a] = pll(0, 1);
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(i, V[t.first].node.size())
            {
                ll n = V[t.first].node[i];
                if (S[n].first < cost)
                    continue;
                S[n].second++;
                if (S[n].first == cost)
                    continue;
                S[n].first = cost;
                q.push(pll(n, cost));
            }
        }
    }

    ll ans = 1;
    {
        memset(U, 0, sizeof(U));
        queue<pll> q;
        q.push(pll(b, S[b].first));
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ans = (ans * S[t.first].second) % MOD;
            ll cost = t.second - 1;
            REP(i, V[t.first].node.size())
            {
                ll n = V[t.first].node[i];
                if (cost != S[n].first || U[n])
                    continue;
                U[n] = true;
                q.push(pll(n, cost));
            }
        }
    }
    cout << ans << endl;
    return 0;
}