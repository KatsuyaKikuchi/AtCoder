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
    ll cost;
    pll g;
};

string Map[1005];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    pll s;
    REP(i, H)
    {
        cin >> Map[i];
        REP(j, W)
        {
            if (Map[i][j] == 'S')
                s = pll(i, j);
        }
    }

    ll ans = 0;
    FOR(n, N + 1, 1)
    {
        queue<Node> q;
        q.push(Node(s, 0));
        vector<bool> U(H * W, false);
        U[s.first * W + s.second] = true;
        while (!q.empty())
        {
            Node t = q.front();
            q.pop();
            if (Map[t.g.first][t.g.second] - '0' == n)
            {
                s = t.g;
                ans += t.cost;
                break;
            }
            REP(i, 4)
            {
                int nx = t.g.first + x[i], ny = t.g.second + y[i];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                if (U[nx * W + ny])
                    continue;
                if (Map[nx][ny] == 'X')
                    continue;
                U[nx * W + ny] = true;
                q.push(Node(pll(nx, ny), t.cost + 1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}