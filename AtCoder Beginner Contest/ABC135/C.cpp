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
    REP(i, N + 1)
    {
        cin >> A[i];
    }
    ll ans = 0;
    REP(i, N)
    {
        ll b;
        cin >> b;
        ll m = std::min(b, A[i]);
        b -= m;
        ll n = std::min(b, A[i + 1]);
        A[i + 1] -= n;
        ans += m + n;
    }
    cout << ans << endl;
    return 0;
}