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

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll S = B - A + 1;
    //! (A,B)のうち、Cで割り切れるもの
    ll c = B / C - (A - 1) / C;
    //! Dでわりきれるもの
    ll d = B / D - (A - 1) / D;
    //! CでもDでもわりきれるもの
    ll g = C * D / gcd(C, D);
    ll cd = B / g - (A - 1) / g;
    cout << S - (c + d) + cd << endl;
    return 0;
}