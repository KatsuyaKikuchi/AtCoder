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

int main()
{
    ll N, B, C;
    cin >> N >> B >> C;
    REP(i, N)
    {
        cin >> A[i];
    }
    ll sum = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        ll t = std::min(B, C);
        sum += t * A[i];
        C -= t;
    }
    cout << sum << endl;
    return 0;
}