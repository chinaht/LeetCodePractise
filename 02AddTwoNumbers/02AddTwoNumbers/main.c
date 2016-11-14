//
//  main.c
//  02AddTwoNumbers
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 fht. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    int carry = 0;
    while(p !=NULL || q != NULL){
        int pVal;
        int qVal;
        int sum;
        
        pVal = p!=NULL?p->val:0;
        qVal = q!=NULL?q->val:0;
        sum = pVal+qVal+carry;
        carry = sum/10;
        sum = sum%10;
        struct ListNode *tempResult = malloc(sizeof(struct ListNode));
        tempResult->val = sum;
        tempResult->next = NULL;
        if (result == NULL) {
            result = tempResult;
            temp = result;
        }else{
            temp->next = tempResult;
            temp = tempResult;
        }
        p = p->next;
        q = q->next;
    }
    free(temp);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
