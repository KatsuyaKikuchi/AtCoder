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
    ll K, A, B;
    cin >> K >> A >> B;

    ll s = std::min(K, A - 1);
    ll n = s + 1;
    K -= s;

    n += (K / 2) * std::max((ll)2, B - A) + K % 2;
    cout << n << endl;
    return 0;
}