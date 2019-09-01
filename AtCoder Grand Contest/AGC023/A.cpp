#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<ll, ll> M;

int main()
{
    ll N;
    cin >> N;
    ll ans = 0;
    ll s = 0;
    M[s]++;
    REP(i, N)
    {
        ll a;
        cin >> a;
        s += a;
        ans += M[s];
        M[s]++;
    }
    cout << ans << endl;
    return 0;
}