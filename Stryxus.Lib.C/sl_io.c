#include "pch.h"
#include "sl_io.h"

bool file_exists(const char file_path[])
{
	struct stat buffer;
	return stat(file_path, &buffer) == 0;
}

void create_file(const char file_path[])
{
	FILE *f;
	fopen_s(&f, file_path, "r");
	if (f != NULL) fclose(f);
}

//

// TODO: Add 'ibi' bits and bytes

unsigned long	base_bit;
unsigned long	bits_in_kilo;
unsigned long	bits_in_mega;
unsigned long	bits_in_giga;
unsigned long	bits_in_terra;
unsigned long	bits_in_petta;
unsigned long	bits_in_exa;
unsigned long	bits_in_zetta;
unsigned long	bits_in_yotta;

unsigned long	base_byte;
unsigned long	bytes_in_kilo;
unsigned long	bytes_in_mega;
unsigned long	bytes_in_giga;
unsigned long	bytes_in_terra;
unsigned long	bytes_in_petta;
unsigned long	bytes_in_exa;
unsigned long	bytes_in_zetta;
unsigned long	bytes_in_yotta;

#define			base_bit		(base_bit		=	1u)
#define			bits_in_kilo	(bits_in_kilo	=	base_bit		* 1000u)
#define			bits_in_mega	(bits_in_mega	=	bits_in_kilo	* 1000u)
#define			bits_in_giga	(bits_in_giga	=	bits_in_mega	* 1000u)
#define			bits_in_terra	(bits_in_terra	=	bits_in_giga	* 1000u)
#define			bits_in_petta	(bits_in_petta	=	bits_in_giga	* 1000u)
#define			bits_in_exa		(bits_in_exa	=	bits_in_petta	* 1000u)
#define			bits_in_zetta	(bits_in_zetta	=	bits_in_exa		* 1000u)
#define			bits_in_yotta	(bits_in_yotta	=	bits_in_zetta	* 1000u)

#define			base_byte		(base_byte		=	base_bit		* 8u)
#define			bytes_in_kilo	(bytes_in_kilo	=	base_byte		* 1000u)
#define			bytes_in_mega	(bytes_in_mega	=	bytes_in_kilo	* 1000u)
#define			bytes_in_giga	(bytes_in_giga	=	bytes_in_mega	* 1000u)
#define			bytes_in_terra	(bytes_in_terra =	bytes_in_giga	* 1000u)
#define			bytes_in_petta	(bytes_in_petta =	bytes_in_terra	* 1000u)
#define			bytes_in_exa	(bytes_in_exa	=	bytes_in_petta	* 1000u)
#define			bytes_in_zetta	(bytes_in_zetta =	bytes_in_exa	* 1000u)
#define			bytes_in_yotta	(bytes_in_yotta =	bytes_in_zetta	* 1000u)

