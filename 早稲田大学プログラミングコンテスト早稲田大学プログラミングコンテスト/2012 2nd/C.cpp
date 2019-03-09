#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N, M;
string C[50];
int x[4] = {1, -1, 1, -1};
int y[4] = {1, 1, -1, -1};

int solve(int n, int m)
{
    int s[4] = {0, 0, 0, 0};
    bool e[4] = {false, false, false, false};
    REP(i, N)
    {
        int t[4] = {0, 0, 0, 0};
        REP(j, i + 1)
        {
            REP(k, 4)
            {
                int nx = n + x[k] * i;
                int ny = m + y[k] * j;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || C[nx][ny] == 'X')
                {
                    e[k] = true;
                    continue;
                }
                if (e[k])
                    continue;
                t[k] += (int)(C[nx][ny] - '0');
            }
        }
        REP(j, 4)
        {
            if (e[j])
                continue;
            s[j] += t[j];
        }
    }
    int max = 0;
    REP(i, 4)
    {
        max = std::max(s[i], max);
    }
    return max;
}

int main()
{
    cin >> N >> M;
    REP(i, N)
    {
        cin >> C[i];
    }

    int max = 0;
    REP(i, N)
    {
        REP(j, M)
        {
            max = std::max(max, solve(i, j));
        }
    }
    cout << max << endl;
    return 0;
}