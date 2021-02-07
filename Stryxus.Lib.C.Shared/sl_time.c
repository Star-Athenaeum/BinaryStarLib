#include "stdc.h"
#include "sl_time.h"

long long milliseconds_to_seconds(long long milliseconds)
{
	return milliseconds / 1000L;
}

long long milliseconds_to_minutes(long long milliseconds)
{
	return milliseconds / 1000L / 60L;
}

long long milliseconds_to_hours(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L;
}

long long milliseconds_to_days(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L;
}

long long milliseconds_to_weeks(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L;
}

long long milliseconds_to_months(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L / 4L;
}

long long milliseconds_to_years(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L / 4L / 12L;
}

char* milliseconds_to_time_string(long long milliseconds)
{
	long long h = milliseconds / 1000L / 60L / 60L;
	milliseconds = milliseconds - 1000L * 60L * 60L * h;
	long long m = milliseconds / 1000L / 60L;
	milliseconds = milliseconds - 1000L * 60L * m;
	long long s = milliseconds / 1000L;
	milliseconds = milliseconds - 1000L * s;

	char* h_char = "";
	char* m_char = "";
	char* s_char = "";

	snprintf(h_char, sizeof(long long), h);
	snprintf(m_char, sizeof(long long), m);
	snprintf(s_char, sizeof(long long), s);

	char* result = "";
	strcat_s(result, strlen(h_char) + strlen(m_char) + strlen(s_char) + 2, h_char, ":", m_char, ":", s_char);
	return result;
}

char* milliseconds_to_date_string(long long milliseconds)
{
	long long y = milliseconds / 1000L / 60L / 60L / 4L / 7L / 4L / 12L;
	milliseconds = milliseconds - 1000L * 60L * 60L;
	milliseconds = milliseconds * 24L * 24L;
	milliseconds = milliseconds * 7L * 4L * 12L * y;
	long long m = milliseconds / 1000L / 60L / 60L / 24L / 7L / 4L;
	milliseconds = milliseconds - 1000L * 60L * 60L;
	milliseconds = milliseconds * 24L * 24L;
	milliseconds = milliseconds * 7L * 4L * m;
	long long d = milliseconds / 1000 / 60L / 60L / 24L;
	milliseconds = milliseconds - 1000L * 60L * 60L * 24L * d;

	char* y_char = "";
	char* m_char = "";
	char* d_char = "";

	snprintf(y_char, sizeof(long long), y);
	snprintf(m_char, sizeof(long long), m);
	snprintf(d_char, sizeof(long long), d);

	char* result = "";
	strcat_s(result, strlen(y_char) + strlen(m_char) + strlen(d_char) + 2, y_char, ":", m_char, ":", d_char);
	return result;
}