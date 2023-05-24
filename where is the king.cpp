#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findKingIndex(vector<int> &A)
{
    int n = A.size();
    int totalSum = accumulate(A.begin(), A.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum -= A[i];
        if (leftSum == totalSum)
        {
            return i;
        }
        leftSum += A[i];
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << findKingIndex(A) << endl;
    }
    return 0;
}
/*
Problem Statement
---------------------
Once upon a time, King Alexander of Greece lost his kingdom in a war. He could have saved his life by hiding in a tunnel. He told his commander how he could be found in the tunnel.

The tunnel is made of blocks, each with a number written on the wall. King Alexander explained that he would be in the leftmost block where the sum of all the numbers strictly to the left of that block is equal to the sum of all the numbers strictly to the right of the block. Each block can be represented by an index starting from zero. Can you now tell me the leftmost index where the king is hidden?

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

If the king cannot be found, it means that he is no longer alive. In that case, you need to indicate -1.

Input Format
---------------
First line will contain T, the number of test cases.
Second line will contain N, the number of blocks in that tunnel.
Third line will contain an integer array A of N values that were written on each block.
Constraints

1 <= T <= 1000
1 <= N <= 10^5
-1000 <= A[i] <= 1000 ; Where 0 <= i < N
Output Format
--------------
Output the index of the block in which king could be found, otherwise print -1.
Sample Input 0

3
6
1 7 3 6 5 6
3
1 2 3
3
2 1 -1
Sample Output 0

3
-1
0
Explanation 0

In the first test case, the index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

In the second test case, there is no index that satisfies the conditions in the problem statement.

In the third test case, the index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/
