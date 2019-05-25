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
    string S, T, U;
    cin >> S >> T >> U;

    if (S.length() == 5 && T.length() == 7 && U.length() == 5)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    return 0;
}