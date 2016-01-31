#ifndef PIVO_DUMMY_MODULE_H
#define PIVO_DUMMY_MODULE_H

#include "InputModule.h"

extern void(*LogFunc)(int, const char*, ...);

class DummyInputModule : public InputModule
{
    public:
        DummyInputModule();
        ~DummyInputModule();

        virtual bool LoadFile(const char* file);

    protected:
        //

    private:
        //
};

#endif
