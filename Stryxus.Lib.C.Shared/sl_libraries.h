#pragma once

#ifdef KERNEL_NT
void load_libraries(char** lib_names);
HMODULE get_library(char* lib_name);
void* get_lib_function(HMODULE lib, char* func_name);
void free_libraries();
#endif

#ifdef KERNEL_LINUX
void load_libraries(char** lib_names);
void* get_library(char* lib_name);
void* get_lib_function(void* lib, char* func_name);
void free_libraries();
#endif
