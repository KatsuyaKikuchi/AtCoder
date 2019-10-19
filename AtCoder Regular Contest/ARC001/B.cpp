#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[10] = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2};

int main()
{
    ll A, B;
    cin >> A >> B;
    ll d = abs(B - A);
    ll ans = d / 10 + C[d % 10];
    cout << ans << endl;
    return 0;
}