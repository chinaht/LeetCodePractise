//
//  main.cpp
//  C++algorithmPractice
//
//  Created by apple on 17/1/20.
//  Copyright © 2017年 fht. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
void quickSort(T *arr, T left, T right);


int main(int argc, const char * argv[]) {
 
    std::cout << "Hello, World!\n";
    int n = 6000000;
    int *arr = (int *)malloc(n*sizeof(int));
    for (int i = 0; i <n; i++) {
        int r = (int)random();
        arr[i] = r;
    }
    //快排
    int left = 0;
    int right = n;
    clock_t start = clock();
    quickSort(arr, left, right);
    clock_t end = clock();
    cout<<(end -start)<<endl;
    //    //输出
//    for (int i = left; i <= right; ++i)
//    {
//        cout<<arr[i]<<endl;
//    }
    free(arr);
    return 0;
}

template <typename T>
void quickSort(T *arr, T left, T right){
    if (left >= right) {
        return;
    }
    //每次比较得到一个中间哨兵位置
    T key = arr[left];
    T middleIndex = left;
    for (T i = left+1; i<=right; i++) {
        T indexValue = arr[i];
        if (indexValue <= key) {
            middleIndex++;
            arr[i] = arr[middleIndex];
            arr[middleIndex] = indexValue;
        }
    }
    arr[left] = arr[middleIndex];
    arr[middleIndex] = key;
    
    quickSort(arr,left,middleIndex-1);
    quickSort(arr,middleIndex+1,right);
}
