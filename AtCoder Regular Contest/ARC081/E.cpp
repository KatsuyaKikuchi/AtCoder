#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[200005][30];

int main()
{
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    for (int i = S.length() - 1; i >= 0; --i)
    {
        ll m = INF;
        REP(j, 26)
        {
            C[i][j] = C[i + 1][j];
            m = std::min(m, C[i][j]);
        }
        C[i][S[i] - 'a'] = m + 1;
    }

    string ans = "";
    ll mi = 0;
    REP(i, S.length())
    {
        if (i != 0 && mi + 'a' != S[i - 1])
            continue;
        mi = 0;
        REP(j, 26)
        {
            if (C[i][mi] > C[i][j])
                mi = j;
        }
        ans.push_back((char)(mi + 'a'));
    }
    cout << ans << endl;
    return 0;
}