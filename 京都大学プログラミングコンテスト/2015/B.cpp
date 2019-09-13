#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int z[3] = {-1, 0, 1};

ll dfs(vector<string> N, ll h, ll w)
{
    if (N[h][w] == 'X')
        return 0;
    if (w >= 9)
    {
        return 1;
    }

    ll s = 0;
    REP(i, 3)
    {
        ll nh = h + z[i];
        if (nh < 0 || nh >= 10)
            continue;
        if (N[h][w] == 'X')
            continue;
        s += dfs(N, nh, w + 1);
        if (s > 1)
            break;
    }
    return s;
}

int main()
{
    // REP(i, 10)
    // {
    //     cout << N[i];
    //     if (i % 10 == 9)
    //         cout << endl;
    // }
    string N[10] = {
        "..........",
        "C.........",
        "..........",
        ".........C",
        "..........",
        "..........",
        "C.........",
        "..........",
        ".......C..",
        ".........."};
    REP(i, 10)
    {
        cout << N[i] << endl;
        ;
    }
#if false
    ll S = 100;
    FOR(a, S, 0)
    {
        cout << a << endl;
        FOR(b, S, a + 1)
        {
            FOR(c, S, b + 1)
            {
                FOR(d, S, c + 1)
                {
                    vector<string> M;
                    vector<string> N;
                    REP(e, 10)
                    {
                        M.push_back("..........");
                        N.push_back("..........");
                    }

                    M[a % 10][a / 10] = 'C';
                    M[b % 10][b / 10] = 'C';
                    M[c % 10][c / 10] = 'C';
                    M[d % 10][d / 10] = 'C';

                    REP(i, 10)
                    {
                        REP(j, 10)
                        {
                            if (M[i][j] != 'C')
                            {
                                continue;
                            }

                            REP(a, 3)
                            {
                                REP(b, 8)
                                {
                                    ll nx = i + x[b] * a;
                                    ll ny = j + y[b] * a;
                                    if (nx < 0 || ny < 0 || nx > 9 || ny > 9)
                                        continue;
                                    N[nx][ny] = 'X';
                                }
                            }
                        }
                    }

                    ll s = 0;
                    REP(i, 10)
                    {
                        s += dfs(N, i, 0);
                        if (s > 1)
                            break;
                    }

                    if (s > 1 || s == 0)
                        continue;

                    REP(i, 10)
                    {
                        cout << M[i] << endl;
                    }
                    return 0;
                }
            }
        }
    }
#endif
    return 0;
}