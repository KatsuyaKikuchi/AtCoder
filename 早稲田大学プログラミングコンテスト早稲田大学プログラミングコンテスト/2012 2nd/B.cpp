#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll dp[105];

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    dp[0] = 0;
    FOR(i, N, 1)
    {
        ll min = INF;
        for (int j = 1; j <= 3; ++j)
        {
            if (i - j < 0)
                break;
            min = std::min(min, dp[i - j]);
        }
        if (S[i] == 'X')
            min++;
        dp[i] = min;
    }
    cout << dp[N - 1] << endl;
    return 0;
}