#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];
ll B[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N - 1)
    {
        cin >> B[i];
    }
    memset(A, 0, sizeof(A));
    A[0] = B[0];
    A[N - 1] = B[N - 2];
    FOR(i, N - 1, 1)
    {
        A[i] = std::min(B[i - 1], B[i]);
    }
    ll sum = 0;
    REP(i, N)
    {
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}