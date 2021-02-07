#include "stdc.h"
#include "sl_net.h"

#include "curl/curl.h"

size_t write_mem(void* ptr, size_t size, size_t nmemb, void* stream)
{
    strncat_s(stream, size, (char*)ptr, size * nmemb);
    return size * nmemb;
}

bool download(char* url, char* data)
{
    CURL* curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPPROXYTUNNEL, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_mem);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        CURLcode res = curl_easy_perform(curl);
        //if (res) Logger::log_error(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return true;
    }
    else return false;
}

bool download_file(char* url)
{
    return false;
}

//