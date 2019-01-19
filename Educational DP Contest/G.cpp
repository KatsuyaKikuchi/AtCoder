#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Node
{
    int in = 0;
    vector<int> next;
    ll length = 0;
};

bool S[100005];
Node V[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        V[x].next.push_back(y);
        V[y].in++;
        S[y] = true;
    }

    queue<Node> q;
    REP(i, N)
    {
        if (S[i])
            continue;
        q.push(V[i]);
    }

    while (!q.empty())
    {
        Node n = q.front();
        q.pop();
        REP(i, n.next.size())
        {
            if (--V[n.next[i]].in > 0)
                continue;
            if (V[n.next[i]].length >= n.length + 1)
                continue;
            V[n.next[i]].length = n.length + 1;
            q.push(V[n.next[i]]);
        }
    }
    ll max = 0;
    REP(i, N)
    {
        max = std::max(max, V[i].length);
    }
    cout << max << endl;
    return 0;
}