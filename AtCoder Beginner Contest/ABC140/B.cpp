#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[25];
ll A[25];

int main()
{
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        A[a - 1] = i;
    }
    REP(i, N)
    {
        ll b;
        cin >> b;
        ans += b;
    }
    REP(i, N - 1)
    {
        cin >> C[i];
    }
    FOR(i, N, 1)
    {
        if (A[i] == A[i - 1] + 1)
            ans += C[i - 1];
    }
    cout << ans << endl;
    return 0;
}