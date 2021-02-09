#include "stdc.h"
#include "sl_time.h"

double milliseconds_to_seconds(long long milliseconds)
{
	return milliseconds / 1000L;
}

double milliseconds_to_minutes(long long milliseconds)
{
	return milliseconds / 1000L / 60L;
}

double milliseconds_to_hours(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L;
}

double milliseconds_to_days(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L;
}

double milliseconds_to_weeks(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L;
}

double milliseconds_to_months(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L / 4L;
}

double milliseconds_to_years(long long milliseconds)
{
	return milliseconds / 1000L / 60L / 60L / 24L / 7L / 4L / 12L;
}

char* milliseconds_to_time_string(long long milliseconds)
{
	unsigned int s = (unsigned int)(milliseconds * pow(10, -3)) % 60;
	unsigned int m = (unsigned int)((milliseconds * pow(10, -3)) / 60) % 60;
	unsigned int h = (unsigned int)((milliseconds * pow(10, -3)) / 60 / 60) % 60;

	int h_len = snprintf(NULL, 0, "%d", h) + 2;
	int m_len = snprintf(NULL, 0, "%d", m) + 2;
	int s_len = snprintf(NULL, 0, "%d", s) /* FIRST CHARACTER FILL & NULL TERMINATOR */ + 2;

	char* h_char = malloc(h_len);
	char* m_char = malloc(m_len);
	char* s_char = malloc(s_len);

	snprintf(h_char, h_len, "%s%d", h < 10 ? "0" : "", h);
	snprintf(m_char, m_len, "%s%d", m < 10 ? "0" : "", m);
	snprintf(s_char, s_len, "%s%d", s < 10 ? "0" : "", s);

	int full_length = sizeof(h_char) + sizeof(m_char) + sizeof(s_char) + 1;
	char* result = malloc(full_length);
	snprintf(result, full_length, "%s%s%s%s%s", h_char, ":", m_char, ":", s_char);
	return result;
}

char* milliseconds_to_date_string(long long milliseconds)
{
	double y = (milliseconds / 3.6) * pow(10, -3) * pow(10, -3);
	double m = (milliseconds / 6)	* pow(10, -3) * pow(10, -1);
	double d = (milliseconds / 1)	* pow(10, -3) * 10;

	char y_char[sizeof y];
	char m_char[sizeof m];
	char d_char[sizeof d];

	if (snprintf(y_char, sizeof y, "%f", y) && snprintf(m_char, sizeof m, "%f", m) && snprintf(d_char, sizeof d, "%f", d))
	{
		int result_len = sizeof(char) * (sizeof y_char + sizeof m_char + sizeof d_char + 2);
		char* result = (char*)malloc(result_len);
		if (result)
		{
			strcat_s(result, sizeof result, d_char, ":", m_char, ":", y_char);
			return result;
		}
		else return (char*)-1;
	}
	else return (char*)-1;
}