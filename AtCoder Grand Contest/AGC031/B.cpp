#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[200005];
ll P[200005];
//! [iまでに]=何通りあるか
ll T[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> C[i];
        P[C[i]] = -1;
    }
    T[0] = 1;
    REP(i, N)
    {
        if (P[C[i]] >= 0 && P[C[i]] != i - 1)
            T[i] = (T[i] + T[P[C[i]]]) % MOD;
        P[C[i]] = i;
        T[i + 1] = T[i];
    }
    cout << T[N] % MOD << endl;
    return 0;
}