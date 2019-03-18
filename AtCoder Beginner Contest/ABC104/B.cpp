#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string solve(string S)
{
    if (S[0] != 'A')
        return "WA";
    int n = 0;
    FOR(i, S.length(), 1)
    {
        if (S[i] == 'C')
        {
            if (i == 1 || i == S.length() - 1)
                return "WA";
            n++;
            continue;
        }

        if (S[i] - 'a' < 0 || S[i] - 'a' > 26)
            return "WA";
    }
    return n == 1 ? "AC" : "WA";
}

int main()
{
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}