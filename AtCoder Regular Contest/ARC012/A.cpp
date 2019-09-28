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
    int n = 0;
    if (S == "Monday")
        n = 5;
    else if (S == "Tuesday")
        n = 4;
    else if (S == "Wednesday")
        n = 3;
    else if (S == "Thursday")
        n = 2;
    else if (S == "Friday")
        n = 1;

    cout << n << endl;
    return 0;
}