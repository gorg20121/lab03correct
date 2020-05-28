#include "histogram.h"
#include <vector>
#include <iostream>
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if(numbers.size()==0)
    {
        return;
    }
    else{
    min=numbers[0];
    max=numbers[0];
    for (size_t i=1; i<numbers.size(); i++)
    {
        if (min>numbers[i])
        {
            min=numbers[i];
        }
        if (max<numbers[i])
        {
            max=numbers[i];
        }}}
}
vector<size_t> make_histogram(const Input& data){
    double min=0;
    double max=0;
    find_minmax(data.numbers, min, max);
    vector<size_t>bins(data.bin_count);
    for (double number: data.numbers)
        {
        size_t bin;
    bin = (number - min) / (max - min) * data.bin_count;
        if (bin==data.bin_count)
        {
            bin--;
        }
        bins[bin]++;
        }
    return bins;
}
