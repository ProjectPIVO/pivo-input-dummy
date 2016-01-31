#include "General.h"
#include "DummyInputModule.h"
#include "Log.h"

void(*LogFunc)(int, const char*, ...) = nullptr;

extern "C"
{
    DLL_EXPORT_API InputModule* CreateInputModule()
    {
        return new DummyInputModule;
    }

    DLL_EXPORT_API void RegisterLogger(void(*log)(int, const char*, ...))
    {
        LogFunc = log;
    }
}

DummyInputModule::DummyInputModule()
{
    //
}

DummyInputModule::~DummyInputModule()
{
    //
}

void DummyInputModule::ReportFeatures(IMF_SET &set)
{
    // nullify set
    IMF_CREATE(set);

    // add features we support
    IMF_ADD(set, IMF_FLAT_PROFILE);
}

bool DummyInputModule::LoadFile(const char* file)
{
    LogFunc(LOG_WARNING, "WARNING: You are using dummy module! No valid results will be supplied!");

    return true;
}

void DummyInputModule::GetClassTable(std::vector<ClassEntry> &dst)
{
    dst.clear();

    dst.resize(3);

    dst[0].name = "TestClass";
    dst[1].name = "AppClass";
    dst[2].name = "SomeClass";
}

void DummyInputModule::GetFunctionTable(std::vector<FunctionEntry> &dst)
{
    dst.clear();

    dst.resize(5);

    dst[0].name = "someClasslessFunction";
    dst[0].classId = NO_CLASS;

    dst[1].name = "TestMethod";
    dst[1].classId = 0;

    dst[2].name = "MainAppMethod";
    dst[2].classId = 1;

    dst[3].name = "AnotherAppMethod";
    dst[3].classId = 1;

    dst[4].name = "SomeMethod";
    dst[4].classId = 2;
}
