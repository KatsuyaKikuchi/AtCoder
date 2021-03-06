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
    int N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    ll sum = 0;
    REP(i, K)
    {
        sum += A[i];
    }
    ll max = sum;
    FOR(i, N, K)
    {
        sum += A[i] - A[i - K];
        max = std::max(max, sum);
    }
    cout << max << endl;
    return 0;
}