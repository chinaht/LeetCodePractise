//
//  main.c
//  05LongestPalindromicSubstring
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int getCharsLenth(char *s);
int getLongestPalindromeLengthWith(int left,int right,char *s,int charLength);
/*
 从左到右 扫描 i（奇数长度与偶数长度 对称两种情况），  将i或者i与i+1作为中心字符
 例如  奇数长度  s[i]作为中心点时，start end 从i开始，start--与end++相等时则对称
 
 */
char* longestPalindrome(char* s) {
    
    int charLength = getCharsLenth(s);
    if (charLength == 0) {
        return NULL;
    }
    int start = 0;int end = 0;
    int index = 0;
    while (index < charLength) {
        int len1 = getLongestPalindromeLengthWith(index, index, s, charLength);
        int len2 = getLongestPalindromeLengthWith(index, index+1, s, charLength);
        int len = 0;
        if (len1 >len2) {
            len = len1;
        }else{
            len = len2;
        }
        if (len > (end-start)) {
            start = index - (len-1)/2;
            end = index + len/2;
        }
        index++;
    }
    char *result = malloc((end-start+2)*sizeof(char));
    for (int i = 0; i<(end-start+1); i++) {
        result[i] = s[start+i];
    }
    result[end-start+1] = '\0';
    return result;
}
int getLongestPalindromeLengthWith(int left,int right,char *s,int charLength){
    int l = left,r = right;
    
    while (l >=0&& r<=charLength&&s[l] == s[r]) {
        l--;
        r++;
    }
    return r-l-1;
}
int getCharsLenth(char *s){
    if (s == NULL) {
        return 0;
    }
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char *s = "cbbd";
    char *result = longestPalindrome(s);
    return 0;
}
