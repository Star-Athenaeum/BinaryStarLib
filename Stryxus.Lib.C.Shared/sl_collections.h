#pragma once

#ifdef KERNEL_NT
struct cmap_dll_handle
{
	char* name;
	HMODULE module_alloc;
};
#elif KERNEL_LINUX
struct cmap_dll_handle
{
	char* name;
	void* handle_alloc;
};
#endif