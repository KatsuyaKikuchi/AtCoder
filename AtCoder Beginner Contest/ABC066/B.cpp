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
    REP(i, S.length() - 1)
    {
        int l = S.length() - i - 1;
        if (l % 2 == 1)
            continue;
        bool e = true;
        REP(j, l / 2)
        {
            if (S[j] != S[l / 2 + j])
                e = false;
        }

        if (e)
        {
            cout << l << endl;
            break;
        }
    }
    return 0;
}