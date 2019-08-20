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
    ll par;
};
Vertex T[200005];
Vertex V[200005];
bool U[200005];
ll P[200005];
ll A[200005];

int main()
{
    ll N, Q;
    cin >> N >> Q;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        T[a].node.push_back(b);
        T[b].node.push_back(a);
    }

    {
        memset(U, 0, sizeof(U));
        queue<ll> q;
        q.push(0);
        while (!q.empty())
        {
            ll t = q.front();
            q.pop();
            U[t] = true;
            REP(i, T[t].node.size())
            {
                ll n = T[t].node[i];
                if (U[n])
                    continue;
                V[n].par = t;
                V[t].node.push_back(n);
                q.push(n);
            }
        }
    }

    REP(i, Q)
    {
        ll p, x;
        cin >> p >> x;
        P[--p] += x;
    }

    {
        queue<pll> q;
        q.push(pll(0, 0));
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ll s = t.second + P[t.first];
            A[t.first] = s;
            REP(i, V[t.first].node.size())
            {
                ll n = V[t.first].node[i];
                q.push(pll(n, s));
            }
        }
    }
    REP(i, N)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}