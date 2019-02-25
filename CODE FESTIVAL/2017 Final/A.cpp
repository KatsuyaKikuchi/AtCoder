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
    string a = "AKIHABARA";
    int n = a.length() - s.length();
    if (n < 0)
        return "NO";
    REP(i, pow(2, s.length() + 1))
    {
        string t = "";
        REP(j, s.length() + 1)
        {
            if (((i >> j) & 1) == 1)
                t += 'A';
            if (s.length() > j)
                t += s[j];
        }
        if (t == a)
            return "YES";
    }
    return "NO";
}

int main()
{
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}