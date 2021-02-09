#pragma once

double milliseconds_to_seconds(long long milliseconds);

double milliseconds_to_minutes(long long milliseconds);

double milliseconds_to_hours(long long milliseconds);

double milliseconds_to_days(long long milliseconds);

double milliseconds_to_weeks(long long milliseconds);

double milliseconds_to_months(long long milliseconds);

double milliseconds_to_years(long long milliseconds);

char* milliseconds_to_time_string(long long milliseconds);

char* milliseconds_to_date_string(long long milliseconds);