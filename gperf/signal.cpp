#include <gperftools/profiler.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void gprofStartAndStop(int signum)
{
    static int isStarted = 0;
    if (signum != SIGUSR1)
        return;

    if (!isStarted)
    {
        isStarted = 1;
        ProfilerStart("signal.prof");
        printf("ProfilerStart success\n");
    }
    else
    {
        ProfilerStop();
        printf("ProfilerStop success\n");
    }
}

void f()
{
    int i;
    for (i = 0; i < 1024 * 1024; ++i)
    {
        char *p = (char *)malloc(1024 * 1024);
        free(p);
    }
}

int main()
{
    signal(SIGUSR1, gprofStartAndStop);

    while (1)
    {
        printf("call f\n");
        f();
        sleep(1);
    }
    return 0;
}