#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pb push_back
ll mod =  1e9 + 7;
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rev(i,a,n) for(ll i=n-1;i>=a;i--)
#define pcout(p) cout<<p.first<<" "<<p.second<<endl
#define cout3(a,b,c) cout<<a<<' '<<b<<' '<<c<<endl
#define cout2(a,b) cout<<a<<' '<<b<<endl

template<typename T1, typename T2>void ans(bool x, T1 y, T2 z) {if (x)cout << y << endl; else cout << z << endl;}
template<typename T1, typename T2, typename T3>void anss(T1 x, T2 y, T3 z) {ans(x != y, x, z);};
template<typename T>void debug(const T &v, ll h, ll w, string sv = " ") {for (ll i = 0; i < h; i++) {cout << v[i][0]; for (ll j = 1; j < w; j++)cout << sv << v[i][j]; cout << endl;}};
template<typename T>void debug(const T &v, ll n, string sv = " ") {if (n != 0)cout << v[0]; for (ll i = 1; i < n; i++)cout << sv << v[i]; cout << endl;};
template<typename T>void debug(const vector<T>&v) {debug(v, v.size());}
template<typename T>void debug(const vector<vector<T>>&v) {for (auto &vv : v)debug(vv, vv.size());}
template<typename T, typename V>void debug(const vector<pair<T, V>>&v) {for (auto it : v)cout << it.first << " " << it.second << endl;};

template<typename T>void debug(stack<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(queue<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop();} cout << endl;}
template<typename T>void debug(deque<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop_front();} cout << endl;}
// template<typename T>void debug(PQ<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
// template<typename T>void debug(QP<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(const set<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T>void debug(const multiset<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T, size_t size>void debug(const array<T, size> &a) {for (auto z : a)cout << z << " "; cout << endl;}
template<typename T, typename V>void debug(const map<T, V>&v) {for (auto z : v)cout << "[" << z.first << "]=" << z.second << ","; cout << endl;}
// ios_base::sync_with_stdio(0);
// cin.tie(0); cout.tie(0);


struct LazySegTree {
	int n;
	vector<int> arr;
	vector<int> SegTree;
	vector<int> Lazy;

	//Update (l,r,x) : add x to each element from l to r.
	//query (l,r) : find sum from L to R.

	LazySegTree(int N, vector<int> v) {
		n = N;
		arr = v;
		int siz = 1;
		while (siz < 2 * N) {
			siz *= 2;
		}
		SegTree.assign(siz, -1);  	// May change
		Lazy.assign(siz, 0); 	   //may change , Lazy = 0 means no updation req.
		build(0, n - 1, 1);
	}

	//update = U : add x to each element from l to r.
	void U(int l, int r, int x) {
		return update(0, n - 1, 1, l, r, x);
	}
	//query (l,r) = Q : find sum from L to R.
	int Q(int l, int r) {
		return query(0, n - 1, 1, l, r);
	}

	int merge(int left, int right) {
		return left + right;		// operation may change
	}

	void build(int start, int end, int index) {
		if (start == end) {
			SegTree[index] = arr[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, index * 2);
		build(mid + 1, end, index * 2 + 1);

		SegTree[index] = merge(SegTree[index * 2], SegTree[index * 2 + 1]);
		return;
	}

	void propagate(int start, int end, int index) {
		// in actual seg Tree we have already updated at index before calling propagate(), propagate function's job is to do changes in LazySeg tree only.
		// the changes in lazySegTree required are 1.make lazy[index]=0 and 2.propagate change downwards.
		if (start == end) {
			//propagation not possible
			Lazy[index] = 0;					//might change
			return;
		}
		Lazy[index * 2] += Lazy[index];		//may change (here adding , might be assign)
		Lazy[index * 2 + 1] += Lazy[index];	//may change (here adding , might be assign)
		Lazy[index] = 0;					//might change
	}

	void update(int start, int end, int index, int l, int r, int val) {
		if (Lazy[index] != 0) {							//might change
			SegTree[index] += Lazy[index] * (end - start + 1);		//may change depending upon merge function
			propagate(start, end, index);
		}

		//current node is in most updated form
		if (start >= l && end <= r) {
			SegTree[index] += val * (end - start + 1); 		//may change
			Lazy[index] += val;					//may change
			propagate(start, end, index);
			return;
			//reason why we are leaving it to most updated form is because when we'll return upward for merging , we could do that merging correctly by using correct values.
		}
		if (start > r || end < l)
			return;

		int mid = (start + end) / 2;
		update(start, mid, index * 2, l, r, val);
		update(mid + 1, end, index * 2 + 1, l, r, val);

		SegTree[index] = merge(SegTree[index * 2], SegTree[index * 2 + 1]);
		return;
	}

	int query(int start, int end, int index, int l, int r) {
		if (Lazy[index] != 0) {							//may change
			SegTree[index] += Lazy[index] * (end - start + 1);		//may change
			propagate(start, end, index);
		}

		if (start >= l && end <= r) {
			return SegTree[index];
		}
		if (end < l || r < start)
			return 0;  			//may change

		int mid = (start + end) / 2;
		int leftAns = query(start, mid, index * 2, l, r);
		int rightAns = query(mid + 1, end, index * 2 + 1, l, r);
		return merge(leftAns, rightAns);
	}

};


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	LazySegTree st(n, v);
	debug(st.SegTree);
	st.U(0, 3, 1);
	cout << st.Q(0, 3);
	st.U(3, 5, 2);
	cout << st.Q(0, 4);
	st.U(1, 1, 0);
	st.U(2, 2, 0);
	debug(st.SegTree);
	debug(st.Lazy);


	return 0;
}
