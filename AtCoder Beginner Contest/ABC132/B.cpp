#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[104];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> P[i];
    }
    int a = 0;
    FOR(i, N - 1, 1)
    {
        ll x = P[i - 1];
        ll y = P[i];
        ll z = P[i + 1];
        if ((y < z && y > x) || (y < x && y > z))
            a++;
    }
    cout << a << endl;
    return 0;
}