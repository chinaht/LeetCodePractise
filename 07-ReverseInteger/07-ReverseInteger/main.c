//
//  main.c
//  07-ReverseInteger
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int max = INT_MAX/10;
    int min = INT_MIN/10;
    
    int result = 0;
    while (x !=0) {
        
        if (result >max) {
            return 0;
        }
        if (result < min) {
            return 0;
        }
        int tem = x%10;
        result = tem+result*10;
        x = x/10;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int tem = 1534236469;
    int result = reverse(tem);
    return 0;
}
