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
string S[60];
int x[3] = {-1, 0, 1};
int y[3] = {-1, 0, 1};

int get(int h, int w)
{
    int n = 0;
    REP(i, 3)
    {
        REP(j, 3)
        {
            if (i == 1 && j == 1)
                continue;
            int nh = x[i] + h, nw = y[j] + w;
            if (nh < 0 || nh >= H || nw < 0 || nw >= W)
                continue;
            if (S[nh][nw] == '#')
                n++;
        }
    }
    return n;
}

int main()
{

    cin >> H >> W;
    REP(i, H)
    {
        cin >> S[i];
    }

    REP(h, H)
    {
        REP(w, W)
        {
            if (S[h][w] == '.')
            {
                cout << get(h, w);
            }
            else
            {
                cout << S[h][w];
            }
        }
        cout << endl;
    }
    return 0;
}