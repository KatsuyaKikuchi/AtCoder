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
    int max = 1;
    REP(i, S.length())
    {
        if (S[i] == '2')
            n++;
        else
            n--;
        if (n < 0)
            break;
        max = std::max(max, abs(n));
    }
    if (n != 0)
        max = -1;
    cout << max << endl;
    return 0;
}