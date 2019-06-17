#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[100005];

int main()
{
    ll N, X;
    cin >> N >> X;
    REP(i, N)
    {
        cin >> L[i];
    }

    ll D = 0;
    ll ans = 1;
    REP(i, N)
    {
        D += L[i];
        if (D <= X)
            ans++;
    }
    cout << ans << endl;
    return 0;
}