#include <time.h>
/* ... */
static double TimeSpecToSeconds(struct timespec* ts)
{
    return (double)ts->tv_sec + (double)ts->tv_nsec / 1000000000.0;
}
/* ... */
    struct timespec start;
    struct timespec end;
    double elapsedSeconds;
    if(clock_gettime(CLOCK_MONOTONIC, &start))
    { /* handle error */ }
    /* Do stuff */
    if(clock_gettime(CLOCK_MONOTONIC, &end))
    { /* handle error */ }
    elapsedSeconds = TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start);
    
    
    
    
