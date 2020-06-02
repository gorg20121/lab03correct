#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <cstdio>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count){
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t>count(bin_count,0);
    for (double x: numbers){
        size_t bin_index=(size_t)(x-min)*(bin_count)/(max-min);
        if (bin_index==bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;}
    return count;
}

int main()
{
     DWORD WINAPI GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD mask2 = 0x000000ff;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask2;
    DWORD version_minor = version >>8;
    if ((version & 0x80000000) == 0) {
            printf("true\n");
        }

        DWORD build = platform;

        printf("Windows v%d.%d (build %d)", version_major, version_minor, build);

    return 0;

    size_t number_count;
    cerr<< "enter number count";
    cin>>number_count;
    const auto numbers=input_numbers(number_count);

    size_t bin_count;
    cerr<< "enter bin count";
    cin>>bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins);
    return 0;

}
