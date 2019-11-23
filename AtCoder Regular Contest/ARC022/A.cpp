#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool solve(string s)
{
    string a = "ICT";
    string b = "ict";
    int index = 0;
    REP(i, s.length())
    {
        if (s[i] == a[index] || s[i] == b[index])
            index++;
        if (index >= 3)
            break;
    }

    return index >= 3;
}
int main()
{
    string S;
    cin >> S;
    if (solve(S))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}