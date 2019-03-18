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
    ll N, X;
    cin >> N >> X;

    ll sum = N;
    ll a = std::min(X, N - X);
    ll b = std::max(X, N - X);
    while (a > 0)
    {
        ll c = b / a;
        sum += 2 * a * c;
        ll d = b % a;
        b = a;
        a = d;
    }
    sum -= b;
    cout << sum << endl;
    return 0;
}