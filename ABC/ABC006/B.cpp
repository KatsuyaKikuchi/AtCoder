#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 10007;
const ll INF = (ll)1e15;

ll T[1000005];

int main()
{
    ll N;
    cin >> N;
    T[0] = T[1] = 0;
    T[2] = 1;
    FOR(i, N, 3)
    {
        T[i] = (T[i - 1] + T[i - 2] + T[i - 3]) % MOD;
    }
    cout << T[N - 1] << endl;
    return 0;
}