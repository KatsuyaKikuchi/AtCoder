#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, M;
pll s, g;
string S[505];
double P[250005];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
bool U[505][505];

struct Node
{
    int x;
    int y;
    int cost;
    Node(int x, int y, int c) : x(x), y(y), cost(c) {}
};

bool check(double d)
{
    memset(U, 0, sizeof(U));
    queue<Node> q;
    q.push(Node(s.first, s.second, 0));
    U[s.first][s.second] = true;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (t.x == g.first && t.y == g.second)
            return true;
        ll cost = t.cost + 1;
        REP(i, 4)
        {
            int nx = t.x + x[i], ny = t.y + y[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            double p = P[cost] * (S[nx][ny] - '0');
            if (p < d)
                continue;
            if (U[nx][ny] || S[nx][ny] == '#')
                continue;
            U[nx][ny] = true;
            q.push(Node(nx, ny, cost));
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    REP(i, N)
    {
        cin >> S[i];
        REP(j, M)
        {
            if (S[i][j] == 's')
                s = pll(i, j);
            if (S[i][j] == 'g')
                g = pll(i, j);
        }
    }
    P[0] = 1;
    REP(i, N * M + 1)
    {
        P[i + 1] = P[i] * 0.99;
    }

    double ok = -1, ng = 10;
    bool e = false;
    REP(i, 150)
    {
        double mid = (ok + ng) * 0.5;
        if (check(mid))
        {
            ok = mid;
            e = true;
        }
        else
            ng = mid;
    }

    if (!e)
        cout << -1 << endl;
    else
        cout << OF64 << ok << endl;
    return 0;
}