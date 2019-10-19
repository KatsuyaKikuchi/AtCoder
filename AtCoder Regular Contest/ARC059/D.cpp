#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[30];

int main()
{
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    REP(i, S.length())
    {
        if (i > 0 && S[i] == S[i - 1])
        {
            cout << i << " " << i + 1 << endl;
            return 0;
        }

        if (i > 0 && i < S.length() - 1 && S[i - 1] == S[i + 1])
        {
            cout << i << " " << i + 2 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}