void convert_data_magnitude_to_bits(double value, BYTE_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == KILO_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == MEGA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == GIGA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == TERRA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == PETTA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == EXA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == ZETTA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == YOTTA_BYTE)
	{
		if (to_magnitude == BIT)				value = value * base_byte;
		else if (to_magnitude == KILO_BIT)		value = (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		value = (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		value = (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		value = (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		value = (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		value = (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		value = (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		value = (value / bytes_in_yotta) * base_byte;
	}
}

void convert_data_magnitude_to_bytes(double value, BIT_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BIT)
	{
		if (to_magnitude == BYTE)				value = value / base_byte;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_exa;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_zetta;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_yotta;
	}
	else if (from_magnitude == KILO_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == KILO_BYTE)		value = value / base_byte;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_exa;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_zetta;
	}
	else if (from_magnitude == MEGA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		value = value / base_byte;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_exa;
	}
	else if (from_magnitude == GIGA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		value = value / base_byte;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_petta;
	}
	else if (from_magnitude == TERRA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	value = value / base_byte;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_terra;
	}
	else if (from_magnitude == PETTA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	value = value / base_byte;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_giga;
	}
	else if (from_magnitude == EXA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == EXA_BYTE)		value = value / base_byte;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_mega;
	}
	else if (from_magnitude == ZETTA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_zetta;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	value = value / base_byte;
		else if (to_magnitude == YOTTA_BYTE)	value = (value / base_byte) / bytes_in_yotta;
	}
	else if (from_magnitude == YOTTA_BIT)
	{
		if (to_magnitude == BYTE)				value = (value / base_byte) * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		value = (value / base_byte) * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		value = (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		value = (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	value = (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	value = (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		value = (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	value = (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	value = value / base_byte;
	}
}

void convert_data_magnitude_in_bits(double value, BIT_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BIT)
	{
		if (to_magnitude == BIT)				value = value;
		else if (to_magnitude == KILO_BIT)		value = value / bits_in_kilo;
		else if (to_magnitude == MEGA_BIT)		value = value / bits_in_mega;
		else if (to_magnitude == GIGA_BIT)		value = value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		value = value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		value = value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == KILO_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value;
		else if (to_magnitude == MEGA_BIT)		value = value / bits_in_mega;
		else if (to_magnitude == GIGA_BIT)		value = value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		value = value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		value = value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == MEGA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value;
		else if (to_magnitude == GIGA_BIT)		value = value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		value = value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		value = value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == GIGA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value;
		else if (to_magnitude == TERRA_BIT)		value = value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		value = value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == TERRA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value;
		else if (to_magnitude == PETTA_BIT)		value = value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == PETTA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		value = value;
		else if (to_magnitude == EXA_BIT)		value = value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == EXA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		value = value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		value = value;
		else if (to_magnitude == ZETTA_BIT)		value = value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == ZETTA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		value = value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		value = value * bits_in_zetta;
		else if (to_magnitude == ZETTA_BIT)		value = value;
		else if (to_magnitude == YOTTA_BIT)		value = value / bits_in_yotta;
	}
	else if (from_magnitude == YOTTA_BIT)
	{
		if (to_magnitude == BIT)				value = value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		value = value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		value = value * bits_in_zetta;
		else if (to_magnitude == ZETTA_BIT)		value = value * bits_in_yotta;
		else if (to_magnitude == YOTTA_BIT)		value = value;
	}
}

void convert_data_magnitude_in_bytes(double value, BYTE_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BYTE)
	{
		if (to_magnitude == BYTE)				value = value;
		else if (to_magnitude == KILO_BYTE)		value = value / bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		value = value / bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	value = value / bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	value = value / bytes_in_petta;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_exa;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_zetta;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_yotta;
	}
	else if (from_magnitude == KILO_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_kilo;
		else if (to_magnitude == KILO_BYTE)		value = value;
		else if (to_magnitude == MEGA_BYTE)		value = value / bytes_in_zetta;
		else if (to_magnitude == GIGA_BYTE)		value = value / bytes_in_exa;
		else if (to_magnitude == TERRA_BYTE)	value = value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	value = value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == MEGA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_mega;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		value = value;
		else if (to_magnitude == GIGA_BYTE)		value = value / bytes_in_exa;
		else if (to_magnitude == TERRA_BYTE)	value = value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	value = value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == GIGA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_giga;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_mega;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		value = value;
		else if (to_magnitude == TERRA_BYTE)	value = value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	value = value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == TERRA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_terra;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_giga;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		value = value * bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	value = value;
		else if (to_magnitude == PETTA_BYTE)	value = value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == PETTA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_petta;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_terra;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_giga;
		else if (to_magnitude == GIGA_BYTE)		value = value * bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	value = value * bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	value = value;
		else if (to_magnitude == EXA_BYTE)		value = value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == EXA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		value = value * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	value = value * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	value = value * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		value = value;
		else if (to_magnitude == ZETTA_BYTE)	value = value / bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_mega;
	}
	else if (from_magnitude == ZETTA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_zetta;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_exa;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_petta;
		else if (to_magnitude == GIGA_BYTE)		value = value * bytes_in_terra;
		else if (to_magnitude == TERRA_BYTE)	value = value * bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	value = value * bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		value = value * bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	value = value;
		else if (to_magnitude == YOTTA_BYTE)	value = value / bytes_in_kilo;
	}
	else if (from_magnitude == YOTTA_BYTE)
	{
		if (to_magnitude == BYTE)				value = value * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		value = value * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		value = value * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		value = value * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	value = value * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	value = value * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		value = value * bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	value = value * bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	value = value;
	}
}

double convert_data_magnitude_to_bits_copy(double value, BYTE_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == KILO_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == MEGA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == GIGA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == TERRA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == PETTA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == EXA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == ZETTA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	else if (from_magnitude == YOTTA_BYTE)
	{
		if (to_magnitude == BIT)				return value * base_byte;
		else if (to_magnitude == KILO_BIT)		return (value / bytes_in_kilo) * base_byte;
		else if (to_magnitude == MEGA_BIT)		return (value / bytes_in_mega) * base_byte;
		else if (to_magnitude == GIGA_BIT)		return (value / bytes_in_giga) * base_byte;
		else if (to_magnitude == TERRA_BIT)		return (value / bytes_in_terra) * base_byte;
		else if (to_magnitude == PETTA_BIT)		return (value / bytes_in_petta) * base_byte;
		else if (to_magnitude == EXA_BIT)		return (value / bytes_in_exa) * base_byte;
		else if (to_magnitude == ZETTA_BIT)		return (value / bytes_in_zetta) * base_byte;
		else if (to_magnitude == YOTTA_BIT)		return (value / bytes_in_yotta) * base_byte;
	}
	return 0L;
}

double convert_data_magnitude_to_bytes_copy(double value, BIT_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BIT)
	{
		if (to_magnitude == BYTE)				return value / base_byte;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_exa;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_zetta;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_yotta;
	}
	else if (from_magnitude == KILO_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == KILO_BYTE)		return value / base_byte;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_exa;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_zetta;
	}
	else if (from_magnitude == MEGA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		return value / base_byte;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_petta;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_exa;
	}
	else if (from_magnitude == GIGA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		return value / base_byte;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_terra;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_petta;
	}
	else if (from_magnitude == TERRA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	return value / base_byte;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_giga;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_terra;
	}
	else if (from_magnitude == PETTA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	return value / base_byte;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_giga;
	}
	else if (from_magnitude == EXA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == EXA_BYTE)		return value / base_byte;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) / bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_mega;
	}
	else if (from_magnitude == ZETTA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_zetta;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	return value / base_byte;
		else if (to_magnitude == YOTTA_BYTE)	return (value / base_byte) / bytes_in_yotta;
	}
	else if (from_magnitude == YOTTA_BIT)
	{
		if (to_magnitude == BYTE)				return (value / base_byte) * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		return (value / base_byte) * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		return (value / base_byte) * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		return (value / base_byte) * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	return (value / base_byte) * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	return (value / base_byte) * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		return (value / base_byte) * bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	return (value / base_byte) * bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	return value / base_byte;
	}
	return 0L;
}

double convert_data_magnitude_in_bits_copy(double value, BIT_MAGNITUDE from_magnitude, BIT_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BIT)
	{
		if (to_magnitude == BIT)					value = value;
		else if (to_magnitude == KILO_BIT)		return value / bits_in_kilo;
		else if (to_magnitude == MEGA_BIT)		return value / bits_in_mega;
		else if (to_magnitude == GIGA_BIT)		return value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		return value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		return value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == KILO_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		value = value;
		else if (to_magnitude == MEGA_BIT)		return value / bits_in_mega;
		else if (to_magnitude == GIGA_BIT)		return value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		return value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		return value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == MEGA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		value = value;
		else if (to_magnitude == GIGA_BIT)		return value / bits_in_giga;
		else if (to_magnitude == TERRA_BIT)		return value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		return value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == GIGA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		value = value;
		else if (to_magnitude == TERRA_BIT)		return value / bits_in_terra;
		else if (to_magnitude == PETTA_BIT)		return value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == TERRA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		return value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		value = value;
		else if (to_magnitude == PETTA_BIT)		return value / bits_in_petta;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == PETTA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		return value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		return value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		value = value;
		else if (to_magnitude == EXA_BIT)		return value / bits_in_exa;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == EXA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		return value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		return value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		return value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		value = value;
		else if (to_magnitude == ZETTA_BIT)		return value / bits_in_zetta;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == ZETTA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		return value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		return value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		return value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		return value * bits_in_zetta;
		else if (to_magnitude == ZETTA_BIT)		value = value;
		else if (to_magnitude == YOTTA_BIT)		return value / bits_in_yotta;
	}
	else if (from_magnitude == YOTTA_BIT)
	{
		if (to_magnitude == BIT)					return value * bits_in_kilo;
		else if (to_magnitude == KILO_BIT)		return value * bits_in_mega;
		else if (to_magnitude == MEGA_BIT)		return value * bits_in_giga;
		else if (to_magnitude == GIGA_BIT)		return value * bits_in_terra;
		else if (to_magnitude == TERRA_BIT)		return value * bits_in_petta;
		else if (to_magnitude == PETTA_BIT)		return value * bits_in_exa;
		else if (to_magnitude == EXA_BIT)		return value * bits_in_zetta;
		else if (to_magnitude == ZETTA_BIT)		return value * bits_in_yotta;
		else if (to_magnitude == YOTTA_BIT)		value = value;
	}
	return 0L;
}

double convert_data_magnitude_in_bytes_copy(double value, BYTE_MAGNITUDE from_magnitude, BYTE_MAGNITUDE to_magnitude)
{
	if (from_magnitude == BYTE)
	{
		if (to_magnitude == BYTE)				value = value;
		else if (to_magnitude == KILO_BYTE)		return value / bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		return value / bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == TERRA_BYTE)	return value / bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	return value / bytes_in_petta;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_exa;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_zetta;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_yotta;
	}
	else if (from_magnitude == KILO_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_kilo;
		else if (to_magnitude == KILO_BYTE)		value = value;
		else if (to_magnitude == MEGA_BYTE)		return value / bytes_in_zetta;
		else if (to_magnitude == GIGA_BYTE)		return value / bytes_in_exa;
		else if (to_magnitude == TERRA_BYTE)	return value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	return value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == MEGA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_mega;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_kilo;
		else if (to_magnitude == MEGA_BYTE)		value = value;
		else if (to_magnitude == GIGA_BYTE)		return value / bytes_in_exa;
		else if (to_magnitude == TERRA_BYTE)	return value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	return value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == GIGA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_giga;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_mega;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_kilo;
		else if (to_magnitude == GIGA_BYTE)		value = value;
		else if (to_magnitude == TERRA_BYTE)	return value / bytes_in_petta;
		else if (to_magnitude == PETTA_BYTE)	return value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == TERRA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_terra;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_giga;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_mega;
		else if (to_magnitude == GIGA_BYTE)		return value * bytes_in_kilo;
		else if (to_magnitude == TERRA_BYTE)	value = value;
		else if (to_magnitude == PETTA_BYTE)	return value / bytes_in_terra;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == PETTA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_petta;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_terra;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_giga;
		else if (to_magnitude == GIGA_BYTE)		return value * bytes_in_mega;
		else if (to_magnitude == TERRA_BYTE)	return value * bytes_in_kilo;
		else if (to_magnitude == PETTA_BYTE)	value = value;
		else if (to_magnitude == EXA_BYTE)		return value / bytes_in_giga;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_mega;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == EXA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		return value * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	return value * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	return value * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		value = value;
		else if (to_magnitude == ZETTA_BYTE)	return value / bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_mega;
	}
	else if (from_magnitude == ZETTA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_zetta;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_exa;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_petta;
		else if (to_magnitude == GIGA_BYTE)		return value * bytes_in_terra;
		else if (to_magnitude == TERRA_BYTE)	return value * bytes_in_giga;
		else if (to_magnitude == PETTA_BYTE)	return value * bytes_in_mega;
		else if (to_magnitude == EXA_BYTE)		return value * bytes_in_kilo;
		else if (to_magnitude == ZETTA_BYTE)	value = value;
		else if (to_magnitude == YOTTA_BYTE)	return value / bytes_in_kilo;
	}
	else if (from_magnitude == YOTTA_BYTE)
	{
		if (to_magnitude == BYTE)				return value * bytes_in_yotta;
		else if (to_magnitude == KILO_BYTE)		return value * bytes_in_zetta;
		else if (to_magnitude == MEGA_BYTE)		return value * bytes_in_exa;
		else if (to_magnitude == GIGA_BYTE)		return value * bytes_in_petta;
		else if (to_magnitude == TERRA_BYTE)	return value * bytes_in_terra;
		else if (to_magnitude == PETTA_BYTE)	return value * bytes_in_giga;
		else if (to_magnitude == EXA_BYTE)		return value * bytes_in_mega;
		else if (to_magnitude == ZETTA_BYTE)	return value * bytes_in_kilo;
		else if (to_magnitude == YOTTA_BYTE)	value = value;
	}
	return 0L;
}

//