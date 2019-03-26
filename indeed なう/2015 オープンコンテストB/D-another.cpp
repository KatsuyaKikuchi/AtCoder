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
    Node(pll g, ll c) : g(g), cost(c) {}
    pll g;
    ll cost;
};

ll M[105][105];
bool U[105][105];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

//1 プリム法で解く
int main()
{
    ll H, W;
    cin >> H >> W;
    pll s, g;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    ll sum = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            cin >> M[h][w];
            sum += M[h][w];
        }
    }
    s.first--;
    s.second--;
    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> q([](Node a, Node b) { return a.cost < b.cost; });
    q.push(Node(pll(s.second, s.first), 0));
    while (!q.empty())
    {
        Node t = q.top();
        q.pop();
        if (U[t.g.first][t.g.second])
            continue;
        sum += t.cost;
        U[t.g.first][t.g.second] = true;
        REP(i, 4)
        {
            int nx = x[i] + t.g.first;
            int ny = y[i] + t.g.second;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (U[nx][ny])
                continue;
            ll cost = M[nx][ny] * M[t.g.first][t.g.second];
            q.push(Node(pll(nx, ny), cost));
        }
    }
    cout << sum << endl;
    return 0;
}