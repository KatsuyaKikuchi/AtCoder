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
    ll N, M;
    cin >> N >> M;

    REP(i, N + 1)
    {
        //! 老人の数を固定
        ll m = M - 3 * i;
        if (m < 0)
            break;
        if (m % 2 == 1)
            continue;
        ll j = (2 * (N - i) - m / 2);
        ll k = N - i - j;
        if (j >= 0 && k >= 0)
        {
            cout << j << " " << i << " " << k << endl;
            return 0;
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}