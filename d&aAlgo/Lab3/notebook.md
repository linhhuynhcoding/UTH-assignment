Sv. Huỳnh Vũ Nhật Linh |
CN2304CLCB  
Source Code: [github.com/linhhuynhcoding/](https://github.com/linhhuynhcoding/UTH-assignment/tree/master/d%26aAlgo/Lab3)

# BRUTE FORCE

### Bài 1 - Lựa cân
Cho n quả cân có khối lượng khác nhau. Viết chương trình đưa ra tất
cả các cách có thể đưa các quả cân lên 2 đĩa cân sao cho cân cân bằng!
``` cpp
void recursive(int i, string s) {
    if (i == n) {
        int tmp = 0, tmp1 = 0;
        vector<int> v, v1;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') { tmp += a[j]; v.push_back(a[j]); }
            else { tmp1 += a[j]; v1.push_back(a[j]); }
        }
        if (tmp == tmp1) { 
            for (int x : v) cout << x << " ";
            cout << " | ";
            for (int x : v1) cout << x << " ";
            cout << endl;
        }
        return;
    }  
    recursive(i + 1, s + to_string(0));
    recursive(i + 1, s + to_string(1));
    
}
```
### Bài 2 - Robot
Có 1 rôbốt có thể di chuyển 1 đến 2 mét 1 lần, hãy viết 1 chương trình
đưa ra các cách mà 1 robot có thể đi trên quảng đường n mét. Đưa ra
tất cả các cách đi đó!

``` cpp
void recursive (vector<int> footprint, int n, int current) {
    if (current == n) {
        for (auto i : footprint) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    if (current + 1 <= n) {
        vector<int> next = footprint;
        next.push_back(1);
        recursive(next, n, current + 1);
    }
    if (current + 2 <= n) {

        vector<int> next = footprint;
        next.push_back(2);
        recursive(next, n, current + 2);
    }
    return;
}
```

### Bài 3 - Phân tích số
Liệt kê tất cả các cách phân tích số nguyên dương n thành tổng các số
nguyên dương, hai cách phân tích là hoán vị của nhau chỉ tính là một
cách.

``` cpp
void recursive (vector<int> footprint, int pre, int n) {
    if (n == 0) {
        int sum = 0;
        for (auto i : footprint) {
            cout << i << " + ";
            sum += i;
        }
        cout << "\b\b= " << sum << "\n";
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (i > pre ) continue;

        vector <int> next = footprint;
        next.push_back(i);

        if (n - i >= 0)
            recursive(next, i, n - i);
    }
    
    return;
}
```

### Bài 4 - Bài toán người du lịch
Có n thành phố, d[i, j] là chi phí để di chuyển từ thành phố i đến thành phố j. (Nếu không có đường đi thì d[i, j] = ∞). Một người muốn
đi du lịch qua tất cả các thành phố, mỗi thành phố một lần rồi trở về
nơi xuất phát sao cho tổng chi phí là nhỏ nhất. Hãy xác định một
đường đi như vậy

``` cpp
void recursive(vector<int> footprint, bool visited[20], int current, int end)
{
    visited[current] = true;

    if (current == end)
    {
        for (int i = 0; i < 20; i++)
        {
            if (visited[i] == false)
                return;
        }
        int cur_ans = 0;
        for (auto i = 1; i < footprint.size(); i++)
        {
            cur_ans = d[footprint[i - 1]][footprint[i]];
        }
        ans = min(ans, cur_ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (d[current][i] == INF || visited[i]) continue;

        vector<int> next = footprint;
        next.push_back(i);


        recursive(next, visited, i, end);
    }
}
```


### Bài 5 - Bài toán giao tasks
Có n task, mỗi task có thù lao vi . Có m công nhân, hãy thực hiện việc giao tasks cho các công nhân, nhưng đảm bảo tổng giá trị thực hiện các task của mỗi công nhân sai lệch ít nhất có thể 

``` cpp
void recursive(vector<int> tasks, bool dagiao[20], int currentTask)
{
    if (currentTask == n) {
        double x = 0;
        for (int i = 1; i <= n; i++) x += salary[tasks[i]];
        x /= n;
        double dolech = 0;

        for (int i = 1; i <= n; i++) {
            dolech += sqrt((salary[tasks[i]] - x) * (salary[tasks[i]] - x) / (n - 1));
        }

        ans = min(ans, dolech);
        return; 
    }

    for (int i = 1; i <= m; i++) {
        if (dagiao[i]) continue;

        dagiao[i] = true;

        vector<int> nexttasks = tasks;
        nexttasks[currentTask] = i;
        recursive(nexttasks, dagiao, currentTask + 1);
    }    
}
```
