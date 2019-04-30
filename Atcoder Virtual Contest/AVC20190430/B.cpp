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
    ll sum = S[0] - '0';
    FOR(i, S.length(), 1)
    {
        int t = S[i] - '0';
        if (i % 2 == 1)
            sum -= t;
        else
            sum += t;
    }
    cout << sum << endl;
    return 0;
}