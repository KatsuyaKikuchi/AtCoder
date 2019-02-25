#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int C[3];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        C[S[i] - 'a']++;
    }
    if (abs(C[0] - C[1]) <= 1 && abs(C[1] - C[2]) <= 1 && abs(C[2] - C[0]) <= 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}