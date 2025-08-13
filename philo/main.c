#include "philosophers.h"

int main(int argc, char** argv)
{
    if(parse(argc, argv) == 1)
    {
        error_handler();
        return 1;
    }
    asig_struct(argv);
    return 0;
}