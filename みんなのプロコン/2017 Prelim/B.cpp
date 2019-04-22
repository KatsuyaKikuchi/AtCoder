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
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    ll sum = 0;
    REP(i, K)
    {
        sum += A[i] + i;
    }
    cout << sum << endl;
    return 0;
}