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

        virtual const char* ReportName();
        virtual const char* ReportVersion();
        virtual void ReportFeatures(IMF_SET &set);
        virtual bool LoadFile(const char* file, const char* binaryFile);
        virtual void GetClassTable(std::vector<ClassEntry> &dst);
        virtual void GetFunctionTable(std::vector<FunctionEntry> &dst);
        virtual void GetFlatProfileData(std::vector<FlatProfileRecord> &dst);
        virtual void GetCallGraphMap(CallGraphMap &dst);
        virtual void GetCallTreeMap(CallTreeMap &dst);

    protected:
        //

    private:
        //
};

#endif
