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

bool DummyInputModule::LoadFile(const char* file)
{
    LogFunc(LOG_WARNING, "WARNING: You are using dummy module! No results will be supplied!");

    return true;
}
