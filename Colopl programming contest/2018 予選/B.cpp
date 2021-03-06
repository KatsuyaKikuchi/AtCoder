#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005];

int main()
{
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    REP(i, N)
    {
        cin >> T[i];
    }
    ll ans = 0;
    REP(i, N)
    {
        if (S[i] == '0')
            ans += T[i];
        else
            ans += std::min(T[i], X);
    }
    cout << ans << endl;
    return 0;
}