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
    int N;
    string S;
    cin >> N >> S;
    REP(i, N)
    {
        string s = "";
        int n = 0;
        REP(j, S.length())
        {
            ++n;
            if (j == S.length() - 1 || S[j] != S[j + 1])
            {
                s += to_string(n);
                s.push_back(S[j]);
                n = 0;
            }
        }
        S = s;
    }
    cout << S << endl;
    return 0;
}