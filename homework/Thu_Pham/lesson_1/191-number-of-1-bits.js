//Solution for https://leetcode.com/problems/number-of-1-bits/

/*
 * @param {number} n - a positive integer
 * @return {number}
 */
 var hammingWeight = function(n) {
    return n.toString(2).replace(/0/g, "").length;
};