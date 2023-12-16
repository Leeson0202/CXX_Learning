//
// Created by ￼ Leeson on 2023/9/27.
//

#include <iostream>
#include "string"

using namespace std;

// 查找和替换
void string_find(){
//    * `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
//    * `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
//    * `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
//    * `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
//    * `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
//    * `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
//    * `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
//    * `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
//    * `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
//    * `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
    cout << "******** string find ********" << endl;
    string s1="hello lee, lee is learning C++";


}

// 字符串拼接
void string_append() {
//    * `string& operator+=(const char* str);`                   //重载+=操作符
//    * `string& operator+=(const char c);`                         //重载+=操作符
//    * `string& operator+=(const string& str);`                //重载+=操作符
//    * `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
//    * `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
//    * `string& append(const string &s);`                           //同operator+=(const string& str)
//    * `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾
    cout << "******** string append ********" << endl;
    char c = 'c';
    char str[] = "2c2c2c2c2c2c";
    string s1;
    cout << "s1: " << s1 << endl;

    s1 += c;
    cout << "s2: " << s1 << endl;

    s1 += str;
    cout << "s3: " << s1 << endl;

    s1.append(str);
    cout << "s4: " << s1 << endl;

    s1.append(str, 5);
    cout << "s5: " << s1 << endl;

    s1.append(s1);
    cout << "s6: " << s1 << endl;

    s1.append(str, 2, 4);
    cout << "s7: " << s1 << endl;

}

// 赋值操作
void string_assign() {
//    * `string& operator=(const char* s);`             //char*类型字符串 赋值给当前的字符串
//    * `string& operator=(const string &s);`         //把字符串s赋给当前的字符串
//    * `string& operator=(char c);`                          //字符赋值给当前的字符串
//    * `string& assign(const char *s);`                  //把字符串s赋给当前的字符串
//    * `string& assign(const char *s, int n);`     //把字符串s的前n个字符赋给当前的字符串
//    * `string& assign(const string &s);`              //把字符串s赋给当前字符串
//    * `string& assign(int n, char c);`                  //用n个字符c赋给当前字符串
    cout << "******** string assign********" << endl;
    char c[] = "charts";
    string s1 = c;
    cout << "s1: " << s1 << endl;

    string s2 = s1;
    cout << &s1 << " " << &s2 << endl;


    string s3;
    s3.assign(c, 2);// 前两个赋值给对象
    cout << s3 << endl;

    string s4;
    s4.assign(10, 'v'); // 10个v
    cout << "s4: " << s4 << endl;


}


// 构造函数
void string_construct() {
    cout << "********string constructor********" << endl;
    // `string();`          				//创建一个空的字符串 例如: string str;
    // string(const char* s);`	        //使用字符串s初始化
    // string(const string& str);`    //使用一个string对象初始化另一个string对象
    // string(int n, char c);`           //使用n个字符c初始化
    string s1 = string();
    s1 = "hello s1";
    char c[10] = "abcd";
    string s2(c);
    string s3(s1);
    string s4(4, 'a');
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
}


int main() {
    string_construct();
    string_assign();
    string_append();
    return 0;
}