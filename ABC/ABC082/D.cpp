#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool dpx[8005][8005];
bool dpy[8005][8005];

int main()
{
    string S;
    cin >> S;
    int x, y;
    cin >> x >> y;
    int s = S.length();
    REP(i, S.length())
    {
        if (S[i] == 'T')
        {
            s = i;
            break;
        }
        x--;
    }
    vector<int> X, Y;
    int n = 0;
    bool axisX = true;
    FOR(i, S.length(), s)
    {
        if (S[i] == 'T')
        {
            if (n != 0)
            {
                if (axisX)
                {
                    X.push_back(n);
                }
                else
                {
                    Y.push_back(n);
                }
            }
            axisX = !axisX;
            n = 0;
            continue;
        }
        n++;
    }
    if (axisX)
    {
        X.push_back(n);
    }
    else
    {
        Y.push_back(n);
    }

    dpx[0][0] = true;
    REP(i, X.size())
    {
        REP(j, 8005)
        {
            if (dpx[i][j])
            {
                dpx[i + 1][abs(j + X[i])] = dpx[i + 1][abs(j - X[i])] = true;
            }
        }
    }
    dpy[0][0] = true;
    REP(i, Y.size())
    {
        REP(j, 8005)
        {
            if (dpy[i][j])
            {
                dpy[i + 1][abs(j + Y[i])] = dpy[i + 1][abs(j - Y[i])] = true;
            }
        }
    }

    if (dpx[X.size()][abs(x)] && dpy[Y.size()][abs(y)])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}