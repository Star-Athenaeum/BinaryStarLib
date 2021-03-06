#include "stdc.h"
#include "sl_json.h"

bool json_entry_exists(const cJSON* json, const char* key)
{
    cJSON* el = NULL;
    char* it_key = NULL;

    cJSON_ArrayForEach(el, json)
    {
        it_key = el->string;
        if (it_key != NULL && it_key == key) return true;
    }
    return false;
}