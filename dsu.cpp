#include<bits\stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int mod =  1e9 + 7;
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rev(i,a,n) for(ll i=n-1;i>=a;i--)
#define pcout(p) cout<<p.first<<" "<<p.second<<" "


template<typename T1, typename T2>void ans(bool x, T1 y, T2 z) {if (x)cout << y << endl; else cout << z << endl;}
template<typename T1, typename T2, typename T3>void anss(T1 x, T2 y, T3 z) {ans(x != y, x, z);};
template<typename T>void debug(const T &v, ll h, ll w, string sv = " ") {for (ll i = 0; i < h; i++) {cout << v[i][0]; for (ll j = 1; j < w; j++)cout << sv << v[i][j]; cout << endl;}};
template<typename T>void debug(const T &v, ll n, string sv = " ") {if (n != 0)cout << v[0]; for (ll i = 1; i < n; i++)cout << sv << v[i]; cout << endl;};
template<typename T>void debug(const vector<T>&v) {debug(v, v.size());}
template<typename T>void debug(const vector<vector<T>>&v) {for (auto &vv : v)debug(vv, vv.size());}
template<typename T>void debug(stack<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(queue<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop();} cout << endl;}
template<typename T>void debug(deque<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop_front();} cout << endl;}
template<typename T>void debug(PQ<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(QP<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(const set<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T>void debug(const multiset<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T, size_t size>void debug(const array<T, size> &a) {for (auto z : a)cout << z << " "; cout << endl;}
template<typename T, typename V>void debug(const map<T, V>&v) {for (auto z : v)cout << "[" << z.first << "]=" << z.second << ","; cout << endl;}



struct DSU {
    vector<int> par, rnk, size;
    multiset<int> ms;

    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), size(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i)
            par[i] = i, ms.insert(1);
    }
    int find(int i)
    {
        if (par[i] == i)
            return i;
        return par[i] = find(par[i]);
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return size[find(i)];
    }
    int totalcc() {
        return c;    //connected components
    }
    int merge(int i, int j) {
        i = find(i), j = find(j);
        if (i == j)
            return -1;
        else
            --c;

        if (size[i] > size[j]) swap(i, j);

        par[i] = j;

        int sizX = size[i], sizY = size[j];
        //why does get size function don't work here when i write it above instead of size[]

        auto it = ms.find(sizX);    ms.erase(it);
        auto it2 = ms.find(sizY);   ms.erase(it2);

        size[j] += size[i];
        ms.insert(size[j]);

        // if (rnk[i] == rnk[j]) rnk[j]++;

        return j;
    }
};



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;

    DSU dsu(n);

    return 0;
}
