/*
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

#include <stdio.h>
#include<string.h>
#define FALSE -1
#define TRUE 0


int max(int x, int y)
{
    return x > y ? x : y;
}

int allUnique(char *s,int start,int end){
    int a[128] = {0};

    int i = 0;
    for(i = start;i<end;i++){
        int ch = s[i];
        if(a[ch] == 1){
            return FALSE;
        }
        a[ch] = 1;
    }
    return TRUE;
}

// int lengthOfLongestSubstring(char *s)
// {
    
//     int i = 0, j = 0, maxi = 0;
//     int length = strlen(s);
    
//     for(i = 0; i < length; i++)
//     {
//         for( j = i+1; j <= length; j++)
//         {
//             if(allUnique(s,i,j) == TRUE){
//                 maxi = max(maxi,j-i);
//             }
//         }
//     }
//     return maxi;
    
// }
int lengthOfLongestSubstring(char *s)
{
    int a[256] = {0};    
    int i = 0, j = 0, maxi = 0;
    int length = strlen(s);

    while(i<length && j< length){
        if(a[s[j]] == 0){
            a[s[j++]] = 1;
            maxi=max(maxi,j-i);
        }else{
            a[s[i++]] = 0;
        }
    }
    return maxi;
    
}


int main(int argc, char const *argv[])
{
    char *a = "abcabcbb";
    char *b = "bbbbb";
    char *c = "pwwkew";
    printf("%d\n",lengthOfLongestSubstring(a));
    printf("%d\n",lengthOfLongestSubstring(b));
    printf("%d\n",lengthOfLongestSubstring(c));

    return 0;
}
