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
    int N, M;
    cin >> N >> M;
    //! 犬を0番目に
    ll d = 1;
    ll n = N, m = M;
    REP(i, N + M)
    {
        if (i % 2 == 0)
            d *= n--;
        else
            d *= m--;
        d %= MOD;
    }
    //! 猿を0番目に
    n = N;
    m = M;
    ll s = 1;
    REP(i, N + M)
    {
        if (i % 2 == 0)
            s *= m--;
        else
            s *= n--;
        s %= MOD;
    }

    cout << (d + s) % MOD << endl;
    return 0;
}