#include <stdio.h>
#include <time.h>

int main() {
    long int sec_since_epoch;
    struct tm current_time, *time_ptr;

    int hr, min, sec, day, mon, y;
    sec_since_epoch = time(0);
    printf("time() - seconds since epoch: %ld\n", sec_since_epoch);

    time_ptr = &current_time;

    localtime_r(&sec_since_epoch, time_ptr);

    //3 different way to access struct elements

    hr = current_time.tm_hour;
    min = time_ptr->tm_min;
    sec = *((int *)time_ptr);

    printf("Current time is: %02d:%02d:%02d\n", hr, min, sec);
}