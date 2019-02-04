#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[30];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        U[(int)(S[i] - 'a')] = true;
    }

    REP(i, 26)
    {
        if (U[i])
            continue;
        cout << (char)(i + 'a') << endl;
        return 0;
    }
    cout << "None" << endl;
    return 0;
}