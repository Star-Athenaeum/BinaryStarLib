#include "stryxuslib.h"
#include "c_tests.h"

int main()
{
    // Time

    printf(milliseconds_to_time_string(60000L));
    printf(milliseconds_to_date_string(60000L));

    //

    getchar();
    return 0;
}