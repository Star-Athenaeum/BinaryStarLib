#include "stdc.h"
#include "stryxuslib.h"

int init_stryxus_lib()
{
#ifdef KERNEL_NT
	char* libraries[1] = { "libcurl-x64.dll" };
	load_libraries(libraries);
#endif

#ifdef KERNEL_LINUX

#endif

}