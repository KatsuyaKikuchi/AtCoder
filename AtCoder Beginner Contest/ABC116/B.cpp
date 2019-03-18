#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll func(int n)
{
    if (n % 2 == 0)
        return n / 2;
    return 3 * n + 1;
}

int main()
{
    ll S;
    cin >> S;
    map<ll, int> m;
    m[S] = 1;
    FOR(i, 1000001, 2)
    {
        S = func(S);
        if (m[S] > 0)
        {
            cout << i << endl;
            break;
        }
        m[S] = 1;
    }
    return 0;
}