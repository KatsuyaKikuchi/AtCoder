#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[105];
ll A[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N - 1)
    {
        cin >> B[i];
    }
    memset(A, 0, sizeof(A));
    REP(i, N - 2)
    {
        ll a = std::min(B[i], B[i + 1]);
        A[i + 1] = a;
    }
    A[0] = B[0];
    A[N - 1] = B[N - 2];
    ll s = 0;
    REP(i, N)
    {
        s += A[i];
    }
    cout << s << endl;
    return 0;
}