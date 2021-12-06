#include "types.h"
#include "user.h"
#include "date.h"

int stdout = 1;
int stderr = 2;

void display_time(int);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(stdout, "Tempo de usuário:\n");
        display_time(0);
        printf(stdout, "Tempo de sistema:\n");
        display_time(0);
        printf(stdout, "Tempo total:\n");
        display_time(0);

        exit();
    }
    int start_count = uptime();
    time();

    int pid = fork();
    if (pid < 0)
    {
        printf(stdout, "time: error executing command\n");
        exit();
    }
    else if (pid == 0)
    {
        exec(argv[1], argv + 1);
        exit();
    }
    else if (pid > 0)
    {
        wait();
    }
    int sys_time = time();
    int total_time = uptime() - start_count;
    int user_time = total_time - sys_time;
    printf(stdout, "Tempo de usuário: ");
    display_time(user_time);
    printf(stdout, "Tempo de sistema: ");
    display_time(sys_time);
    printf(stdout, "Tempo total: ");
    display_time(total_time);
    exit();
}

void display_time(int user_time)
{
    int miliseconds = user_time % 100;
    int seconds = user_time / 100;
    if (miliseconds < 10)
        printf(stdout, "%d.00%ds\n", seconds, miliseconds);
    else if (miliseconds < 100)
        printf(stdout, "%d.0%ds\n", seconds, miliseconds);
    else
        printf(stdout, "%d.%ds\n", seconds, miliseconds);
}
