#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll s = (b / x) - (std::max(a - 1, (ll)0) / x);
    if (a == 0)
        s++;
    cout << s << endl;
    return 0;
}