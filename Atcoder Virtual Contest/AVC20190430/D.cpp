#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
ll S[200005];
map<ll, ll> m;

int main()
{
    int N;
    cin >> N;
    memset(S, 0, sizeof(S));
    REP(i, N)
    {
        cin >> A[i];
        S[i] = A[i];
    }

    REP(i, N - 1)
    {
        S[i + 1] += S[i];
    }
    m[0]++;
    ll ans = 0;
    REP(i, N)
    {
        ans += m[S[i]];
        m[S[i]]++;
    }
    cout << ans << endl;
    return 0;
}