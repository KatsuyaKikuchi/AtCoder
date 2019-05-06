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
    int N;
    cin >> N;
    ll p = 0, m = 1;
    REP(i, N)
    {
        char c;
        ll a;
        cin >> c >> a;
        if (c == '+')
            p += a;
        else if (c == '*' && a != 0)
            m *= a;
    }
    cout << p * m << endl;
    return 0;
}