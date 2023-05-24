//this approach terminated due to timeout
//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    // Write C++ code here
//    int t;
//    cin>> t;
//    while(t--)
//    {
//        int L, R;
//        cin>> L>> R;
//
//        long long sum =0;
//        if (L > R)
//            swap(L, R);
////        if(L<R)
////        {
//            for(int i=L; i<=R; i++)
//                sum +=i;
//            cout<< sum << endl;
////        }
//
//    }
//
//
//
//    return 0;
//}

//this approach working fine
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;

        long long sum = 0;
        if (L > R)
            swap(L, R);

        sum = (long long)(R - L + 1) * (L + R) / 2;
        cout<< R<<"-" << L <<"="<< (R-L)<<endl;
        cout << sum << endl;
    }

    return 0;
}
/*
Problem Statement
-----------------
You are given a range represented by two integers L and R,and you should find the sum of the numbers in the range between L and R inclusive.

Input Format
------------
First line contains a number T – the number of test cases.
Each of the next T lines contains two numbers L,R.
Constraints

1 ≤ T ≤ 10^5
1≤ L,R ≤ 10^9.
Output Format
-------------
For each test case, print the sum.
Sample Input 0

4
3 6
2 11
4 16
17 7
Sample Output 0

18
65
130
132
*/
