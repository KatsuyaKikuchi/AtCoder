#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[4] = {0, 0, 0, 0};

int main()
{
    string S;
    cin >> S;
    string ans = "Yes";
    REP(i, S.length())
    {
        if (S[i] == 'N')
            T[0]++;
        else if (S[i] == 'W')
            T[1]++;
        else if (S[i] == 'S')
            T[2]++;
        else
            T[3]++;
    }

    REP(i, 2)
    {
        if (T[i] * T[i + 2] == 0 && T[i] + T[i + 2] > 0)
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}