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
    vector<int> next;
    int p = 0;
};

Vertex V[100005];
bool isC[100005];
int Ans[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N - 1 + M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        isC[b] = true;
        V[a].next.push_back(b);
        V[b].p++;
    }

    int root = -1;
    REP(i, N)
    {
        if (!isC[i])
        {
            root = i;
            break;
        }
    }

    Ans[root] = -1;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        REP(i, V[t].next.size())
        {
            int n = V[t].next[i];
            V[n].p--;
            if (V[n].p > 0)
                continue;
            Ans[n] = t;
            q.push(n);
        }
    }

    REP(i, N)
    {
        cout << Ans[i] + 1 << endl;
    }
    return 0;
}