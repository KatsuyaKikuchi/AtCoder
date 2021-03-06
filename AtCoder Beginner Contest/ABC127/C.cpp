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
    memset(S, 0, sizeof(S));
    REP(i, M)
    {
        ll l, r;
        cin >> l >> r;
        S[l - 1]++;
        S[r]--;
    }
    REP(i, N)
    {
        S[i + 1] += S[i];
    }
    ll ans = 0;
    REP(i, N)
    {
        if (S[i] >= M)
            ans++;
    }
    cout << ans << endl;
    return 0;
}