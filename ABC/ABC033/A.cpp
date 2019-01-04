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
    char f = S[0];
    string ans = "SAME";
    REP(i, S.length())
    {
        if (f != S[i])
            ans = "DIFFERENT";
    }
    cout << ans << endl;
    return 0;
}