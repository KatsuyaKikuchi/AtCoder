#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[1005][1005];
pll nx[4] = {pll(2, 1), pll(-1, 2), pll(-2, -1), pll(1, -2)};
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int main()
{
    int N;
    cin >> N;

    queue<pll> q;
    q.push(pll(0, 0));
    U[0][0] = true;
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        REP(i, 4)
        {
            pll n = pll(t.first + nx[i].first, t.second + nx[i].second);
            if (n.first < 0 || n.first >= N || n.second < 0 || n.second >= N)
                continue;
            if (U[n.first][n.second])
                continue;
            U[n.first][n.second] = true;
            q.push(n);
        }
    }

    REP(i, N)
    {
        REP(j, N)
        {
            if (U[i][j])
            {
                cout << 'X';
                continue;
            }
            char c = 'X';
            REP(k, 4)
            {
                int nx = i + x[k], ny = j + y[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (U[nx][ny])
                {
                    c = '.';
                    break;
                }
            }
            cout << c;
        }
        cout << endl;
    }

    return 0;
}