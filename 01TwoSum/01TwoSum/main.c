//
//  main.c
//  01TwoSum
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int a[2];
    a[0]=0;
    a[1]=0;
    for (int i =0;i<numsSize;i++){
        a[0] = i;
        int firstInt = nums[i];
        for(int j=i+1;j<numsSize;j++){
            int secondInt = nums[j];
            if((firstInt+secondInt)==target){
                a[1]=j;
                break;
            }
        }
        if(a[1] >0) break;
    }
    int *p = a;
    return p;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {2,7,11,15};
    int *result = malloc(sizeof(int));
    result = twoSum(nums, 4, 9);
    return 0;
}
