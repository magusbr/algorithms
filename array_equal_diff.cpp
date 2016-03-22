#include <stdio.h>
#include <iostream>

using namespace std;

int solution(int X, int A[], int N)
{
    int i = 0, j = 0;
    int equal_times = 0;
    int equal_times_end = 0;
    int diff_times = 0;
    int total_times = 0;

    for (i = 0; i < N; i++)
        if (A[i] == X) total_times++;

    i = 0;
    j = N-1;
    while (true)
    {
        // first get the different part
        if (diff_times == equal_times)
        {
            if (A[j] != X) diff_times++;
            else equal_times_end++;
            j--;
        }

        // only advance equal part after different part advanced first
        if (diff_times > equal_times)
        {
            if (A[i] == X) equal_times++;
            i++;
        }

        // return number obtained from right side
        if ((equal_times + equal_times_end == total_times) && (equal_times == diff_times))
            return N-(diff_times+equal_times_end);
    }

    return 0;
}

int main(int argc, char** argv)
{
    //int A[] = {5, 5, 1, 7, 2, 3, 5};
    //int A[] = {5, 5, 1, 7, 2, 3, 5, 1};
    //int A[] = {1, 5, 5, 1, 7, 2, 3, 5, 1};
    //int A[] = {1, 5, 1, 2};
    //int A[] = {1, 5, 1, 2, 5, 5, 5};
    //int A[] = {1, 5, 5, 5, 1, 2};
    // can add 5 at both ends in the example below but answer will always be 1
    //int A[] = {5, 5, 5, 1, 5, 5};
    int A[] = {1, 1, 1, 1, 5, 5, 5, 5, 1};


    cout << solution(5, A, sizeof(A)/sizeof(int)) << endl;

    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
