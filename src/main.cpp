#include "../include/mode.h"
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "invalic arguments\n";
        cout << "use main -h for help\n";
        cout << "use main -p for prototypes\n";
        return 1;
    }
    algorithmMode(argc, argv);
}