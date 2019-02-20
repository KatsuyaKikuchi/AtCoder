#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N[30];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        N[S[i] - 'a']++;
    }
    ll sum = 0;
    ll l = 0;
    REP(i, 27)
    {
        l += N[i] - (N[i] % 2);
        sum += N[i] % 2;
    }
    if (sum > 0)
    {
        sum--;
        l++;
    }
    cout << sum + l * l << endl;
    return 0;
}