#include "philosophers.h"

void *ft_routine (t_general *general)
{   
    pthread_mutex_lock(&general->a);
    printf("chispos\n");
    pthread_mutex_unlock(&general->a);
    
    return NULL;
}