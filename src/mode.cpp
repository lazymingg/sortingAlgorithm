#include "mode.h"
void algorithmMode(int argc, char* argv[])
{
    // check if the user wants to run the program in algorithm mode
    if (strcmp(argv[1], "-a") == 0)
    {
        cout << "ALGORITHM MODE" << endl;
        AlgorithmMode mode(argc, argv);
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        cout << "COMPARISON MODE" << endl;
    }
    else
    {
        cout << "Usage: " << argv[0] << " -a <algorithm> <input_file|size> <order|parameters>\n";
        return;
    }
}