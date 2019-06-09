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
    bool d = false;
    int t = 0;
    REP(i, S.length())
    {
        if (S[i] == '{')
            t++;
        else if (S[i] == '}')
            t--;

        if (t == 1 && S[i] == ':')
            d = true;
    }
    if (S == "{}" || d)
        cout << "dict" << endl;
    else
        cout << "set" << endl;
    return 0;
}