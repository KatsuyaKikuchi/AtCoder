#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[30];

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    REP(i, N)
    {
        C[S[i] - 'a']++;
    }
    ll ans = 1;
    REP(i, 26)
    {
        ans = (ans * (C[i] + 1)) % MOD;
    }
    ans = (MOD + ans - 1) % MOD;
    cout << ans << endl;
    return 0;
}