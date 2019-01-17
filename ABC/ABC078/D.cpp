#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[2005];

//! [自分がiを引いた時の]=(最大値、最小値)
pll dp[2005];

int main()
{
    ll N, Z, W;
    cin >> N >> Z >> W;
    A[0] = W;
    REP(i, N)
    {
        cin >> A[i + 1];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        pll m(-INF, INF);
        for (int j = i + 1; j < N; ++j)
        {
            m.first = std::max(m.first, dp[j].second);
            m.second = std::min(m.second, dp[j].first);
        }
        dp[i].first = std::max(abs(A[N] - A[i]), m.first);
        dp[i].second = std::min(abs(A[N] - A[i]), m.second);
    }
    cout << dp[0].first << endl;
    return 0;
}