#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[1005];
ll T[1005][1005];
struct Node
{
    pll g;
    int c = 0;
    Node(pll g, int c) : g(g), c(c) {}
};

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        REP(j, W)
        {
            T[i][j] = INF;
        }
    }
    queue<Node> q;
    REP(i, H)
    {
        cin >> M[i];
        REP(j, W)
        {
            if (M[i][j] == '#')
            {
                T[i][j] = 0;
                q.push(Node(pll(i, j), 0));
            }
        }
    }

    while (!q.empty())
    {
        Node t = q.front();
        q.pop();
        REP(i, 4)
        {
            int nx = t.g.first + x[i];
            int ny = t.g.second + y[i];
            ll c = t.c + 1;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (T[nx][ny] <= c)
                continue;
            T[nx][ny] = c;
            q.push(Node(pll(nx, ny), c));
        }
    }

    ll max = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            max = std::max(max, T[i][j]);
        }
    }
    cout << max << endl;
    return 0;
}