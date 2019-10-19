#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105][105];
ll B[105][105];

ll cost(pll l, pll r)
{
    ll a = A[r.first + 1][r.second + 1] - (A[r.first + 1][l.second] + A[l.first][r.second + 1]) + A[l.first][l.second];
    ll b = B[r.first + 1][r.second + 1] - (B[r.first + 1][l.second] + B[l.first][r.second + 1]) + B[l.first][l.second];
    if (a != b)
        return 0;
    return (r.first + 1 - l.first) * (r.second + 1 - l.second);
}

int main()
{
    ll H, W;
    cin >> H >> W;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    REP(i, H)
    {
        REP(j, W)
        {
            ll c;
            cin >> c;
            if ((i + j) % 2 == 0)
                A[i + 1][j + 1] = c;
            else
                B[i + 1][j + 1] = c;
        }
    }

    FOR(i, H + 1, 1)
    {
        FOR(j, W + 1, 1)
        {
            A[i + 1][j] += A[i][j];
            B[i + 1][j] += B[i][j];
        }
    }
    FOR(j, W + 1, 1)
    {
        FOR(i, H + 1, 1)
        {
            A[i][j + 1] += A[i][j];
            B[i][j + 1] += B[i][j];
        }
    }

    ll max = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            pll l(i, j);
            FOR(x, H, i)
            {
                FOR(y, W, j)
                {
                    pll r(x, y);
                    max = std::max(max, cost(l, r));
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}