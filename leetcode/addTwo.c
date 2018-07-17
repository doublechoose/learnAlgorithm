#include<stdio.h>
#include<malloc.h>
// Definition for singly-linked list.
// https://leetcode-cn.com/problems/add-two-numbers/description/
/**
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
struct ListNode {
    int val;
    struct ListNode *next;
 };
 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int temp = 0;
    struct ListNode* first=l1,*second = l2;
    struct ListNode* result,*third;
    result = third= (struct ListNode*)malloc(sizeof(struct ListNode));

    while(first!=NULL||second!=NULL){
        
        int x = (first!=NULL)?first->val:0;
        int y = (second!=NULL)?second->val:0;

        int sum = temp+x+y;
        temp = sum /10;

        third->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        third = third->next;
        third->val = sum % 10;
        if(first!=NULL){
            first = first->next;
        }
        if(second!=NULL){
            second = second->next;
        }
        
    }
    if(temp > 0){
        third->next =(struct ListNode*)malloc(sizeof(struct ListNode));
        third->next->val = temp;
        third->next->next = NULL;
    }else{
        third->next = NULL;
    }

    return result->next;
}

int main(int argc, char const *argv[])
{
    struct ListNode* l1,*temp1;
    temp1 = l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2,*temp2;
    temp2 = l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp1->val = 1;
    temp1->next =  (struct ListNode*)malloc(sizeof(struct ListNode));
    temp1 = l1->next;
    temp1->val = 8;
    // temp1->next=  (struct ListNode*)malloc(sizeof(struct ListNode));
    // temp1 = temp1->next;
    // temp1->val = 3;
    temp1->next = NULL;
    
    l2->val = 0;
    // l2->next =  (struct ListNode*)malloc(sizeof(struct ListNode));
    // temp2 = l2->next;
    // temp2->val = 6;
    // temp2->next=  (struct ListNode*)malloc(sizeof(struct ListNode));
    // temp2 = temp2->next;
    // temp2->val = 4;
    temp2->next = NULL;

    
    struct ListNode* result = addTwoNumbers(l1,l2);

    while(result!=NULL){
        printf("%d ->",result->val);
        result = result->next;
    }
    return 0;
}
