#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e7 + 5;
char pattern[maxn], text[maxn];
int match[maxn];
void buildMatch(char pattern[], int plen, int match[])
{
    match[0] = 0, match[1] = 0;
    int j;
    for (int i = 2; i <= plen; i++)
    {
        j = match[i - 1];
        while (j && pattern[j] != pattern[i - 1])
            j = match[j];
        if (pattern[i - 1] == pattern[j])
            match[i] = j + 1;
        else
            match[i] = 0;
    }
}

void kmp(char text[], char pattern[], int tlen, int plen)
{
    int j = 0;
    for (int i = 0; i < tlen; i++)
    {
        while (j && text[i] != pattern[j])
            j = match[j];
        if (text[i] == pattern[j])
            j++;
        if (j == plen)
        {
            printf("%d\n", i - plen + 1 + 1);
            j = match[j];
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    //cin >> text >> pattern;
    scanf("%s\n%s", text, pattern);
    int tlen = strlen(text);
    int plen = strlen(pattern);
    buildMatch(pattern, plen, match);

    kmp(text, pattern, tlen, plen);

    for (int i = 1; i <= plen; i++)
    {
        cout << match[i] << " ";
    }
    return 0;
}
//       null -- a -- ab -- aba -- abaa -- abaab
//state   0      1     2     3      4        5
//match   0      0     0     1      1        2
//match是转移到的状态 也是下一个要匹配的pattern的字符的位置
//也是前缀等于后缀的最长长度
//text         abaabc
//pattern      abaab×
//此时匹配失败      abaab  期望可以一次性挪动到这里 那么等价于什么呢，即接下来判断p[2]和text[t]
//我们发现就是相当于  状态2已经被匹配完成了