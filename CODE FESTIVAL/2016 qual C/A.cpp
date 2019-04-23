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
    int c = S.length(), f = -1;
    REP(i, S.length())
    {
        if (S[i] == 'C' && c > i)
            c = i;
        if (S[i] == 'F')
            f = i;
    }
    if (c < f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}