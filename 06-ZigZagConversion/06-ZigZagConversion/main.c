//
//  main.c
//  06-ZigZagConversion
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int lengthChar(char *s);
char* convert(char* s, int numRows) {
    int length = lengthChar(s);
    if (length <= numRows||numRows==1) {
        return s;
    }
    char *result = malloc((length+1)*sizeof(char));
    int resultIndex = 0;
    int singleCount = numRows*2-2;//单次
    
    for (int i=0; i<numRows; i++) {
        int column = 0;
        int index = i;
        while (index < length) {
            result[resultIndex] = s[index];
            column++;
            resultIndex++;
            if (i == 0||i == (numRows-1)) {
                index= i + singleCount*column;
            }else {
                int temp = column%2;
                if (temp == 0) {
                    //偶数列
                    
                    index= i + singleCount*(column/2);
                }else{
                    //奇数列
                    index = i + singleCount*(column/2)+(singleCount-i*2);
                }
            }
        }
    }
    result[length] = '\0';
    return result;
}
int lengthChar(char *s){
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char *tem = "AB";
    char *result = convert(tem, 1);
    return 0;
}
