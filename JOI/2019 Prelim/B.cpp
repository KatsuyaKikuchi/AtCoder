#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[105];

int main()
{
    memset(X, 0, sizeof(X));
    ll N, M;
    cin >> N;
    REP(i, N)
    {
        ll x;
        cin >> x;
        X[i] = x;
    }
    cin >> M;
    REP(i, M)
    {
        ll a;
        cin >> a;
        a--;
        ll s = X[a];
        ll t = X[a + 1];
        if (s == 2019 || s + 1 == t)
            continue;
        X[a]++;
    }
    REP(i, N)
    {
        cout << X[i] << endl;
    }
    return 0;
}