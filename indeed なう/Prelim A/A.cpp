#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll num(ll n)
{
    ll m = 0;
    while (n > 0)
    {
        n /= 10;
        m++;
    }
    return m;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    cout << num(A) * num(B) << endl;
    return 0;
}