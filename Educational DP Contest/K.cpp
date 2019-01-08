#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[105];
//! [i個の石が残っている時]=勝てるか
bool dp[100005];

int main()
{
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, A[0])
    {
        dp[i] = false;
    }
    FOR(i, K + 1, A[0])
    {
        REP(j, N)
        {
            if (i - A[j] < 0)
                break;
            if (!dp[i - A[j]])
            {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[K])
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
    return 0;
}