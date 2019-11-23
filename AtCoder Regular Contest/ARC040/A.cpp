#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
    }
    ll R = 0, B = 0;
    REP(i, N)
    {
        REP(j, N)
        {
            if (S[i][j] == 'R')
                R++;
            else if (S[i][j] == 'B')
                B++;
        }
    }

    if (R == B)
        cout << "DRAW" << endl;
    else if (R > B)
        cout << "TAKAHASHI" << endl;
    else
        cout << "AOKI" << endl;
    return 0;
}