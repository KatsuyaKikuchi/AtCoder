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
    ll par = -1;
    vector<ll> node;
    ll count = 0;
};

Vertex V[105];
Vertex P[105];
ll C[105];
ll H[105];

int main()
{
    ll N, X;
    cin >> N >> X;
    X--;
    REP(i, N)
    {
        cin >> H[i];
    }
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    //! Xを根にしてつなぎ直す
    {
        queue<ll> q;
        q.push(X);
        while (!q.empty())
        {
            ll t = q.front();
            q.pop();
            REP(i, V[t].node.size())
            {
                ll n = V[t].node[i];
                if (P[t].par == n)
                    continue;
                P[t].node.push_back(n);
                P[n].par = t;
                q.push(n);
            }
        }
    }
    memset(C, 0, sizeof(C));
    {
        queue<ll> q;
        REP(i, N)
        {
            if (P[i].node.size() == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            ll t = q.front();
            q.pop();
            REP(i, P[t].node.size())
            {
                ll n = P[t].node[i];
                C[t] += C[n];
            }
            if (t == X)
                break;
            if (H[t] > 0 || C[t] > 0)
                C[t] += 2;
            ll p = P[t].par;
            if (p < 0)
                continue;

            if (++P[p].count == P[p].node.size())
                q.push(p);
        }
    }

    cout << C[X] << endl;
    return 0;
}