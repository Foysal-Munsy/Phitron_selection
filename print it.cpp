#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cout << setw(n-i+1);
        for (int j = 1; j <= i*2-1; j++)
        {
            if (i % 2 == 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        cout << setw(n-i+1);
        for (int j = 1; j <= i*2-1; j++)
        {
            if (i % 2 == 1)
            {
                cout << ">";
            }
            else
            {
                cout << "<";
            }
        }
        cout << endl;
    }
    return 0;
}
/*
Problem Statement
---------------------
You will be given a positive integer N, you need to print a pattern according to the input. Some sample pattern is given in the sample input output.

Input Format
----------------
Input will contain only N.
Constraints

1 <= N <= 20
Output Format
-------------------
Output the pattern:-
Sample Input 0

5
Sample Output 0

    >
   <<<
  >>>>>
 <<<<<<<
>>>>>>>>>
 <<<<<<<
  >>>>>
   <<<
    >
Sample Input 1

4
Sample Output 1

   >
  <<<
 >>>>>
<<<<<<<
 >>>>>
  <<<
   >
Sample Input 2

1
Sample Output 2

>
*/
