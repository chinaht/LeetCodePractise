//
//  main.c
//  04MedianOfTwoSortedArrays
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *result = (int *)malloc((nums1Size+nums2Size)*sizeof(int));
    int nums1Index = 0;
    int nums2Index = 0;
    while (nums1Index <nums1Size &&nums2Index <nums2Size) {
        double num1V = nums1[nums1Index];
        double num2V = nums2[nums2Index];
        if (num1V >num2V) {
            result[nums1Index+nums2Index]=num2V;
            nums2Index++;
        }else{
            result[nums1Index+nums2Index]=num1V;
            nums1Index++;
        }
    }
    while (nums1Index<nums1Size) {
        double num1V = nums1[nums1Index];
        result[nums1Index+nums2Index]=num1V;
        nums1Index++;
    }
    while (nums2Index<nums2Size) {
        double num2V = nums2[nums2Index];
        result[nums1Index+nums2Index]=num2V;
        nums2Index++;
    }
    
    double resultV = 0;
    int allCount = nums1Size+nums2Size;
    int medianCount = allCount/2;
    if (allCount%2 == 1) {
        resultV = result[medianCount];
    }else{
        resultV = (result[medianCount]+result[medianCount-1])/2.0;
    }
    for (int i = 0; i<(nums1Size+nums2Size); i++) {
        printf("%i\n",result[i]);
    }
    free(result);
    return resultV;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
