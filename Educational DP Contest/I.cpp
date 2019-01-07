#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double p[3005];
//! [i番目まで見たとき][面がnマイ出る]=確率
double dp[3005][3005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> p[i];
    }
    dp[0][0] = 1;
    REP(i, N)
    {
        REP(j, N + 1)
        {
            dp[i + 1][j] = dp[i][j] * (1 - p[i]);
            if (j > 0)
                dp[i + 1][j] += dp[i][j - 1] * p[i];
        }
    }

    double s = 0;
    FOR(i, N + 1, N / 2 + 1)
    {
        s += dp[N][i];
    }
    cout << OF64 << s << endl;
    return 0;
}