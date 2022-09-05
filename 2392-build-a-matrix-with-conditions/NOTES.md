Build a graph using conditions and find topological sorting of them
​
1. if top sort is not possible, then matrix is not possible (in case of cycle)
2. for a vertex find the i index in rowTopoSort and jth Index in columnTopoSort, those indices will be the indices of matrix and vertex will be the value at matrix[i][j]