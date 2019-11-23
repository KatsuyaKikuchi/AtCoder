#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool solve(ll n, string s)
{
    if (n % 2 != 0)
        return false;

    REP(i, n / 2)
    {
        if (s[i] != s[n / 2 + i])
            return false;
    }
    return true;
}
int main()
{
    ll N;
    string S;
    cin >> N >> S;
    if (solve( N, S))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}