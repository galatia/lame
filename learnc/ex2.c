#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int age = atoi(argv[1]);
    int height = atoi(argv[2]); 

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall.\n", height);

    return 0;
}
