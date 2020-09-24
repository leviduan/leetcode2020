/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct object {
    int val;
    int index;
};

static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i, j;
    *returnSize = 2;
    struct object *objs = malloc(numsSize * sizeof(*objs));
    for (i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsSize, sizeof(*objs), compare);
    
    int count = 0;
    int *results = malloc(2 * sizeof(int));
    i = 0;
    j = numsSize - 1;
    while (i < j) {
        int diff = target - objs[i].val;
        if (diff > objs[j].val) {
            while (++i < j && objs[i].val == objs[i - 1].val) {}
        } else if (diff < objs[j].val) {
            while (--j > i && objs[j].val == objs[j + 1].val) {}
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }
    return 0;
}

// @lc code=end

