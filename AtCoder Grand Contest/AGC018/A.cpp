#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, K;
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

string solve()
{
    ll g = A[0];
    REP(i, N)
    {
        g = gcd(g, A[i]);
    }

    REP(i, N)
    {
        ll k = A[i] - K;
        if (k < 0)
            continue;
        if (k % g == 0)
            return "POSSIBLE";
    }
    return "IMPOSSIBLE";
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }

    cout << solve() << endl;
    return 0;
}