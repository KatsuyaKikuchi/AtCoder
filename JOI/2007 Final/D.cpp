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
    vector<int> child;
    vector<int> parent;
    int count = 0;
};

Vertex V[5005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int w, l;
        cin >> w >> l;
        w--;
        l--;
        V[w].child.push_back(l);
        V[l].parent.push_back(w);
    }

    queue<int> q;
    REP(i, N)
    {
        if (V[i].child.size() == 0)
            q.push(i);
    }

    int d = q.size() == 1 ? 0 : 1;
    vector<int> ans;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t + 1);
        int add = 0;
        REP(i, V[t].parent.size())
        {
            int p = V[t].parent[i];
            V[p].count++;
            if (V[p].count == V[p].child.size())
            {
                q.push(p);
                add++;
            }
        }
        if (add > 1)
            d = 1;
    }
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i] << endl;
    }
    cout << d << endl;
    return 0;
}