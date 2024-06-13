#include "../include/mode.h"
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "Usage: " << argv[0] << " -a <algorithm> <input_file|size> <order|parameters>\n";
        return 1;
    }
    algorithmMode(argc, argv);
}