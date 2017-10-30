#include <stdio.h>


int fibonacciCalculation(int fibIndex)
{
    
    int firstIndex = 1, secondIndex = 1, nextIndex;


    for (int i = 1; i <= fibIndex-2; ++i)
    {
        nextIndex = firstIndex + secondIndex;
        firstIndex = secondIndex;
        secondIndex = nextIndex;
    }    
    return nextIndex;
}


void printFibonacciSeries (int fibIndex){

    int firstIndex = 1, secondIndex = 1, nextIndex;

    printf("Fibonacci series: ");

    for (int i = 1; i <= fibIndex; ++i)
    {
        printf("%d, ", firstIndex);
        nextIndex = firstIndex + secondIndex;
        firstIndex = secondIndex;
        secondIndex = nextIndex;
    }
}

int findClosestFibonacciNumber (int findClosest){

    int currentFibonacciNumber=0;
    int currentIndex =0;

    if (findClosest<=0){
        return 1;

    }else {


        for (int i = 1; i <= findClosest; ++i) {
            currentFibonacciNumber = fibonacciCalculation(i);

            if (currentFibonacciNumber >= findClosest) {
                currentIndex = i - 1;//take previous index - the lower
                break;

            } else {
                currentIndex = i;
            }

        }
        return currentIndex;
    }

}

void menu(){

    printf("Please select option from menu below:\n");
    printf("1. Calculate Fibonacci number\n");
    printf("2. Find closest Fibonacci number\n");

  }


int main ()

{
    int number, result, findClosest,choice;

    menu();

    scanf("%d",&choice);


    if (choice==1){

        printf("Enter a positive number: ");
        scanf("%d", &number);
        result= fibonacciCalculation(number);

        if (result<0){
            printf("%d - Error: Input positive number !\n",result);
        } else if (result==0){
            printf("%d - Error: Input larger number than 0!\n",result);
        }else{
            printf("Fibonacci number: %d\n", result);
        }
        printFibonacciSeries(number);
    } else if (choice==2){

        printf("Enter a positive number: ");
        scanf("%d", &number);
        printFibonacciSeries(number);
        findClosest=findClosestFibonacciNumber(number);
        printf("\nClosest Fibonacci number: %d (Closest in FS),%d (Index in FS)\n", fibonacciCalculation(findClosest),findClosest);

    } else {
        printf("Enter correct number (1 or 2)");
    }

    return 0;
}
