#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;


// sum {B[i]*(-2)^i for i=0...N-1}

struct Results
{
    int* B;
    int N;
};

inline int exp_mine(long i) { long ret = ((i % 2) == 0) ? exp2l(i) : -exp2l(i); return ret; };

struct Results solution(int A[], int M)
{
    struct Results result;

    long i = 0, j = 0;
    long sum = 0;
    long tmp_pos = 0;
    long tmp_neg = 0;
    long tmp = 0;
    long num_input = 0;
    long num_objective = 0;

    for (i = 0; i < M; i++)
    {
        if (A[i] > 0)
            sum += exp_mine(i)*A[i];
    }

    num_input = sum;
    num_objective = -num_input;
    cout << num_input << " -> " << num_objective << endl;

    // get to the exponent where the sum is greater than the number we need, summing only the positives or negatives
    // if objective is positive, consider the positive sum only
    // if objective is negative, consider the negative sum only
    j = 0;
    while (((num_objective > 0) && (tmp_pos < num_objective)) || ((num_objective < 0) && (tmp_neg > num_objective)))
    {
        // if exponent is even, it is positive
        if ((j % 2) == 0)
            tmp_pos += exp_mine(j);
        else // if odd, then negative
            tmp_neg += exp_mine(j);
        j++;
    }
    j--;
    cout << "j?" << j << endl;

    sum = exp_mine(j);
    cout << j << 1 << " ";

    // prepare output
    i = j+1;
    result.B = (int*)malloc(sizeof(int)*i);
    result.B[j] = 1;
    result.N = i;

    // until we get the objective, add the other exponents if it converges
    while ((sum != num_objective) && (j > 0))
    {
        j--;
        tmp = exp_mine(j);

        // it converges if summing it to the current number will get us closer to the result we seek:
        // current + exponent has a smaller difference to objective than current
        if (abs(abs(num_objective)-abs(sum+tmp)) <= abs(abs(num_objective)-abs(sum)))
        {
            sum += tmp;
            cout << j << 1 << " ";
            result.B[j] = 1;
        }
        else
        {
            cout << j << 0 << " ";
            result.B[j] = 0;
        }
    }
    cout << endl;

    cout << sum << endl;

    return result;
};


int main(int argc, char** argv)
{
    // 9 -> -9
    int A[] = {1,0,0,1,1};
    Results res = solution(A, 5);

    // -9 -> 9
    //int A[] = {1,1,0,1};
    //Results res = solution(A, 4);

    free(res.B);
    return 0;
}
