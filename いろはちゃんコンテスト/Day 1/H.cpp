#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll sumn(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ll N;
    cin >> N;
    ll sum = sumn(N);
    ll ans = 0;
    ll t = 1;
    while (sum > 0)
    {
        ll s = std::min(9LL, sum);
        sum -= s;
        ans += t * s;
        t *= 10;
    }

    if (ans == N)
    {
        while (true)
        {
            if (t == 1 || (ans / t) % 10 == 9)
            {
                ans -= t;
                ans += t * 10;
                break;
            }
            t /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}