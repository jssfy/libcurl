#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
#include <curl/curl.h>   
  
#define POSTURL "http://localhost:8888/upload"   
#define POSTFIELDS "text=anye_post"   
#define FILENAME "log/curlposttest.log"   
  
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);   
  
int main(int argc, char *argv[]) {   
    CURL *curl;   
    CURLcode res;   
    FILE *fptr;   
    struct curl_slist *http_header = NULL;   
  
    if ((fptr = fopen(FILENAME, "w")) == NULL) {   
        fprintf(stderr, "fopen file error: %s\n", FILENAME);   
        exit(1);   
    }   
  
    curl = curl_easy_init();   
    curl_easy_setopt(curl, CURLOPT_URL, POSTURL);   
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, POSTFIELDS);   
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);   
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fptr);   
    curl_easy_setopt(curl, CURLOPT_POST, 1);   
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);   
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);   
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);   
    // curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/Users/zhu/CProjects/curlposttest.cookie");   
    res = curl_easy_perform(curl);   
    curl_easy_cleanup(curl);   
}   
  
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {   
    FILE *fptr = (FILE*)userp;   
    fwrite(buffer, size, nmemb, fptr);   
}  
