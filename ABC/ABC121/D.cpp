#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll calc(ll n, ll t)
{
    ll x = (n / t) * (t / 2);
    ll y = std::max((n % t) - t / 2 + 1, 0LL);
    return x + y;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    ll t = 1;
    REP(i, 45)
    {
        if (t > B)
            break;
        t *= 2;
        ll n = calc(B, t) - calc(A - 1, t);
        ans |= (n % 2) << i;
    }
    cout << ans << endl;
    return 0;
}