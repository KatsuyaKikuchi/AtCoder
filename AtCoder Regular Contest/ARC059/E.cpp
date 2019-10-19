#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[401];
int B[401];
//! [iの][j乗]
ll S[401][401];
//! [iから][jの][k乗]を足したもの
int T[401][401][401];

int dp[401][401];

int main()
{
    ll N, C;
    cin >> N >> C;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }
    memset(S, 0, sizeof(S));
    memset(T, 0, sizeof(T));
    memset(dp, 0, sizeof(dp));
    REP(i, 400)
    {
        ll m = 1;
        REP(j, C + 1)
        {
            S[i + 1][j] = m;
            m = (m * (i + 1)) % MOD;
        }
    }
    REP(i, 400)
    {
        FOR(j, 400, i)
        {
            REP(k, C + 1)
            {
                T[i + 1][j + 1][k] = (T[i + 1][j][k] + S[j + 1][k]) % MOD;
            }
        }
    }

    dp[0][0] = 1;
    REP(i, N)
    {
        REP(j, C + 1)
        {
            ll s = 0;
            REP(k, j + 1)
            {
                s += (ll)dp[i][k] * (ll)T[A[i]][B[i]][j - k] % MOD;
                s %= MOD;
            }
            dp[i + 1][j] = s;
        }
    }
    cout << dp[N][C] << endl;
    return 0;
}