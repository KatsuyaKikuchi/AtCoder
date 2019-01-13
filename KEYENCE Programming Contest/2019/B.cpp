#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string K = "keyence";

int main()
{
    string S;
    cin >> S;
    string ans = "NO";
    REP(i, S.length())
    {
        //! iからL-7文字取り除く
        if (i - 8 >= 0)
            break;
        string s = "";
        REP(j, S.length())
        {
            if (j >= i && j <= i + (S.length() - 8))
                continue;
            s += S[j];
        }
        if (s == K)
        {
            ans = "YES";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}