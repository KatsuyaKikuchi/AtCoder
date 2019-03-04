#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[15];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
pll s, g;
int H, W;
ll T;
ll C[20][20];

struct Node
{
    Node(int x, int y, ll c) : x(x), y(y), cost(c) {}
    int x;
    int y;
    ll cost;
};

bool check(ll z)
{
    REP(i, H)
    {
        REP(j, W)
        {
            C[i][j] = INF;
        }
    }
    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> q([](Node a, Node b) { return a.cost > b.cost; });
    q.push(Node(s.first, s.second, 0));
    C[s.first][s.second] = 0;
    while (!q.empty())
    {
        Node t = q.top();
        q.pop();
        if (C[t.x][t.y] < t.cost)
            continue;
        REP(i, 4)
        {
            int nx = x[i] + t.x;
            int ny = y[i] + t.y;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            ll cost = t.cost;
            if (M[nx][ny] == '#')
                cost += z;
            else
                cost += 1;
            if (C[nx][ny] <= cost)
                continue;
            q.push(Node(nx, ny, cost));
            C[nx][ny] = cost;
        }
    }
    return C[g.first][g.second] <= T;
}

int main()
{
    cin >> H >> W;
    cin >> T;
    REP(i, H)
    {
        cin >> M[i];
    }

    REP(i, H)
    {
        REP(j, W)
        {
            if (M[i][j] == 'S')
                s = pll(i, j);
            if (M[i][j] == 'G')
                g = pll(i, j);
        }
    }

    ll ok = 1, ng = T;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}