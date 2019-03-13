### 结构体
``` c++
#include <iostream>

using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {};   // 构造函数

    // 相当于
    // Point(int x = 0, int y = 0){this->x = x; this->y = y;}
};

Point operator + (const Point &A, const Point &B) { // 运算符重载
    return {A.x + B.x, A.y + B.y};
}

ostream &operator<<(ostream &out, const Point &p) { // 定义结构体流输出方式
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main() {
    Point a, b(1, 2);
    a.x = 3;
    cout << a << "\n";
    cout << b << "\n";
    cout << a + b << "\n";
    return 0;
}
```
### 模板
- #### 函数
``` C++
// 实现数组求和
template<typename T>
T sum(T *begin, T *end) {
    T ans = 0;
    for (T *p = begin; p != end; p++) {
        ans = ans + *p; // 因为结构体只定义了'+'运算符，而没有定义'+='运算符
    }
    return ans;
}

int main() {
    double a[] = {1.1, 2.2, 3.3, 4.4};
    cout << sum(a, a + 4) << "\n";
    Point b[] = {Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8)};
    cout << sum(b, b + 4) << "\n";
    return 0;
}
```
- #### 函数和类也可以是带模板的
``` C++
#include <iostream>
using namespace std;

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template<typename T>
Point<T> operator+(const Point<T> &A, const Point<T> &B) {
    return {A.x + B.x, A.y + B.y};
}

template<typename T>
ostream &operator<<(ostream &out, const Point<T> &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main() {
    Point<int> a(1, 2), b(3, 4);
    Point<double> c(1.1, 2.2), d(3.3, 4.4);
    cout << a + b << " " << c + d << "\n";
    return 0;
}
```

### 排序
``` c
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int number[] = {1,2,56,6,4,2,45,526,4,23,12,12}; // 12 elements
    sort(number, number + 12);
    for (int i = 0; i < 12; ++i) {
        printf("%d\n", number[i]);
    }

    int p = lower_bound(number, number + 12, 12) - number;  // 返回大于或者等于x的第一个位置
    printf("lower:%d", p);
    return 0;
}
```


- UVa10474
``` c++
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int main() {
    int n, q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        sort(a, a + n);

        while (q--) {
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a;
            if (a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }

    return 0;
}
```


### vector
- `vector<int>pile[maxn]`：只有一维固定，二维不固定
- `vector.clear()`：清空
- `vector.resize()`：改变大小
- `vector.push_back()`：在尾部添加元素
- `vector.pop_back()`：在尾部删除元素
- `vector.empty()`：判断是否为空


- UVa101
``` c
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn]; // 每个pile[i]是一个vector

// 找木块a所在的pile和height，以引用的形式返回调用者
void find_block(int a, int &p, int &h) {
    for (int p = 0; p < n; ++p) {
        for (int h = 0; h < pile[p].size(); ++h) {
            if (pile[p][h] == a) return;
        }
    }
}

// 把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p, int h) {
    for (int i = h + 1; i < pile[p].size(); ++i) {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

// 把第p堆高度为h 及其上方的木块整体移动到p2堆的顶部
void pile_onto(int p, int h, int p2) {
    for (int i = h; i < pile[p].size(); ++i) {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print() {
    for (int i = 0; i < n; ++i) {
        printf("%d:", i);
        for (int j = 0; j < pile[i].size(); ++j) {
            printf(" %d", pile[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        pile[i].push_back(i);
    }

    while (cin >> s1 >> a >> s2 >> b) {
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb)continue;   // 非法指令
        if (s2 == "onto")clear_above(pb, hb);
        if (s1 == "move")clear_above(pa, ha);
        pile_onto(pa, ha, pb);
    }
    print();

    return 0;
}

```

### set
- UVa 10815

``` c
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

set<string> dict;   // 集合
int main() {
    string s, buf;
    while (cin >> s) {
        for (int i = 0; i < s.length(); ++i) {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while (ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << "\n";
    }


    return 0;
}
```


### map

- UVa156

``` C
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> cnt;
vector<string> words;

// 将单词s进行“标准化”
string repr(const string &s) {
    string ans = s;
    for (int i = 0; i < ans.length(); ++i) {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 0;
    string s;
    while (cin >> s) {
        if (s[0] == '#')break;

        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); ++i) {
        if (cnt[repr(words[i])] == 1)ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for (int j = 0; j < ans.size(); ++j) {
        cout << ans[j] << "\n";
    }

    return 0;
}

```

### queue

``` C
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int maxt = 1000 + 10;

int main() {
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t) {
        printf("Scenario #%d\n", ++kase);

        // 记录所有人的团队编号
        map<int, int> team;  // team[x]表示编号为x的人所在的团队编号
        for (int i = 0; i < t; ++i) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q, q2[maxt]; // q是团队的队列，而q2[i]是团队i成员的队列
        for (;;) {
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'S')break;
            else if (cmd[0] == 'D') {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();    // 团队t全体出队列
            } else if (cmd[0] == 'E') {
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty())q.push(t);    // 团队t进入队列
                q2[t].push(x);
            }
        }
        printf("\n");
    }

    return 0;
}

```
