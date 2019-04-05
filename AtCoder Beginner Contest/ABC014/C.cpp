#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[1000005];

int main()
{
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    REP(i, N)
    {
        ll l, r;
        cin >> l >> r;
        S[l]++;
        S[r + 1]--;
    }
    ll max = S[0];
    FOR(i, 1000005, 1)
    {
        S[i] += S[i - 1];
        max = std::max(max, S[i]);
    }
    cout << max << endl;
    return 0;
}