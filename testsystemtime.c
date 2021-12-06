#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int main(int argc, char *argv[])
{
    int i = 0;
    for(i=0; i<50; i++){
        mkdir("./test");
        unlink("./test");
    }
    //sleep(1000);
    exit();
}