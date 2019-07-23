#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    vector<ll> dp;
    REP(i, N + 1)
    {
        dp.push_back(INF);
    }
    REP(i, N)
    {
        int index = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[index] = A[i];
    }

    int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << ans << endl;
    return 0;
}