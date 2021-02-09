#include "stryxuslib.h"

int init_stryxus_lib()
{
#ifdef KERNEL_NT
	load_libraries("libcurl-x64.dll");
#endif

#ifdef KERNEL_LINUX

#endif

}