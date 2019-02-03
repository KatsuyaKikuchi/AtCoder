#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[55];

//! [i番目に][L[j]を置いて][前回置いたものがL[k]][コストがcとなるような]=最大の長さ
ll dp0[55][55][55][55];
ll dp1[55][55][55][55];

//ll dp0[15][15][15][15];
//ll dp1[15][15][15][15];

int main()
{
    int N, C;
    cin >> N >> C;
    REP(i, N)
    {
        cin >> A[i].first;
    }
    REP(i, N)
    {
        cin >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });

    //! 奇数番目が小さくなるような門松列
    FOR(i, C + 1, 1)
    {
        REP(j, N)
        {
            REP(k, C + 1)
            {
                REP(m, N)
                {
                    dp0[i][j][m][k] = -1;
                    if (k - A[j].second < 0)
                        continue;
                    if (i % 2 == 0 && A[m].first >= A[j].first)
                        continue;
                    else if (i % 2 == 1 && A[m].first <= A[j].first)
                        continue;
                    REP(n, N)
                    {
                        if (i > 2 && A[n].first == A[j].first)
                            continue;
                        if (dp0[i - 1][m][n][k - A[j].second] == -1)
                            continue;
                        dp0[i][j][m][k] = std::max(dp0[i][j][m][k], dp0[i - 1][m][n][k - A[j].second] + A[j].first);
                    }
                }
            }
        }
    }
    //! 偶数番目が小さくなるような門松列
    FOR(i, C + 1, 1)
    {
        REP(j, N)
        {
            REP(k, C + 1)
            {
                REP(m, N)
                {
                    dp1[i][j][m][k] = -1;
                    if (k - A[j].second < 0)
                        continue;
                    if (i % 2 == 0 && (A[m].first <= A[j].first))
                        continue;
                    else if (i % 2 == 1 && A[m].first >= A[j].first)
                        continue;

                    REP(n, N)
                    {
                        if (i > 2 && A[n].first == A[j].first)
                            continue;
                        if (dp1[i - 1][m][n][k - A[j].second] == -1)
                            continue;
                        dp1[i][j][m][k] = std::max(dp1[i][j][m][k], dp1[i - 1][m][n][k - A[j].second] + A[j].first);
                    }
                }
            }
        }
    }

    ll max = 0;
    FOR(i, C + 1, 3)
    {
        REP(j, N)
        {
            REP(k, C + 1)
            {
                REP(n, N)
                {
                    max = std::max(dp0[i][j][n][k], max);
                    max = std::max(dp1[i][j][n][k], max);
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}