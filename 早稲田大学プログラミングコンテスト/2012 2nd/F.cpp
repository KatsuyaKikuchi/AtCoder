#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string Map[105];
pll T[105][105][4][2];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    ll N, M, L;
    cin >> N >> M >> L;
    string S;
    cin >> S;
    REP(i, N)
    {
        REP(j, M)
        {
            REP(k, 4)
            {
                T[i][j][k][0] = T[i][j][k][1] = pll(INF, 0);
            }
        }
    }
    REP(i, N)
    {
        cin >> Map[i];
        REP(j, M)
        {
            if (Map[i][j] != S[0])
                continue;
            REP(k, 4)
            {
                T[i][j][k][0] = pll(1, 0);
            }
        }
    }
    if (N == 1 && M == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    FOR(i, L - 1, 0)
    {
        REP(h, N)
        {
            REP(w, M)
            {
                if (S[i] != Map[h][w])
                    continue;
                REP(k, 4)
                {
                    if (T[h][w][k][i % 2].second != i)
                        continue;
                    int nx = h + x[k], ny = w + y[k];
                    while (nx >= 0 && ny >= 0 && nx < N && ny < M)
                    {
                        if (S[i + 1] == Map[nx][ny])
                        {
                            REP(l, 4)
                            {
                                if (l == k)
                                    continue;
                                ll sum = T[h][w][k][i % 2].first + abs(h - nx) + abs(w - ny);
                                if (T[nx][ny][l][(i + 1) % 2].second != i + 1)
                                    T[nx][ny][l][(i + 1) % 2] = pll(sum, i + 1);
                                else
                                    T[nx][ny][l][(i + 1) % 2] = pll(std::min(sum, T[nx][ny][l][(i + 1) % 2].first), i + 1);
                            }
                            break;
                        }
                        nx += x[k];
                        ny += y[k];
                    }
                }
            }
        }
    }

    ll min = INF;
    REP(h, N)
    {
        REP(w, M)
        {
            REP(k, 4)
            {
                if (T[h][w][k][(L - 1) % 2].second == L - 1)
                    min = std::min(min, T[h][w][k][(L - 1) % 2].first);
            }
        }
    }
    if (min == INF)
        min = -1;
    cout << min << endl;
    return 0;
}