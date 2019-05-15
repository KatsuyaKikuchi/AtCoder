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

    ll sum = 0;
    for (ll i = 1; i * i <= N; ++i)
    {
        {
            ll a = N / i;
            ll b = N % i;
            if (a == b)
                sum += i;
        }
        {
            ll a = (N - i) / i;
            if (a != 0)
            {
                if (N / a == N % a)
                    sum += a;
            }
        }
    }
    cout << sum << endl;
    return 0;
}