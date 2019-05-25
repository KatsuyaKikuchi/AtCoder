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
    int a = 2, b = 0;
    for (int i = S.length() - 1; i >= 0; --i)
    {
        if (S[i] == '-')
        {
            a *= -1;
            b *= -1;
        }
        else
        {
            if (a == 0)
                a = 1;
            else
                a = 0;
            if (b == 0)
                b = 1;
            else
                b = 0;
        }
    }

    if (a == 2)
        cout << "" << endl;
    else if (a == -2)
        cout << "-" << endl;
    else if (a == 1)
        cout << "!!" << endl;
    else if (a == -1)
        cout << "-!!" << endl;
    else if (a == 0)
    {
        if (b == -1)
            cout << "-!" << endl;
        else
            cout << "!" << endl;
    }
    return 0;
}