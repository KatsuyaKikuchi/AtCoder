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
    int par;
    vector<int> child;
    int count;
    ll size;
};

Vertex V[1005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N - 1)
    {
        int p;
        cin >> p;
        V[i + 1].par = p;
        V[p].child.push_back(i + 1);
    }

    queue<int> q;
    REP(i, M)
    {
        ll b, c;
        cin >> b >> c;
        V[b].size = c;
        q.push(b);
    }

    ll sum = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int p = V[t].par;
        if (t == p)
            break;

        if (++V[p].count == V[p].child.size())
        {
            ll min = INF;
            REP(i, V[p].child.size())
            {
                int n = V[p].child[i];
                min = std::min(min, V[n].size);
            }
            V[p].size = min;
            REP(i, V[p].child.size())
            {
                int n = V[p].child[i];
                sum += V[n].size - min;
            }
            q.push(p);
        }
    }
    cout << sum + V[0].size * V[0].count << endl;
    return 0;
}