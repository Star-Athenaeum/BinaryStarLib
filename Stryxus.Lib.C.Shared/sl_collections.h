#pragma once

#ifdef KERNEL_NT
struct cmap_dll_handle
{
	char* name;
	HMODULE module_alloc;
};
#endif

#ifdef KERNEL_LINUX
struct cmap_dll_handle
{
	char* name;
	void* handle_alloc;
};
#endif