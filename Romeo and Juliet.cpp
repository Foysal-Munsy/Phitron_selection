#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canReunite(int N, int E, vector<vector<int>> &adjList, int X, int Y, int K) {
    vector<int> distX(N, -1);
    vector<int> distY(N, -1);

    queue<int> qX;
    qX.push(X);
    distX[X] = 0;

    queue<int> qY;
    qY.push(Y);
    distY[Y] = 0;

    while (!qX.empty() || !qY.empty()) {
        if (!qX.empty()) {
            int u = qX.front();
            qX.pop();
            for (int v : adjList[u]) {
                if (distX[v] == -1) {
                    distX[v] = distX[u] + 1;
                    qX.push(v);
                }
            }
        }

        if (!qY.empty()) {
            int u = qY.front();
            qY.pop();
            for (int v : adjList[u]) {
                if (distY[v] == -1) {
                    distY[v] = distY[u] + 1;
                    qY.push(v);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (distX[i] != -1 && distY[i] != -1 && max(distX[i], distY[i]) <= K) {
            return true;
        }
    }

    return false;
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adjList(N);
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }
    int X, Y, K;
    cin >> X >> Y >> K;

    if (canReunite(N, E, adjList, X, Y, K))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
/*
Problem Statement
------------------
Romeo and Juliet are a newly married couple. They went to Switzerland for their honeymoon. They had a plan in mind: they would test their fortune by staying in different cities and seeing if they could reunite in at most K steps. Switzerland has N cities numbered from 0 to N-1, with E two-way roads connecting them.

Romeo is in city X, and Juliet is in city Y. In each step, they can cross one road and move from one city to another. It is not mandatory for both of them to cross; one can choose to stay in the same city if desired. However, the step will still be counted.

Can you tell if they can be reunited or not?

Input Format
------------
First line will contain N and E; The number of city and number of roads respectively.
Next E lines will contain A and B which means there is a road between city A and B.
Last line will contain X,Y and K.
Constraints

2 <= N <= 100
0 <= E <= 1000
0 <= X, Y < N and X != Y
0 <= K <= 1000
Output Format
-------------
Output "YES" if they can be reunited otherwise output "NO".
Sample Input 0

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
4 7 2
Sample Output 0

YES
Sample Input 1

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
2 7 2
Sample Output 1

YES
Sample Input 2

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
2 7 1
Sample Output 2

NO
Sample Input 3

7 6
4 0
0 1
3 1
3 2
4 2
5 6
4 6 10
Sample Output 3

NO
*/
