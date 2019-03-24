#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[55];
int A[55][55];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int main()
{
    int R, C;
    cin >> R >> C;
    pll s, g;
    cin >> s.first >> s.second;
    s.first--;
    s.second--;
    cin >> g.first >> g.second;
    g.first--;
    g.second--;
    REP(i, R)
    {
        cin >> M[i];
    }
    REP(i, R)
    {
        REP(j, C)
        {
            A[i][j] = -1;
        }
    }
    queue<pll> q;
    q.push(s);
    A[s.first][s.second] = 0;
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        REP(i, 4)
        {
            int nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (M[nx][ny] == '#' || A[nx][ny] >= 0)
                continue;
            q.push(pll(nx, ny));
            A[nx][ny] = A[t.first][t.second] + 1;
        }
    }
    cout << A[g.first][g.second] << endl;
    return 0;
}