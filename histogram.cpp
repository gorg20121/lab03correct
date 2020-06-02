#include "histogram.h"
#include <vector>
#include <windows.h>
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
 string make_info_text() {
    stringstream buffer;
    DWORD WINAPI GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD mask2 = 0x000000ff;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask2;
    DWORD version_minor = version >>8;
    if ((version & 0x40000000) == 0) {


         DWORD build = platform;

            buffer << "Windows v" << version_major << "." << version_minor << "(build " << build << ")\n";
    }

    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computer_name);
    GetComputerNameA(computer_name, &size);
    buffer << "Computer name: " << computer_name << "\n";

    return buffer.str();
}
