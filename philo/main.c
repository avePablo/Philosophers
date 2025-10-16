#include "philosophers.h"

int main(int argc, char** argv)
{
    int i = parse(argc, argv);
    if(i != 0)
    {
        error_handler(i);
        return 1;
    }
    asig_struct(argv);
    return 0;
}