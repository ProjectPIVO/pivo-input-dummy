/**
 * Copyright (C) 2016 Martin Ubl <http://pivo.kennny.cz>
 *
 * This file is part of PIVO dummy input module.
 *
 * PIVO dummy input module is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * PIVO dummy input module is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PIVO dummy input module. If not,
 * see <http://www.gnu.org/licenses/>.
 **/

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

const char* DummyInputModule::ReportName()
{
    return "Dummy input module";
}

const char* DummyInputModule::ReportVersion()
{
    return "1.0";
}

void DummyInputModule::ReportFeatures(IMF_SET &set)
{
    // nullify set
    IMF_CREATE(set);

    // add features we support
    IMF_ADD(set, IMF_FLAT_PROFILE);
    IMF_ADD(set, IMF_CALL_GRAPH);
    IMF_ADD(set, IMF_CALL_TREE);
    IMF_ADD(set, IMF_USE_SECONDS);
}

bool DummyInputModule::LoadFile(const char* file, const char* binaryFile)
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
    dst[0].functionType = FET_MISC;

    dst[1].name = "TestMethod";
    dst[1].classId = 0;
    dst[1].functionType = FET_TEXT;

    dst[2].name = "MainAppMethod";
    dst[2].classId = 1;
    dst[2].functionType = FET_TEXT;

    dst[3].name = "AnotherAppMethod";
    dst[3].classId = 1;
    dst[3].functionType = FET_TEXT;

    dst[4].name = "SomeMethod";
    dst[4].classId = 2;
    dst[4].functionType = FET_TEXT;
}

void DummyInputModule::GetFlatProfileData(std::vector<FlatProfileRecord> &dst)
{
    dst.clear();

    dst.resize(4);

    dst[0].functionId = 2;
    dst[0].timeTotal = 4;
    dst[0].callCount = 10;

    dst[1].functionId = 3;
    dst[1].timeTotal = 3;
    dst[1].callCount = 5;

    dst[2].functionId = 1;
    dst[2].timeTotal = 1;
    dst[2].callCount = 8;

    dst[3].functionId = 0;
    dst[3].timeTotal = 3.5;
    dst[3].callCount = 9;
}

void DummyInputModule::GetCallGraphMap(CallGraphMap &dst)
{
    dst.clear();

    dst[0][1] = 5;
    dst[1][2] = 4;
    dst[1][3] = 8;
    dst[0][3] = 1;
    dst[3][2] = 4;
}

void DummyInputModule::GetCallTreeMap(CallTreeMap &dst)
{
    dst.clear();

    CallTreeNode* ctn = new CallTreeNode, *ctn2 = new CallTreeNode;

    ctn2->functionId = 2;
    ctn2->parent = ctn;
    ctn2->sampleCount = 100;
    ctn2->timeTotal = 3.2;
    ctn2->timeTotalPct = 0.11;

    ctn->functionId = 1;
    ctn->parent = nullptr;
    ctn->sampleCount = 100;
    ctn->timeTotal = 5.2;
    ctn->timeTotalPct = 0.2;
    ctn->children[2] = ctn2;

    dst[1] = ctn;
}
