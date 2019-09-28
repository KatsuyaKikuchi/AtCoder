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
    bool e = true;
    REP(i, S.length())
    {
        if (i % 2 == 0 && S[i] == 'L')
            e = false;
        else if (i % 2 == 1 && S[i] == 'R')
            e = false;
    }
    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}