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
    ll N;
    cin >> N;
    FOR(h, 3501, 1)
    {
        FOR(n, 3501, 1)
        {
            ll A = N * h * n;
            ll B = 4 * h * n - N * (n + h);
            if (B <= 0)
                continue;
            if (A % B == 0)
            {
                cout << h << " " << n << " " << A / B << endl;
                return 0;
            }
        }
    }
    return 0;
}