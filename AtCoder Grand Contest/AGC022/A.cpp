#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[30];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        U[S[i] - 'a'] = true;
    }
    REP(i, 26)
    {
        if (!U[i])
        {
            cout << S << (char)('a' + i) << endl;
            return 0;
        }
    }
    for (int i = S.length() - 1; i >= 0; --i)
    {
        FOR(j, 26, S[i] - 'a' + 1)
        {
            if (!U[j])
            {
                REP(k, i)
                {
                    cout << S[k];
                }
                cout << (char)('a' + j) << endl;
                return 0;
            }
        }
        U[S[i] - 'a'] = false;
    }
    cout << -1 << endl;
    return 0;
}