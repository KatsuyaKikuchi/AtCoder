#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005];

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
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i];
    }

    ll a = T[0];
    FOR(i, N, 1)
    {
        ll k = gcd(a, T[i]);
        a = a / k * T[i];
    }
    cout << a << endl;

    return 0;
}