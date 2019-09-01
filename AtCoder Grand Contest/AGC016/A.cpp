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
    ll min = INF;
    REP(i, 27)
    {
        //! 文字'a'+iに変える
        char c = 'a' + i;
        string s = S;
        for (ll j = 0;; ++j)
        {
            bool f = true;
            REP(k, s.length() - 1)
            {
                if (s[k] != s[k + 1])
                    f = false;
            }
            if (f)
            {
                min = std::min(j, min);
                break;
            }

            string tmp = "";
            REP(k, s.length() - 1)
            {
                if (s[k] == c || s[k + 1] == c)
                    tmp.push_back(c);
                else
                    tmp.push_back(s[k]);
            }
            s = tmp;
        }
    }
    cout << min << endl;
    return 0;
}