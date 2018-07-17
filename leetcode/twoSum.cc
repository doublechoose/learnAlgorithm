/*
https://leetcode-cn.com/problems/two-sum/description/
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
#include<stdio.h>
#include<malloc.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *a  = (int *)malloc(sizeof(int)*2);
    int i,j;
    for(i=0;i<numsSize;i++){
        
        for(j = i+1; j < numsSize; j++)
        {
            if(nums[i]+nums[j] == target){
                a[0] = i;
                a[1] = j;
                break;
            }
        }
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a[] = {2,11,7,15};
    int* b;
    int target = 9;
    b = twoSum(a,4,target);
    printf("%d %d",b[0],b[1]);
    free(b);
    return 0;
}
