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
    string S, T;
    cin >> S >> T;

    int s = -1;
    for (int i = S.length() - 1; i >= 0; --i)
    {
        if (i + T.length() > S.length())
            continue;

        bool find = true;
        REP(j, T.length())
        {
            if (S[i + j] == '?' || S[i + j] == T[j])
                continue;
            find = false;
        }
        if (find)
        {
            s = i;
            break;
        }
    }
    if (s == -1)
    {
        cout << "UNRESTORABLE" << endl;
    }
    else
    {
        REP(i, S.length())
        {
            if (i < s || s + T.length() <= i)
            {
                if (S[i] == '?')
                    cout << 'a';
                else
                    cout << S[i];
            }
            else
            {
                cout << T[i - s];
            }
        }
        cout << endl;
    }
    return 0;
}