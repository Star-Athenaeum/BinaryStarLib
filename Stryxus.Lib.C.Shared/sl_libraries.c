#include "stdc.h"
#include "sl_libraries.h"
#include "sl_collections.h"

#ifdef KERNEL_NT
static struct cmap_dll_handle* handles;

static bool libraries_loaded = false;

void load_libraries(char* lib_names[])
{
	if (libraries_loaded)
	{
		// print error
		return;
	}
	//if (sizeof library_names > NT_LIBRARIES_COUNT) Log error
	handles = (struct cmap_dll_handle[sizeof lib_names]){ 0 };
	for (int i = 0; i < sizeof lib_names; i++)
	{
		HMODULE m = LoadLibrary(lib_names[i]);
		//if (m == NULL) Logger::log_last_error();
		/*else*/
		handles[i].name = "";
		handles[i].module_alloc = m;
	}
	libraries_loaded = true;
}

HMODULE get_library(char* lib_name)
{
	for (int i = 0; i < sizeof handles; i++)
	{
		if (handles[i].name == lib_name) return handles[i].module_alloc;
		// else report error
	}
}

void* get_lib_function(HMODULE lib, char* func_name)
{
	return (void*)GetProcAddress(lib, func_name);
	// needs error checking
}

void free_libraries()
{
	for (int i = 0; i < sizeof handles; i++) FreeLibrary(handles[i].module_alloc);
}
#endif

#ifdef KERNEL_LINUX
static struct cmap_dll_handle* handles;

static bool libraries_loaded = false;

void load_libraries(char* lib_names[])
{
	if (libraries_loaded)
	{
		// print error
		return;
	}
	//if (sizeof library_names > NT_LIBRARIES_COUNT) Log error
	handles = (struct cmap_dll_handle[sizeof lib_names]){ 0 };
	for (int i = 0; i < sizeof lib_names; i++)
	{
		void* m = dlopen(lib_names[i], RTLD_LAZY);
		//if (m == NULL) Logger::log_last_error(dlerror());
		/*else*/
		handles[i].name = "";
		handles[i].handle_alloc = m;
	}
	libraries_loaded = true;
}

void* get_library(char* lib_name)
{
	for (int i = 0; i < sizeof handles; i++)
	{
		if (handles[i].name == lib_name) return handles[i].handle_alloc;
		// else report error
	}
}

void* get_lib_function(void* lib, char* func_name)
{
	return dlsym(lib, func_name);
	//if (dlerror() != NULL)  dlerror() print error
}

void free_libraries()
{
	for (int i = 0; i < sizeof handles; i++) dlclose(handles[i].handle_alloc);
}
#endif
