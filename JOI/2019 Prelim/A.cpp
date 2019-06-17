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
    ll A, B, C;
    cin >> A >> B >> C;
    ll c = C;
    FOR(i, c + 1, 1)
    {
        C -= A;
        if (i % 7 == 0)
            C -= B;
        if (C <= 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}