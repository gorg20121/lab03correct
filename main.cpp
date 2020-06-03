#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "histogram.h"
#include "svg.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>



using namespace std;



vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}


Input read_input(istream& in, bool prompt,int argc, char* argv[],bool flag_control)
{
    Input data;




    size_t number_count;
    if (prompt)
    {
        cerr << "Enter number count: ";
        in >> number_count;
        cerr << "Enter numbers: ";
        data.numbers = input_numbers(in, number_count);
        cerr << "Enter bin count : ";
        in >> data.bin_count;
    }
    else
    {
        if (flag_control){

                srand(time(0));
                int number_count=0;
                int random;

                for (int i=0; i<argc; i++)
                    if (string(argv[i])=="-generate"){
                        number_count=atoi(argv[i+1] );}


                vector<double>random_numbers(number_count);
                for (int i=0; i<number_count; i++){
                    random=0;
                    for (int j=0; j<12; j++)
                        random+=rand();
                    random_numbers[i]=random;}
                data.numbers=random_numbers;
                in >> data.bin_count;
                }
            else{
        in >> number_count;
        data.numbers = input_numbers(in, number_count);
        in >> data.bin_count;}

    }
    return data;
}
size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx)
{
    const size_t data_size = item_size * item_count;
    const char* new_items = reinterpret_cast<const char*>(items);
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(new_items, data_size);
    return data_size;
}




Input download(const string& address, int  argc, char* argv[], bool flag_control)
{
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);


    CURL *curl = curl_easy_init();
    if(curl)
    {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL,address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK )
        {
            cerr<<curl_easy_strerror(res);
            exit(1);
        }
        curl_easy_cleanup(curl);

    }
    return read_input(buffer, false, argc,  argv,flag_control);
}
int main(int argc, char* argv[])
{
    Input input;
     if (argc > 1){
        bool flag=false;
        bool flag_fault=false;
        int link;
        for (int i=0; i<argc; i++){
            if (string(argv[i])=="-generate"){
                flag=true;
                if (i==(argc-1)){
                    cerr<<"Please set number count after <-generate>";
                    flag_fault=true;}
                else if (string(argv[i+1]).size()>12){
                    cerr<<"Please set number count after <-generate>";
                    flag_fault=true;}}

            if (string(argv[i]).size()>10)
                link=i;}
        if (!flag && !flag_fault)
            input = download(argv[1],argc,  argv, false);
        if (!flag_fault && flag)
            input =download (argv[link],argc,  argv, true);}
    else
    input = read_input(cin, true, argc,  argv, true);

                const auto bins = make_histogram(input);
    show_histogram_svg(bins);
    return 0;

}
