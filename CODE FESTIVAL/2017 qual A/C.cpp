#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int H, W;
int C[30];

string solve(int o, int e)
{
    if (H % 2 == 0)
    {
        if (W % 2 == 0)
        {
            if (o == 0 && e == 0)
                return "Yes";
            return "No";
        }
        if (H / 2 >= e && o == 0)
            return "Yes";
        return "No";
    }

    if (W % 2 == 0)
    {
        if (W / 2 >= e && o == 0)
            return "Yes";
        return "No";
    }

    if (o != 1)
        return "No";
    if (H / 2 + W / 2 >= e)
        return "Yes";
    return "No";
}

int main()
{
    cin >> H >> W;
    REP(i, H)
    {
        string s;
        cin >> s;
        REP(j, W)
        {
            C[s[j] - 'a']++;
        }
    }
    int o = 0, e = 0;
    REP(i, 26)
    {
        int n = C[i] % 4;
        if (n == 1)
            o++;
        if (n == 2)
            e++;
        if (n == 3)
        {
            o++;
            e++;
        }
    }
    cout << solve(o, e) << endl;
    return 0;
}