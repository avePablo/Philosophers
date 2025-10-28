#include "philosophers.h"

void *ft_routine (void *arg)
{   
	t_general *general = (t_general *)arg;
    pthread_mutex_lock(&general->a);
    printf("chispos\n");
    pthread_mutex_unlock(&general->a);
    
    return NULL;
}