#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    memset(U, 0, sizeof(U));
    REP(i, N)
    {
        ll a, b;
        cin >> a >> b;
        ll t = i - (a + b);
        if (t < M && t >= 0)
            U[t] = true;
    }

    ll ans = 0;
    REP(i, M)
    {
        if (U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}