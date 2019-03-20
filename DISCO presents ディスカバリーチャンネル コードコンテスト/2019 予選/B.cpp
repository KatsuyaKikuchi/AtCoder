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
    if (N % 2 == 0)
    {
        ll n = N / 2;
        cout << n * (n - 1) * 2 << endl;
    }
    else
    {
        ll n = N - 2;
        ll sum = 0;
        for (int i = 1; i < n; i += 2)
        {
            sum += i;
        }
        cout << 2 * sum + n << endl;
    }

    return 0;
}