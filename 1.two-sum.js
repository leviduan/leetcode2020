/*
 * @lc app=leetcode id=1 lang=javascript
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */


var twoSum = function(nums, target) {
    let storeDic = nums.map((val, index) => {
        return {
            val: val,
            index: index, 
        }
    })
    storeDic.sort((min, max) => {
        return min.val - max.val
    })
    let i=0,j=nums.length-1
    while(i<j) {
        let diff = target - storeDic[j].val
        if (diff > storeDic[i].val) ++i
        if (diff < storeDic[i].val) --j
        if (diff == storeDic[i].val) return [storeDic[i].index, storeDic[j].index].sort()
    }
    return [0,0]
};

// console.log(twoSum([2,7,11,15], 9))

// @lc code=end

