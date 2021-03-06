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
    ll X;
    cin >> X;
    ll t = 0;
    for (ll n = X; n > 0; n /= 10)
        t += n % 10;

    if (X % t == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}