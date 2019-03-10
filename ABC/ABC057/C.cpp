#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll calc(ll n)
{
    int t = 0;
    while (n > 0)
    {
        t++;
        n /= 10;
    }
    return t;
}

int main()
{
    ll N;
    cin >> N;
    ll min = INF;
    for (ll i = 1; i * i <= N; ++i)
    {
        if (N % i != 0)
            continue;
        min = std::min(min, std::max(calc(i), calc(N / i)));
    }
    cout << min << endl;
    return 0;
}