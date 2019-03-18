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
    int m = 0;
    int n = S.length();
    m = (int)(S[n - 4] - '0') + (int)(S[n - 5] - '0') * 10;
    if (m > 4)
        cout << "TBD" << endl;
    else
        cout << "Heisei" << endl;
    return 0;
}