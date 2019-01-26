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
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll a = 0, b = 0, c = 0;
    REP(i, S.length())
    {
        string s = "No";
        if (S[i] == 'a')
        {
            if (A + B > a + b)
            {
                s = "Yes";
                a++;
            }
        }
        else if (S[i] == 'b')
        {
            if (A + B > a + b && B > b)
            {
                s = "Yes";
                b++;
            }
        }
        cout << s << endl;
    }
    return 0;
}