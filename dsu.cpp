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


vector<int> parent;
vector<int> arr;
vector<int> size;
vector<long long> sum;


void make(int i)
{
	parent[i] = i;
	size[i] = 1;
	sum[i] = arr[i];
}
int find(int i)
{
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

void Union(int a, int b)
{
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	if (size[x] > size[y])
		swap(x, y);
	parent[x] = y;
	//int siz = size[y];
	size[y] += size[x];
	sum[y] += sum[x];
	//size[x] += siz;
}

/**
 *  note here there can be 2 types of problems.
 * i) where the gives sets ranges from 1 to n and is in the order 1 2 3 4 5 .....
 *  need to change sum[i]=i;
 * ii) where the given sets contains arbitrary nos or if they contain 1 to n permutation.
 * 	so in this case you need extra arr[] vector and need to cin it.
 *
 *
 *
 *
 * **/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	parent.assign(n + 1, -1);
	size.assign(n + 1, -1);
	arr.assign(n + 1, -1);
	sum.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		make(i);



	return 0;
}
