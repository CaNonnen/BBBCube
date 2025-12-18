#include "CCommComp.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std::chrono;

CCommComp::CCommComp(CContainer& container)
    : container_(container),
    server_()
{}

void CCommComp::init()
{
    server_.init();
    server_.waitForClient();
}

void CCommComp::run()
{
    SContent content = {};
    int i=0;
    
    while (true)
    {   
        std::cout<< "\n\nCommCycle nb: "<<i << "\n"<<std::endl;

        if(!container_.getContent(false,content))//ra l'adresse de content mais on le voit pas ici. Voir def de la fct getContent.
        {
            usleep(1000);
            continue; //retourne au début du while
        }
        //là, les données sont stockées à l'adresse de content.
        std::cout<<"Adress of content: "<<&content<<std::endl;
        server_.transmitMessage(content);
        
        i++;
        std::this_thread::sleep_for(milliseconds(20));
    }
}