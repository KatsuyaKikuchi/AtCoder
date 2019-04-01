#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

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
    ll N, Z;
    cin >> N >> Z;
    REP(i, N)
    {
        ll a;
        cin >> a;
        A[i] = gcd(a, Z);
    }

    ll s = 1;
    REP(i, N)
    {
        s = (A[i] / gcd(s, A[i])) * s;
    }
    cout << s << endl;
    return 0;
}