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

Vertex V[100005];
bool T[100005][2];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].n.push_back(b);
        V[b].n.push_back(a);
    }

    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();

        if (T[t.first][t.second % 2])
            continue;
        T[t.first][t.second % 2] = true;
        int c = t.second + 1;
        REP(i, V[t.first].n.size())
        {
            int n = V[t.first].n[i];
            if (T[n][c % 2])
                continue;
            q.push(pll(n, c));
        }
    }

    ll o = 0, e = 0;
    REP(i, N)
    {
        if (T[i][0])
            o++;
        if (T[i][1])
            e++;
    }

    ll sum = std::min(o * e, N * (N - 1) / 2);
    cout << sum - M << endl;

    return 0;
}