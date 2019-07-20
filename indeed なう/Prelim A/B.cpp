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
int D[30];

string solve(string s)
{
    memset(C, 0, sizeof(C));
    REP(i, s.length())
    {
        C[s[i] - 'a']++;
    }
    REP(i, 30)
    {
        if (C[i] != D[i])
            return "NO";
    }
    return "YES";
}

int main()
{
    ll N;
    cin >> N;
    string s = "indeednow";
    REP(i, s.length())
    {
        D[s[i] - 'a']++;
    }

    REP(i, N)
    {
        string S;
        cin >> S;
        cout << solve(S) << endl;
        ;
    }
    return 0;
}