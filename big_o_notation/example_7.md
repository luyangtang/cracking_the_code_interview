# Example 7

Which of the following are equivalent to ![O(N)](https://latex.codecogs.com/svg.latex?O%28N%29)? Why?

![O(N + P)](https://latex.codecogs.com/svg.latex?O%28N%20&plus;%20P%29), where ![P < \frac{N}{2}](https://latex.codecogs.com/svg.latex?P%20%3C%20%5Cfrac%7BN%7D%7B2%7D)
  - So ![O(N + P) = O\left(N + \frac{N}{2}\right) = O(N)](https://latex.codecogs.com/svg.latex?O%28N%20&plus;%20P%29%20%3D%20O%5Cleft%28N%20&plus;%20%5Cfrac%7BN%7D%7B2%7D%5Cright%29%20%3D%20O%28N%29)
  
![O(2N)](https://latex.codecogs.com/svg.latex?O%282N%29)
  - ![O(2N) = O(N)](https://latex.codecogs.com/svg.latex?O%282N%29%20%3D%20O%28N%29)
  
![O(N + \log N)](https://latex.codecogs.com/svg.latex?O%28N%20&plus;%20%5Clog%20N%29)
  - ![O(N)](https://latex.codecogs.com/svg.latex?O%28N%29) because ![\log N](https://latex.codecogs.com/svg.latex?%5Clog%20N) is dominated by ![N](https://latex.codecogs.com/svg.latex?N)
  
![O(N + M)](https://latex.codecogs.com/svg.latex?O%28N%20&plus;%20M%29)
  - Depending on the order of ![M](https://latex.codecogs.com/svg.latex?M), can be ![O(M)](https://latex.codecogs.com/svg.latex?O%28M%29) if ![M](https://latex.codecogs.com/svg.latex?M) dominates ![M](https://latex.codecogs.com/svg.latex?N) and vise versa
