#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    long long int i, partial_Sum, total_Sum;

    #pragma omp parallel private(partial_Sum) shared(total_Sum)
    {
        partial_Sum = 0;
        total_Sum = 0;

        #pragma omp for
        for(i = 1; i <= 1000000000000; i++){
            partial_Sum += i;
        }

        #pragma omp critical
        {
            //add each threads partial sum to the total sum
            total_Sum += partial_Sum;
        }
    }
    printf("Total Sum: %lld\n", total_Sum);
    return 0;
}
