#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[4] = {'p', 'b', 'q', 'd'};

int main()
{
    string S;
    cin >> S;
    string ans = "Yes";
    REP(i, S.length())
    {
        char a = S[i];
        char b = S[S.length() - 1 - i];
        bool e = false;
        REP(j, 4)
        {
            if (C[j] == a && C[(j + 2) % 4] == b)
                e = true;
        }
        if (!e)
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}