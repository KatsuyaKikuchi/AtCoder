#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005];

int main()
{
    ll N, X;
    cin >> N >> X;
    ll max = 0;
    REP(i, N)
    {
        cin >> A[i];
        max = std::max(max, A[i]);
    }

    ll ans = 0;
    REP(i, N)
    {
        if (A[i] + X >= max)
            ans++;
    }
    cout << ans << endl;
    return 0;
}