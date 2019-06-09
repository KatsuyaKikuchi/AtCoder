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
    if (S[2] == 'B')
        cout << "Bachelor ";
    else if (S[2] == 'M')
        cout << "Master ";
    else
        cout << "Doctor ";
    cout << S[0] << S[1] << endl;
    return 0;
}