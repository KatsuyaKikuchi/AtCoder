#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;
ll A[200005];
int main()
{
    ll N;
    string X;
    cin >> N >> X;
    FOR(n, 11, 2)
    {
        ll m = 0;
        REP(i, X.size())
        {
            ll a = (ll)(X[X.size() - 1 - i] - '0');
            m += a * pow(n, i);
        }
        if (m == N)
        {
            cout << n << endl;
            break;
        }
    }
    return 0;
}
