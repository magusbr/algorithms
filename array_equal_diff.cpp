#include <stdio.h>
#include <iostream>

using namespace std;

int solution(int X, int A[], int N)
{
    int i = 0;
    int equal_times = 0;
    int equal_times_end = 0;
    int diff_times = 0;
    int total_times = 0;

    for (i = 0; i < N; i++)
        if (A[i] == X) total_times++;

    for (i = N-1; i >= 0; i--)
    {
        if (A[N+1-i] == X) equal_times++;
        if (A[i] != X) diff_times++;
        else equal_times_end++;

        if ((equal_times + equal_times_end == total_times) && (equal_times == diff_times))
            return i;
    }

    return 0;
}

int main(int argc, char** argv)
{
    //int A[] = {5, 5, 1, 7, 2, 3, 5};
    //int A[] = {5, 5, 1, 7, 2, 3, 5, 1};
    //int A[] = {1, 5, 5, 1, 7, 2, 3, 5, 1};
    int A[] = {1, 5, 1, 2};

    cout << solution(5, A, sizeof(A)/sizeof(int)) << endl;

    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
