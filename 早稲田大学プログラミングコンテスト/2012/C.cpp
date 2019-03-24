#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Grid
{
    Grid(pll g, ll c) : g(g), cost(c)
    {
    }
    pll g;
    ll cost;
};

string Map[505];
bool U[505][505];
pll S, C, G;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> Map[i];
        REP(j, M)
        {
            if (Map[i][j] == 'S')
            {
                S.first = i;
                S.second = j;
            }
            if (Map[i][j] == 'C')
            {
                C.first = i;
                C.second = j;
            }
            if (Map[i][j] == 'G')
            {
                G.first = i;
                G.second = j;
            }
        }
    }

    ll sum = 0;
    {
        REP(i, N)
        {
            REP(j, M)
            {
                U[i][j] = false;
            }
        }
        queue<Grid> q;
        q.push(Grid(S, 0));
        U[S.first][S.second] = true;
        while (!q.empty())
        {
            Grid g = q.front();
            q.pop();
            if (Map[g.g.first][g.g.second] == 'C')
            {
                sum += g.cost;
                break;
            }
            REP(i, 4)
            {
                int nx = x[i] + g.g.first;
                int ny = y[i] + g.g.second;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (U[nx][ny])
                    continue;
                if (Map[nx][ny] == '#')
                    continue;
                U[nx][ny] = true;
                q.push(Grid(pll(nx, ny), g.cost + 1));
            }
        }
        if (!U[C.first][C.second])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    {
        REP(i, N)
        {
            REP(j, M)
            {
                U[i][j] = false;
            }
        }
        queue<Grid> q;
        q.push(Grid(C, 0));
        U[C.first][C.second] = true;
        while (!q.empty())
        {
            Grid g = q.front();
            q.pop();
            if (Map[g.g.first][g.g.second] == 'G')
            {
                sum += g.cost;
                break;
            }
            REP(i, 4)
            {
                int nx = x[i] + g.g.first;
                int ny = y[i] + g.g.second;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (U[nx][ny])
                    continue;
                if (Map[nx][ny] == '#')
                    continue;
                U[nx][ny] = true;
                q.push(Grid(pll(nx, ny), g.cost + 1));
            }
        }
        if (!U[G.first][G.second])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << sum << endl;
    return 0;
}