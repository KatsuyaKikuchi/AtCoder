#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[10];
ll x[8] = {1, 0, -1, -1, -1, 0, 1, 1};
ll y[8] = {1, 1, 1, 0, -1, -1, -1, 0};
bool paint(vector<string> &m, pll g)
{
    REP(i, 8)
    {
        ll nx = g.first, ny = g.second;
        while (nx < 8 && ny < 8 && nx >= 0 && ny >= 0)
        {
            if (m[nx][ny] == 'Q')
                return false;
            m[nx][ny] = 'x';
            nx += x[i];
            ny += y[i];
        }
    }
    m[g.first][g.second] = 'Q';
    return true;
}

bool dfs(vector<string> m, vector<pll> &v)
{
    if (v.size() == 8)
    {
        return true;
    }
    REP(i, 8)
    {
        REP(j, 8)
        {
            if (m[i][j] != '.')
                continue;

            auto c = m;
            if (paint(c, pll(i, j)))
            {
                v.push_back(pll(i, j));
                if (dfs(c, v))
                    return true;
                v.pop_back();
            }
        }
    }
    return false;
}

int main()
{
    REP(i, 8)
    {
        cin >> M[i];
    }
    vector<pll> v;
    REP(i, 8)
    {
        REP(j, 8)
        {
            if (M[i][j] == 'Q')
                v.push_back(pll(i, j));
        }
    }
    vector<string> m;
    REP(i, 8)
    {
        m.push_back(M[i]);
    }
    REP(i, v.size())
    {
        m[v[i].first][v[i].second] = '.';
        if (!paint(m, v[i]))
        {
            cout << "No Answer" << endl;
            return 0;
        }
    }

    if (dfs(m, v))
    {
        REP(i, v.size())
        {
            pll g = v[i];
            M[g.first][g.second] = 'Q';
        }
        REP(i, 8)
        {
            cout << M[i] << endl;
        }
    }
    else
    {
        cout << "No Answer" << endl;
    }

    return 0;
}