#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

long int recursive_factorial(long int n){
    if(n < 1){
        return 1;
    }
    return n*recursive_factorial(n-1);
}
int main(int argc, char *argv[])
{
    int i = 0;
    int a;
    for(i=0; i<50000000; i++){
        a = recursive_factorial(15);
    }
    printf(stdout, "%d\n", a);
    sleep(200);
    exit();
}