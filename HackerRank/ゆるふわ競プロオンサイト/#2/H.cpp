#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
string S[8];

ll M[15];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
bool U[6][6];

struct Data
{
    int x;
    int y;
    int c;
};

bool solve(pll g, vector<string> s, int n = 0)
{
    if (n == N)
    {
        return N % 2 == 1;
    }

    memset(U, 0, sizeof(U));
    vector<pll> v;
    queue<Data> q;
    q.push(Data{g.first, g.second, 0});
    while (!q.empty())
    {
        auto d = q.front();
        q.pop();
        ll cost = d.c + 1;
        REP(i, 4)
        {
            int nx = d.x + x[i];
            int ny = d.y + y[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;
            if (U[nx][ny])
                continue;
            U[nx][ny] = true;
            if (cost > M[n])
                continue;
            if (s[nx][ny] == 'B' && cost == M[n])
                v.push_back(pll(nx, ny));
            q.push(Data{nx, ny, cost});
        }
    }

    REP(i, v.size())
    {
        s[v[i].first][v[i].second] = '.';
        bool w = solve(v[i], s, n + 1);
        if (n % 2 == 0)
        {
            if (w)
                return true;
        }
        else
        {
            if (!w)
                return false;
        }

        s[v[i].first][v[i].second] = 'B';
    }

    if (n % 2 == 0)
        return false;
    return true;
}

int main()
{
    cin >> N;
    vector<string> s;
    REP(i, 5)
    {
        string t;
        cin >> t;
        s.push_back(t);
    }
    REP(i, N)
    {
        cin >> M[i];
    }

    pll g;
    REP(i, 5)
    {
        REP(j, 5)
        {
            if (s[i][j] == 'G')
                g = pll(i, j);
        }
    }

    if (solve(g, s))
        cout << "gori" << endl;
    else
        cout << "uho" << endl;
    return 0;
}