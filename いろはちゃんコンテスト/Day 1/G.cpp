#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[405];
ll dp0[405][405];
ll dp1[405][405];

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    memset(dp0, -1, sizeof(dp0));
    dp0[0][0] = 0;
    REP(i, N)
    {
        memset(dp1, -1, sizeof(dp1));
        REP(j, std::min(M + 1, i + 1))
        {
            ll max = -1;
            REP(k, K)
            {
                dp1[j][k + 1] = dp0[j][k];
                max = std::max(max, dp0[j][k]);
            }
            if (max >= 0)
                dp1[j + 1][0] = max + A[i];
            else
                dp1[j + 1][0] = -1;
        }
        swap(dp0, dp1);
    }

    ll ans = -1;
    REP(i, K)
    {
        ans = std::max(dp0[M][i], ans);
    }
    cout << ans << endl;
    return 0;
}