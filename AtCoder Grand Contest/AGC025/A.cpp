#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll calc(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    ll N;
    cin >> N;
    ll min = INF;
    FOR(i, N, 1)
    {
        ll a = i;
        ll b = N - a;
        min = std::min(min, calc(a) + calc(b));
    }
    cout << min << endl;
    return 0;
}