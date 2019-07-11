#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int C[30];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        C[S[i] - 'A']++;
    }

    int t = 0;
    bool e = true;
    REP(i, 28)
    {
        if (C[i] > 0)
        {
            if (C[i] != 2)
                e = false;
            t++;
        }
    }

    if (e && t == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}