#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int calc(int n)
{
    int m = 0;
    while (n > 0)
    {
        m += n % 10;
        n /= 10;
    }
    return m;
}
int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    ll n = 0;
    FOR(i, N + 1, 1)
    {
        int m = calc(i);
        if (A <= m && m <= B)
            n += i;
    }
    cout << n << endl;
    return 0;
}