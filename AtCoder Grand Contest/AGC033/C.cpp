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
    vector<int> n;
};

Vertex V[200005];
ll L[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].n.push_back(b);
        V[b].n.push_back(a);
    }

    ll m = -1;
    REP(i, N)
    {
        if (V[i].n.size() == 1)
        {
            m = i;
            break;
        }
    }
    {
        queue<pll> q;
        q.push(pll(m, 0));
        L[m] = 0;
        REP(i, N)
        {
            L[i] = INF;
        }
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            REP(i, V[t.first].n.size())
            {
                int n = V[t.first].n[i];
                if (L[n] <= t.second + 1)
                    continue;
                L[n] = t.second + 1;
                q.push(pll(n, t.second + 1));
            }
        }
    }
    int mi = 0;
    REP(i, N)
    {
        if (L[mi] < L[i])
            mi = i;
    }
    {
        queue<pll> q;
        q.push(pll(mi, 0));
        REP(i, N)
        {
            L[i] = INF;
        }
        L[mi] = 0;
        while (!q.empty())
        {
            pll t = q.front();
            q.pop();
            REP(i, V[t.first].n.size())
            {
                int n = V[t.first].n[i];
                if (L[n] <= t.second + 1)
                    continue;
                L[n] = t.second + 1;
                q.push(pll(n, t.second + 1));
            }
        }
    }

    mi = 0;
    REP(i, N)
    {
        if (L[mi] < L[i])
            mi = i;
    }

    ll len = L[mi];
    if (N == 1)
    {
        cout << "First" << endl;
    }
    else
    {
        if ((len - 1) % 3 == 0)
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
    return 0;
}