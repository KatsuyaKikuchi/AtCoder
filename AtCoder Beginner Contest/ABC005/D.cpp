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
ll D[55][55];
//! 縦n,横mの時の美味しさ最大値
ll M[55][55];

ll A[55][55];

void calc(ll h, ll w)
{
    REP(i, N)
    {
        if (h + i >= N)
            continue;
        REP(j, N)
        {
            if (w + j >= N)
                continue;
            ll s = D[h + i][w + j];
            if (h - 1 >= 0)
                s -= D[h - 1][w + j];
            if (w - 1 >= 0)
                s -= D[h + i][w - 1];
            if (h - 1 >= 0 && w - 1 >= 0)
                s += D[h - 1][w - 1];
            M[i + 1][j + 1] = std::max(s, M[i + 1][j + 1]);
        }
    }
}

void calc()
{
    memset(M, 0, sizeof(M));
    REP(i, N)
    {
        REP(j, N)
        {
            D[i + 1][j] += D[i][j];
        }
    }
    REP(i, N)
    {
        REP(j, N)
        {
            D[j][i + 1] += D[j][i];
        }
    }

    REP(i, N)
    {
        REP(j, N)
        {
            calc(i, j);
        }
    }
}

ll solve(ll p)
{
    ll max = 0;
    FOR(h, N + 1, 1)
    {
        ll w = std::min(N, p / h);
        max = std::max(max, M[h][w]);
    }
    return max;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> D[i][j];
        }
    }
    calc();
    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll P;
        cin >> P;
        cout << solve(P) << endl;
    }
    return 0;
}