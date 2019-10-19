#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[10005];
ll P[10005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i];
    }
    P[1] = 1;
    FOR(i, 10000, 1)
    {
        P[i + 1] = P[i] * (i + 1) % MOD;
    }
    sort(T, T + N);
    ll min = 0;
    ll s = 0;
    ll p = 1;
    ll m = 1;
    REP(i, N)
    {
        s += T[i];
        min += s;
        if (i == N - 1 || T[i] != T[i + 1])
        {
            p = (p * P[m]) % MOD;
            m = 0;
        }
        m++;
    }
    cout << min << endl;
    cout << p << endl;
    return 0;
}