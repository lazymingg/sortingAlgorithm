#include "../include/mode.h"
#include "../include/ControllerComparisonMode.h"
#include "../include/ControllerAlgorithmMode.h"
#include "../include/HidingFeature.h"
void algorithmMode(int argc, char *argv[])
{
    // check if the user wants to run the program in algorithm mode
    if (strcmp(argv[1], "-a") == 0)
    {
        cout << "ALGORITHM MODE" << endl;
        ControllerAlgorithmMode a(argc, argv);
        a.run();
    }

    else if (strcmp(argv[1], "-c") == 0)
    {
        cout << "COMPARISON MODE" << endl;
        ControllerComparisonMode c(argc, argv);
        c.run();
    }

    else if (strcmp(argv[1], "-ming") == 0)
    {
        cout << "HIDING MODE" << endl;
        HidingMode c(argc, argv);
        c.run();
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        printParameterInfo();
        return;
    } 

    if (strcmp(argv[1], "-p") == 0)
    {
        printPrototypes();
        return;
    }
    
    return;
}