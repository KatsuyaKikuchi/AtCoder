#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[105];
//! [i問目まで解いた時][得点をjに]=できるか
bool dp[105][10005] = {false};

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> P[i];
    }
    dp[0][0] = true;
    ll sum = 0;
    REP(i, N)
    {
        sum += P[i];
        REP(j, sum + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - P[i] >= 0 && dp[i][j - P[i]])
                dp[i + 1][j] = true;
        }
    }

    ll ans = 0;
    REP(i, sum + 1)
    {
        if (dp[N][i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}