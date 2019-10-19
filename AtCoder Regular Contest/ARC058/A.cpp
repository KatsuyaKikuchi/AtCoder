#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool D[15];

bool solve(ll n)
{
    while (n > 0)
    {
        if (D[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    memset(D, 0, sizeof(D));
    REP(i, K)
    {
        ll d;
        cin >> d;
        D[d] = true;
    }
    while (true)
    {
        if (solve(N))
            break;
        N++;
    }
    cout << N << endl;
    return 0;
}