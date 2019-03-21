#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int dp[4005][4005];

int main()
{
    string A, B;
    cin >> A >> B;

    for (int i = A.length() - 1; i >= 0; --i)
    {
        REP(j, B.length())
        {
            dp[i][j] = 0;
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
        }
    }
    int max = 0;
    REP(i, A.length())
    {
        REP(j, B.length())
        {
            max = std::max(max, dp[i][j]);
        }
    }
    cout << max << endl;
    return 0;
}