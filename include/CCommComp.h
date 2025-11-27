#pragma once

#include "AComponentBase.h"
#include "CServer.h"
#include "CContainer.h"
#include "CBBBHardware.h"

class CCommComp : public AComponentBase 
{
    public:
        CCommComp (CContainer& container);
        void init() override; //void init existe déjà en virtuel dans classe héritage AComponentBase ==> override pour écrire par dessus cette def.
        void run() override;

    private:

        CContainer& container_;
        CServer server_;

};