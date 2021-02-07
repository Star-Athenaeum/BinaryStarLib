#include "stdc.h"
#include "c_tests.h"

#include "sl_io.h"
#include "sl_json.h"
#include "sl_net.h"
#include "sl_string.h"
#include "sl_time.h"

int main()
{
    // Time

    printf(milliseconds_to_time_string(60000L));
    printf(milliseconds_to_date_string(60000L));

    //

    getchar();
    return 0;
}