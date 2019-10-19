#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string solve(string s)
{
    string A = "AtCoder";
    string B = "ATCODER";
    string C = "atcoder";
    if (s == A)
        return "Yes";
    REP(i, 7)
    {
        if (s[i] != B[i] && s[i] != C[i])
            return "No";
    }
    return "Maybe";
}
int main()
{
    string S;
    cin >> S;

    cout << solve(S) << endl;
    return 0;
}