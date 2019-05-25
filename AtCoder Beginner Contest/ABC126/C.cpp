#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(15)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N, K;
    cin >> N >> K;
    double ans = 0;
    FOR(i, N + 1, 1)
    {
        ll n = i;
        int t = 0;
        while (n < K)
        {
            n *= 2;
            t++;
        }

        ans += 1 / ((double)pow(2, t) * (double)(N));
    }
    cout << OF64 << ans << endl;
    return 0;
}