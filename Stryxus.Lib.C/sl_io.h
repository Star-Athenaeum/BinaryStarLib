#pragma once

bool file_exists(const char file_path[]);
void create_file(const char file_path[]);

//

typedef enum
{
	BYTE,
	KILO_BYTE,
	MEGA_BYTE,
	GIGA_BYTE,
	TERRA_BYTE,
	PETTA_BYTE,
	EXA_BYTE,
	ZETTA_BYTE,
	YOTTA_BYTE
} BYTE_MAGNITUDE;

typedef enum
{
	BIT,
	KILO_BIT,
	MEGA_BIT,
	GIGA_BIT,
	TERRA_BIT,
	PETTA_BIT,
	EXA_BIT,
	ZETTA_BIT,
	YOTTA_BIT
} BIT_MAGNITUDE;

//

void convert_data_magnitude_to_bits(double value, BYTE_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude);
void convert_data_magnitude_to_bytes(double value, BIT_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude);
void convert_data_magnitude_in_bits(double value, BIT_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude);
void convert_data_magnitude_in_bytes(double value, BYTE_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude);

double convert_data_magnitude_to_bits_copy(double value, BYTE_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude);
double convert_data_magnitude_to_bytes_copy(double value, BIT_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude);
double convert_data_magnitude_in_bits_copy(double value, BIT_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude);
double convert_data_magnitude_in_bytes_copy(double value, BYTE_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude);

//