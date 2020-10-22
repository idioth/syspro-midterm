#include <stdio.h>
  
int main(void)
{
        float system, algorithm, network;
        float average;

        printf("Input the system programming, algortihm, and network score:");
        scanf("%f%f%f", &system, &algorithm, &network);

        average = (system + algorithm + network) / 3;

        printf("The average of the three subjects is %.2f.\n", average);

        return 0;

}

