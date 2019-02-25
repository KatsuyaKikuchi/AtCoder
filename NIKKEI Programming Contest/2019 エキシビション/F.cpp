#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e16;

ll solve(ll n)
{
    if (n < 2 || n >= INF)
        return 0;
    if (n % 2 == 0)
        return solve(n / 2) + 1;
    return solve(3 * n + 1) + 1;
}

int main()
{
    ll P;
    cin >> P;
    ll M = 9999999921753316;
    ll n = solve(M);
    while (--n - P >= 0)
    {
        if (M % 2 == 0)
            M /= 2;
        else
            M = 3 * M + 1;
    }

    cout << M << endl;
    return 0;
}