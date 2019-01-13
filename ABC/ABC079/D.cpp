#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[15][15];
//! iを1に変えるのに必要な魔力の最小値
ll T[15];

struct Node
{
    Node(ll c, int i)
        : cost(c), i(i)
    {
    }
    ll cost;
    int i;
};

int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, 10)
    {
        REP(j, 10)
        {
            cin >> C[i][j];
        }
        T[i] = INF;
    }

    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> q([](Node a, Node b) { return a.cost > b.cost; });
    q.push(Node(0, 1));
    while (!q.empty())
    {
        Node t = q.top();
        q.pop();
        if (T[t.i] <= t.cost)
            continue;
        T[t.i] = t.cost;
        REP(i, 10)
        {
            if (T[i] <= t.cost + C[i][t.i])
                continue;
            q.push(Node(t.cost + C[i][t.i], i));
        }
    }

    ll sum = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            int a;
            cin >> a;
            if (a == -1)
                continue;
            sum += T[a];
        }
    }
    cout << sum << endl;
    return 0;
}