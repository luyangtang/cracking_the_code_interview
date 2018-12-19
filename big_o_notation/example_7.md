# Example 7

Which of the following are equivalent to O(N)? Why?
O(N + P), where P < N/2
  - O(N + P) = O(N + N/2) = O(N)
0(2N)
  - O(2N) = O(N)
O(N + log N)
  - O(N) because log N is dominated by N
O(N + M)
  - Depending on the order of M, can be O(M) if M dominates N and vise versa
