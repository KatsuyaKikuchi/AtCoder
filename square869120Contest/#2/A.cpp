#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[2] = {'I', 'O'};

int main()
{
    string S;
    cin >> S;
    ll ans = 0;
    REP(i, S.length())
    {
        if (S[i] == C[ans % 2])
            ans++;
    }
    if (ans % 2 == 0)
        ans = std::max(ans - 1, 0LL);
    cout << ans << endl;
    return 0;
}