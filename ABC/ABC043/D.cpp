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
    int l = -1, r = -1;
    REP(i, S.length())
    {
        if (i + 1 >= S.length())
            break;
        if (S[i] == S[i + 1])
        {
            l = i + 1;
            r = i + 2;
        }
        if (i + 2 >= S.length())
            break;
        if (S[i + 1] == S[i + 2] || S[i] == S[i + 2] || S[i] == S[i + 1])
        {
            l = i + 1;
            r = i + 3;
            break;
        }
    }
    cout << l << " " << r << endl;
    return 0;
}