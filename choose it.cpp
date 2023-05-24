#include <iostream>
#include <vector>
using namespace std;

int maxChocolates(int N, int K, vector<int> &A, vector<int> &W)
{
    vector<int> dp(K + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = W[i]; j <= K; j++)
        {
            dp[j] = max(dp[j], dp[j - W[i]] + A[i]);
        }
    }
    return dp[K];
}


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> W(N);
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }
    cout << maxChocolates(N, K, A, W) << endl;
    return 0;
}
/*
Problem Statement
------------------
You are in your dream where you have gone to your favorite chocolate shop, and in your dream, you can take chocolate an infinite number of times! In the shop, there are several chocolate boxes, and in each box, there could be several chocolates. However, there is a condition: each box has a weight, and you can't take an infinite amount of weight! You can only take a total of W weight.

So, if there are N chocolate boxes where you know the number of chocolates and the weight of each box, and the maximum weight you can carry, can you tell the maximum number of chocolates you can take in your dream?

Input Format
-------------
First line will contain N and K, the number of chocolate boxed and the maximum weight you can carry respectively.
The next line will contain and array A of size N, where each value represent the number of chocolates in each box.
The next line will contain and array W of size N, where each value represent the weight of each chocolate box.
Constraints

1 <= N <= 1000
0 <= K <= 1000
1 <= A[i] <= 1000; where 0 <= i < N
1 <= W[i] <= 1000; where 0 <= i < N
Output Format
--------------
Output the maximum number of chocolates you can take in your dream.
Sample Input 0

5 12
3 4 5 2 10
4 3 5 2 7
Sample Output 0

16
Explanation 0

The maximum will be if you choose the boxes with 4, 2 and 10 chocolates which will take 12 weights.
Sample Input 1

5 32
3 4 5 2 10
4 3 5 2 7
Sample Output 1

44
Explanation 1

The maximum will be if you choose the box with 4 chocolates 1 time, and the box with 10 chocolates 4 times; which will cost a total of 31 weights.

*/
