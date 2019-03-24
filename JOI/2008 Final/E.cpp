#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Rect
{
    pll ld;
    pll ru;
};

Rect R[1005];
int M[7500][7500];

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

int main()
{
    ll H, W;
    cin >> W >> H;
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> R[i].ld.first >> R[i].ld.second >> R[i].ru.first >> R[i].ru.second;
        R[i].ru.first--;
        R[i].ru.second--;
    }
    vector<ll> xs, ys;
    xs.push_back(0);
    xs.push_back(W - 1);
    ys.push_back(0);
    ys.push_back(H - 1);
    REP(i, N)
    {
        REP(d, 2)
        {
            ll tx1 = R[i].ld.first - d, tx2 = R[i].ru.first + d;
            ll ty1 = R[i].ld.second - d, ty2 = R[i].ru.second + d;
            if (0 <= tx1 && tx1 < W)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 < W)
                xs.push_back(tx2);
            if (0 <= ty1 && ty1 < H)
                ys.push_back(ty1);
            if (0 <= ty2 && ty2 < H)
                ys.push_back(ty2);
        }
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    REP(i, N)
    {
        R[i].ld.first = find(xs.begin(), xs.end(), R[i].ld.first) - xs.begin();
        R[i].ru.first = find(xs.begin(), xs.end(), R[i].ru.first) - xs.begin();
        R[i].ld.second = find(ys.begin(), ys.end(), R[i].ld.second) - ys.begin();
        R[i].ru.second = find(ys.begin(), ys.end(), R[i].ru.second) - ys.begin();
    }

    memset(M, 0, sizeof(M));
    //! 塗りつぶし
    REP(i, N)
    {
        ll lx = R[i].ld.first, rx = R[i].ru.first + 1;
        ll dy = R[i].ld.second, uy = R[i].ru.second + 1;
        M[dy][lx]++;
        M[dy][rx]--;
        M[uy][lx]--;
        M[uy][rx]++;
    }

    H = ys.size();
    W = xs.size();
    REP(h, H)
    {
        FOR(w, W, 1)
        {
            M[h][w] += M[h][w - 1];
        }
    }
    REP(w, W)
    {
        FOR(h, H, 1)
        {
            M[h][w] += M[h - 1][w];
        }
    }

    REP(h, H)
    {
        REP(w, W)
        {
            if (M[h][w] > 0)
                cout << '#';
            else if (M[h][w] < 0)
                cout << 'x';
            else
                cout << '.';
        }
        cout << endl;
    }

    ll n = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            if (M[h][w])
                continue;

            queue<pll> q;
            q.push(pll(h, w));
            M[h][w] = true;

            while (!q.empty())
            {
                pll t = q.front();
                q.pop();
                REP(i, 4)
                {
                    int x = nx[i] + t.first, y = ny[i] + t.second;
                    if (x < 0 || x >= H || y < 0 || y >= W)
                        continue;
                    if (M[x][y])
                        continue;
                    M[x][y] = true;
                    q.push(pll(x, y));
                }
            }
            ++n;
        }
    }
    cout << n << endl;

    return 0;
}