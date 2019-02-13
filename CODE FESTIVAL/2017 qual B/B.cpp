#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<ll, ll> D;

int main()
{
    ll N, M;
    cin >> N;
    REP(i, N)
    {
        ll d;
        cin >> d;
        D[d]++;
    }
    cin >> M;
    string ans = "YES";
    REP(i, M)
    {
        ll t;
        cin >> t;
        D[t]--;
        if (D[t] < 0)
            ans = "NO";
    }
    cout << ans << endl;
    return 0;
}