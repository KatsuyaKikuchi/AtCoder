#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[100005];

int main()
{
    memset(X, 0, sizeof(X));
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> X[i];
    }
    ll n = 0;
    ll m = 0;
    REP(i, M)
    {
        ll a;
        cin >> a;
        n += a;
        n += X[n];
        if (n >= N - 1 && m == 0)
            m = i + 1;
       // cout << n << endl;
    }
    cout << m << endl;
    return 0;
}