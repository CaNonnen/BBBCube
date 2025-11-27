#include "CCommComp.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

CCommComp::CCommComp(CContainer& container)
    : container_(container),
    server_()
{}

void CCommComp::init()
{
    server_.init();
}

void CCommComp::run()
{
    SContent content;
    int ttowait = 0;
    int i=0;
    
    while (true)
    {   
        std::this_thread::sleep_for(milliseconds(ttowait));
        std::cout<< "\n\nCommCycle nb: "<<i<<"\ntime gap: " << ttowait << "\n"<<std::endl;
        auto tstart = steady_clock::now();

        container_.getContent(false, content); //la fct utilisera l'adresse de content mais on le voit pas ici. Voir def de la fct getContent.
        //là, les données sont stockées à l'adresse de content.
        bool is_transmetted = server_.transmitMessage(content);
        std::cout << "Fct appliquee ? "<<is_transmetted <<std::endl;

        auto tend = steady_clock::now();
        ttowait = 20 - duration_cast<milliseconds>(tend - tstart).count();
        i++;
    }
}