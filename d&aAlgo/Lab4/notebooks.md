Sv. Huỳnh Vũ Nhật Linh |
CN2304CLCB  
Source Code: [github.com/linhhuynhcoding/](https://github.com/linhhuynhcoding/UTH-assignment/tree/master/d%26aAlgo/Lab4)

# GREEDY

## 1. Knapsack
Có n đồ vật, mỗi đồ vật có giá trị vi , trọng lượng wi . Một người có khả năng mang được trọng lượng W, hãy lựa chọn các đồ vật sao cho tổng trọng lượng các đồ vật nhỏ hơn W và tổng giá trị các đồ vật lớn nhất có thể 

```cpp
void dp()
{
    int w;
    cin >> n >> w;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i ++) {
        auto &[u, v] = a[i];
        cin >> u >> v;
    }

    sort (a.begin(), a.end(), [](const pair <int, int> &a, const pair <int, int> &b){
        return (1.0 * a.second / a.first ) > (1.0 * b.second / b.first );
    });

    int res = 0;

    for (auto [u, v] : a) {
        while (w >= u) res += v, w -= u;
    }
    
    cout << res;
}
```

## 2. Bài toán đổi tiền
Trong máy có chuẩn bị sẵn các loại tiền 10K, 20K, 50K và 100K. Giả sử số lượng không hạn chế. Khi có một khách hàng cần rút N đồng, với N chia hết cho 10K. Tìm một phương án trả N đồng và số lượng tờ ít nhất. 
```cpp
void dp()
{
    set <int, greater<int>> cash = {100, 50, 20, 10};
    cin >> n;

    int res = 0;

    for (auto money : cash){
        while (n >= money) res += 1, n -= money;
    }
    cout << res;
}

```

## 4. Mark and Toys
Mark and Jane are very happy after having their first kid. Their son is very fond of toys, so Mark wants to buy some. There are N different toys lying in front of him, tagged with their prices, but he has only K $. He wants to maximize the number of toys he buys with this money. Now, you are Mark’s best friend and have to help him buy as many toys as possible.

```cpp
void dp()
{
    int k;
    cin >> n >> k;
    set <int> toys = {};

    for (int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        toys.insert(tmp);
    }

    int res = 0;

    for (auto toy : toys) {
        while (k >= toy) res += 1, k -= toy;
    }
    
    cout << res;
}
```

## 5. Max Min
Given a list of N integers, your task is to select K integers from he list
such that its unfairness is minimized.if (x1, x2, ..., xk) are K numbers selected from the list , the nfairness is
defined as max(x1, x2, ..., xk) − min(x1, x2, ..., xk) where max enotes
the largest integer among the elements of K, and min denotes thesmallest integer among the elements of K

```cpp
void dp()
{
    int k;
    cin >> n >> k;
    set<int> nums = {};

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.insert(num);
    }
    int res = abs(*nums.begin() - *nums.rbegin());
    cout << res;
}

```
## 6. Chia tài sản
Trong ngày sinh nhật, hai anh em Tom và Alice nhận được N(N < 10)
đồ chơi. Trên đồ chơi i có ghi giá tiền Xi
. Hai anh em quyết định mỗi
người phải có trách nhiệm bảo quản một phần số quà và phân chia sao
cho chênh lệch tổng giá trị tiền đồ chơi mà mỗi người bảo quản là ít
nhất. Hãy giúp Tom và Alice phân chia. Viết cho phép người dùng
nhập N đồ vật và giá trị các đồ vật Xi
.

```cpp
void dp()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	ll ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		if (ans1 < ans2) ans1 += a[i];
		else ans2 += a[i];
	}
	cout << ans1 << " " << ans2;
}

```