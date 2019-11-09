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

Vertex V[1005];
ll A[1005];

ll dist(string a, string b)
{
    ll n = 0;
    REP(i, a.size())
    {
        if (a[i] != b[i])
            n++;
    }
    return n;
}

int main()
{
    string F, L;
    cin >> F >> L;
    ll N;
    cin >> N;
    vector<string> v(N);
    REP(i, N)
    {
        cin >> v[i];
    }
    v.push_back(F);
    v.push_back(L);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll M = v.size();
    REP(i, M)
    {
        FOR(j, M, i + 1)
        {
            if (dist(v[i], v[j]) == 1)
            {
                V[i].node.push_back(j);
                V[j].node.push_back(i);
            }
        }
    }
    ll s = 0, g = 0;
    REP(i, M)
    {
        if (F == v[i])
            s = i;
        if (L == v[i])
            g = i;
    }

    REP(i, M)
    {
        A[i] = INF;
    }
    A[s] = 0;
    queue<pll> q;
    q.push(pll(s, 0));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        ll cost = t.second + 1;
        REP(i, V[t.first].node.size())
        {
            ll n = V[t.first].node[i];
            if (A[n] <= cost)
                continue;
            A[n] = cost;
            q.push(pll(n, cost));
        }
    }

    if (A[g] == INF)
        cout << -1 << endl;
    else
    {
        vector<string> ans;
        do
        {
            ans.push_back(v[g]);
            REP(i, V[g].node.size())
            {
                ll n = V[g].node[i];
                if (A[n] == A[g] - 1)
                {
                    g = n;
                    break;
                }
            }
        } while (g != s);
        ans.push_back(v[s]);
        cout << ans.size() - 2 << endl;
        REP(i, ans.size())
        {
            cout << ans[ans.size() - 1 - i] << endl;
        }
    }
    return 0;
}