# string

### 1.输入
string 是C++类库中的函数，C++兼容C语言代码，反之则不一定成立，要想用scanf输出string 类型的变量需要进行适当的转换。
``` C++
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	s.resize(100);
	scanf("%s", &s[0]);
	puts(s.c_str());
	for(int i = 0; i < s.size(); i++)
		printf("%c", s.c_str()[i]);
	return 0;
}
```
getline函数可以整行读入，也可按特定字符分割
``` cpp
int main(){
	string s;
	getline(cin, s); // 读入整行 
	getline(cin, s, ' '); // 以空格分割 
	cout << s << endl;
	getline(cin, s, ' ');
	cout << s << endl;
	getline(cin, s, ' ');
	cout << s << endl;
	return 0;
}
```

### 2.C++ Strings(字符串)
name|describe
-|-
Constructors|构造函数，用于字符串初始化|
Operators|操作符，用于字符串比较和赋值|
append()|在字符串的末尾添加文本|
assign()|为字符串赋新值|
at()|按给定索引值返回字符|
begin()|返回一个迭代器，指向第一个字符|
c_str()|将字符串以C字符数组的形式返回|
capacity()|返回重新分配空间前的字符容量|
compare()|比较两个字符串|
copy()|将内容复制为一个字符数组|
data()|返回内容的字符数组形式|
empty()|如果字符串为空，返回真|
end()|返回一个迭代器，指向字符串的末尾。（最后一个字符的下一个位置）|
erase()|删除字符|
find()|在字符串中查找字符|
find_first_of()|查找第一个与value中的某值相等的字符|
find_first_not_of()|查找第一个与value中的所有值都不相等的字符|
find_last_of()|查找最后一个与value中的某值相等的字符|
find_last_not_of()|查找最后一个与value中的所有值都不相等的字符|
get_allocator()|返回配置器|
insert()|插入字符|
length()|返回字符串的长度|
max_size()|返回字符的最大可能个数|
rbegin()|返回一个逆向迭代器，指向最后一个字符|
rend()|返回一个逆向迭代器，指向第一个元素的前一个位置|
replace()|替换字符|
reserve()|保留一定容量以容纳字符串（设置capacity值）|
resize()|重新设置字符串的大小|
rfind()|查找最后一个与value相等的字符（逆向查找）|
size()|返回字符串中字符的数量|
substr()|返回某个子字符串|
swap()|交换两个字符串的内容|

### 3.C++ string字符串比较方法详解
> 需要注意：对于参加比较的两个字符串，任一个字符串均不能为`NULL`，否则程序会异常退出。

- 比较运算符
String 类的常见运算符包括 >、<、==、>=、<=、!=。其意义分别为"大于"、"小于"、"等于"、"大于等于"、"小于等于"、"不等于"。
``` C++
#include <iostream>
#include <string>
using namespace std;
void TrueOrFalse (int x)
{
    cout << (x?"True":"False")<<endl;
}

int main ()
{
    string S1 = "DEF";
    string CP1 = "ABC";
    string CP2 = "DEF";
    string CP3 = "DEFG";
    string CP4 ="def";
    cout << "S1= " << S1 << endl;
    cout << "CP1 = " << CP1 <<endl;
    cout << "CP2 = " << CP2 <<endl;
    cout << "CP3 = " << CP3 <<endl;
    cout << "CP4 = " << CP4 <<endl;
    cout << "S1 <= CP1 returned ";
    TrueOrFalse (S1 <=CP1);
    cout << "S1 <= CP2 returned ";
    TrueOrFalse (S1 <= CP2);
    cout << "S1 <= CP3 returned ";
    TrueOrFalse (S1 <= CP3);
    cout << "CP1 <= S1 returned ";
    TrueOrFalse (CP1 <= S1);
    cout << "CP2 <= S1 returned ";
    TrueOrFalse (CP2 <= S1);
    cout << "CP4 <= S1 returned ";
    TrueOrFalse (CP4 <= S1);
    cin.get();
    return 0;
}
```
- compare()函数
语法
``` cpp
  int compare( const basic_string &str );
  int compare( const char *str );
  int compare( size_type index, size_type length, const basic_string &str );
  int compare( size_type index, size_type length, const basic_string &str, size_type index2,
  size_type length2 );
  int compare( size_type index, size_type length, const char *str, size_type length2 );
```
返回值|情况
-|- 
小于零|this < str 
零|this == str 
大于零|this > str 

*不同的函数*:
- 比较自己和str, 
- 比较自己的子串和str,子串以index索引开始，长度为length 
- 比较自己的子串和str的子串，其中index2和length2引用str，index和length引用自己 
- 比较自己的子串和str的子串，其中str的子串以索引0开始，长度为length2，自己的子串以index开始，长度为length 

如果在使用 compare() 函数时，参数中出现了位置和大小，比较时只能用指定的子串。例如：
``` cpp
s.compare {pos,n, s2);
```
若参与比较的两个串值相同，则函数返回 0；若字符串 S 按字典顺序要先于 S2，则返回负值；反之，则返回正值。下面举例说明如何使用 string 类的 compare() 函数。
``` cpp
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string A ("aBcdef");
    string B ("AbcdEf");
    string C ("123456");
    string D ("123dfg");
    //下面是各种比较方法
    int m=A.compare (B); //完整的A和B的比较
    int p=A.compare(1,5,B,4,2); //"Bcdef"和"Ef"比较
    int q=C.compare(0,3,D,0,3); //"123"和"123"比较
    cout << "m = " << m << ", n = " << n <<", p = " << p << ", q = " << q << endl;
    cin.get();
    return 0;
}
```

### 4.C++ string字符串修改和替换方法详解
可以通过使用多个函数修改字符串的值。例如 assign()，operator=，erase()，交换（swap），插入（insert）等。另外，还可通过 append() 函数添加字符。
- *assign()函数*
语法: 
``` cpp
  // 用str为字符串赋值, 
  basic_string &assign( const basic_string &str );
  basic_string &assign( const char *str );
  // 用str的开始num个字符为字符串赋值, 
  basic_string &assign( const char *str, size_type num );
  // 用str的子串为字符串赋值,子串以index索引开始，长度为len 
  basic_string &assign( const basic_string &str, size_type index, size_type len );
  // 用num个字符ch为字符串赋值. 
  basic_string &assign( size_type num, char ch );
```

以上几种方法在以下例子中有所体现

``` cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 ("123456");
    string str;
    str.assign (str1); //直接赋值
    cout << str << endl;
    str.assign (str1, 3, 3); //赋值给子串
    cout << str << endl;
    str.assign (str1,2,str1.npos);//赋值给从位置 2 至末尾的子串
    cout << str << endl;
    str.assign (5,'X'); //重复 5 个'X'字符
    cout << str << endl;
    string::iterator itB;
    string::iterator itE;
    itB = str1.begin ();
    itE = str1.end();
    str.assign (itB, (--itE)); //从第 1 个至倒数第 2 个元素，赋值给字符串 str
    cout << str << endl;
    return 0;
}
```
- *operator= 函数*
operator= 的功能就是赋值。

- *erase()函数*
erase() 函数的原型为：
``` cpp
  //删除pos指向的字符, 返回指向下一个字符的迭代器, 
  iterator erase( iterator pos );
  // 删除从start到end的所有字符, 返回一个迭代器,指向被删除的最后一个字符的下一个位置
  iterator erase( iterator start, iterator end );
  // 删除从index索引开始的num个字符, 返回*this.
  basic_string &erase( size_type index = 0, size_type num = npos );
```
