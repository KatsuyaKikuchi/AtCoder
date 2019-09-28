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
    vector<ll> pre;
    vector<ll> node;
};

Vertex V[1005];
bool U[1005];
ll R[1005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;
        V[--a].node.push_back(--b);
        V[b].pre.push_back(a);
    }

    memset(U, 0, sizeof(U));
    ll s = -1;
    ll minCost = INF;
    REP(i, N)
    {
        memset(U, 0, sizeof(U));
        queue<pll> q;
        q.push(pll(i, 0));
        U[i] = true;
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(j, V[t.first].node.size())
            {
                ll n = V[t.first].node[j];
                if (n == i)
                {
                    if (cost >= minCost)
                    {
                        break;
                    }
                    //! iから始まるループがある
                    s = i;
                    minCost = cost;
                    break;
                }
                if (U[n])
                    continue;
                U[n] = true;
                q.push(pll(n, cost));
            }
        }
    }

    if (s == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    memset(U, 0, sizeof(U));
    REP(i, N)
    {
        R[i] = INF;
    }
    vector<ll> v;
    v.push_back(s);
    {
        queue<pll> q;
        q.push(pll(s, 0));
        U[s] = true;
        R[s] = 0;
        ll min = -1;
        ll nxt = s;
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(i, V[t.first].node.size())
            {
                ll n = V[t.first].node[i];
                if (n == s)
                {
                    min = cost - 1;
                    nxt = t.first;
                    break;
                }
                if (U[n])
                    continue;
                q.push(pll(n, cost));
                R[n] = cost;
                U[n] = true;
            }
            if (min >= 0)
                break;
        }

        while (nxt != s)
        {
            v.push_back(nxt);
            REP(i, V[nxt].pre.size())
            {
                ll n = V[nxt].pre[i];
                if (min - 1 == R[n])
                {
                    min--;
                    nxt = n;
                    break;
                }
            }
        }
    }

    cout << v.size() << endl;
    REP(i, v.size())
    {
        cout << v[i] + 1 << endl;
    }
    return 0;
}