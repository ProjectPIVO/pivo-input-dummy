#ifndef PIVO_DUMMY_MODULE_H
#define PIVO_DUMMY_MODULE_H

#include "InputModule.h"
#include "InputModuleFeatures.h"

extern void(*LogFunc)(int, const char*, ...);

class DummyInputModule : public InputModule
{
    public:
        DummyInputModule();
        ~DummyInputModule();

        virtual void ReportFeatures(IMF_SET &set);
        virtual bool LoadFile(const char* file, const char* binaryFile);
        virtual void GetClassTable(std::vector<ClassEntry> &dst);
        virtual void GetFunctionTable(std::vector<FunctionEntry> &dst);
        virtual void GetFlatProfileData(std::vector<FlatProfileRecord> &dst);

    protected:
        //

    private:
        //
};

#endif
