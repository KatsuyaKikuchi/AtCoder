#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    S[0] = 0;
    REP(i, N - 1)
    {
        ll a;
        cin >> a;
        S[i + 1] += S[i] + a;
    }

    ll sum = 0;
    ll m = 0;
    REP(i, M)
    {
        ll a;
        cin >> a;
        sum += abs(S[m + a] - S[m]);
        m += a;
    }
    cout << sum % 100000 << endl;
    return 0;
}