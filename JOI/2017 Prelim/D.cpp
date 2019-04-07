#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [iまでに存在する][種類jのぬいぐるみ]の数
ll S[100005][25];
ll A[25];
ll dp[1500000];

int main()
{
    ll N, M;
    cin >> N >> M;
    memset(S, 0, sizeof(S));
    memset(A, 0, sizeof(A));
    REP(i, N)
    {
        ll a;
        cin >> a;
        S[i + 1][a - 1]++;
        A[a - 1]++;
    }
    REP(i, N)
    {
        REP(j, M)
        {
            S[i + 1][j] += S[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    ll p = pow(2, M);
    FOR(i, p, 1)
    {
        ll m = INF;
        ll s = 0;
        REP(j, M)
        {
            if (((i >> j) & 1) == 1)
                s += A[j];
        }
        REP(j, M)
        {
            if (((i >> j) & 1) == 0)
                continue;
            ll tmp = A[j] - (S[s][j] - S[s - A[j]][j]) + dp[i & (~(1 << j))];
            m = std::min(m, tmp);
        }
        dp[i] = m;
    }
    cout << dp[p - 1] << endl;
    return 0;
}