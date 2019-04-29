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
    REP(i, S.length() + 1)
    {
        string s = "";
        REP(j, i)
        {
            s.push_back(S[j]);
        }
        std::reverse(s.begin(), s.end());
        string t = S + s;
        bool e = true;
        REP(j, t.length())
        {
            if (t[j] != t[t.length() - 1 - j])
                e = false;
        }
        if (e)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}