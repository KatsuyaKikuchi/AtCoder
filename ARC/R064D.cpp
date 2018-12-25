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
    string ans = "First";
    if (S[0] == S[S.length() - 1])
    {
        if (S.length() % 2 == 1)
        {
            ans = "Second";
        }
    }
    else
    {
        if (S.length() % 2 == 0)
        {
            ans = "Second";
        }
    }
    cout << ans << endl;
    return 0;
}