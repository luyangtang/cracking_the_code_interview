# Example 8


Suppose we had an algorithm that took in an array of strings, sorted each string, and then sorted the full
array. What would the runtime be?

Suppose the array have size L and s being the length of the longest string. Then to sort L strings the complexity is
O(L) * O(s log s) = O(L * s * log s)

Sorting an array of size L has complexity involves O(L log L) many comparisons and each comparison has time complexity O(s) so the total complexity is O(L * s * log L).

Combining the two gives time complexity of
O(L * s * (log s + log L)).
