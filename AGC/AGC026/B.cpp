#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

string solve(ll a, ll b, ll c, ll d)
{
    if (a < b)
        return "No";
    if (d < b)
        return "No";
    if (b <= c)
        return "Yes";

    ll e = gcd(b, d);
    ll f = a % b;
    ll g = (b - f + e - 1) / e - 1;

    if (f + g * e > c)
        return "No";
    return "Yes";
}

int main()
{
    ll T;
    cin >> T;
    REP(i, T)
    {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << solve(A, B, C, D) << endl;
    }
    return 0;
}