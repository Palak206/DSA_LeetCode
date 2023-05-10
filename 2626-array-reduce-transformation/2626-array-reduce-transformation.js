/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let sum = init;
    for(const i of nums){
        sum = fn(sum,i);
    }
    return sum;
    
};