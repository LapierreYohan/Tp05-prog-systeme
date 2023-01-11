#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <thread>

#include "Restaurant.h"

Restaurant monResto(10);

void actionClient(int nb)
{
    int id = nb;    
    std::cout<<"thread :"<<id<<", j'arrive devant le resto"<<std::endl;
    monResto.arriver();
    std::cout<<"thread :"<<id<<", je rentre et je mange"<<std::endl;
    sleep(20);
    std::cout<<"thread :"<<id<<", fini, je pars"<<std::endl;
    monResto.partir();
}

int main (void)
{
    int nb = 0;
    // Creation infine de clients a frequence aleatoire
    srand(time(NULL));
    while(1)
    {
        sleep(1);
        int temp =  rand()%11;
        if(temp <= 7)
        {
            std::thread monClient(actionClient,++nb);
            monClient.detach();
        }
    }
    return EXIT_SUCCESS;
}
