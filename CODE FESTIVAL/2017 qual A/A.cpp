#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[4] = {'Y', 'A', 'K', 'I'};
string solve(string s)
{
    if (s.length() < 4)
        return "No";
    REP(i, 4)
    {
        if (C[i] != s[i])
            return "No";
    }
    return "Yes";
}
int main()
{
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}