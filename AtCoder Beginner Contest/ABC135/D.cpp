#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[100005][15];
ll m[15];

int main()
{
    memset(dp, 0, sizeof(dp));
    string S;
    cin >> S;
    ll N = S.length();
    REP(i, 10)
    {
        m[i] = i;
    }
    dp[0][0] = 1;
    REP(i, N)
    {
        ll n = S[N - 1 - i] - '0';
        REP(j, 10)
        {
            if (S[N - 1 - i] == '?' || n == j)
            {
                REP(k, 13)
                {
                    dp[i + 1][k] += dp[i][(13 + k - m[j]) % 13];
                    dp[i + 1][k] %= MOD;
                }
            }
            m[j] = (m[j] * 10) % 13;
        }
    }

    cout << dp[N][5] << endl;
    return 0;
}