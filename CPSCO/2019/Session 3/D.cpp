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
    int n = s.length();
    if (s[0] != 'R' || s[n - 1] != 'B')
        return "No";
    REP(i, n - 1)
    {
        if (s[i] == 'R' && s[i + 1] == 'B')
            return "No";
        if (s[i] == 'G' && s[i + 1] == 'G')
            return "No";
    }
    return "Yes";
}

int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}