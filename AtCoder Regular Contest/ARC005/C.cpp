#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[505];
ll M[505][505][5];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

struct Node
{
    ll x;
    ll y;
    ll cost;
    ll b;
};

int main()
{
    ll H, W;
    cin >> H >> W;
    pll s, g;
    REP(i, H)
    {
        cin >> S[i];
        REP(j, W)
        {
            if (S[i][j] == 's')
                s = pll(i, j);
            if (S[i][j] == 'g')
                g = pll(i, j);

            REP(k, 3)
            {
                M[i][j][k] = INF;
            }
        }
    }

    M[s.first][s.second][0] = 0;
    queue<Node> q;
    q.push(Node{s.first, s.second, 0, 0});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        ll cost = t.cost + 1;
        REP(i, 4)
        {
            ll nx = t.x + x[i];
            ll ny = t.y + y[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (S[nx][ny] == '#')
            {
                if (t.b >= 2)
                    continue;
                if (M[nx][ny][t.b + 1] <= cost)
                    continue;
                M[nx][ny][t.b + 1] = cost;
                q.push(Node{nx, ny, cost, t.b + 1});
            }
            else
            {
                if (M[nx][ny][t.b] <= cost)
                    continue;
                M[nx][ny][t.b] = cost;
                q.push(Node{nx, ny, cost, t.b});
            }
        }
    }

    ll min = INF;
    REP(i, 3)
    {
        min = std::min(M[g.first][g.second][i], min);
    }
    if (min == INF)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}