#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    string S;
    cin >> S;
    vector<ll> v;
    REP(i, S.length())
    {
        v.push_back(S[i] - 'A' + 1);
    }
    ll ans = 1;
    REP(i, v.size() - 1)
    {
        ans *= v[i] + v[i + 1];
    }
    cout << ans << endl;
    return 0;
}