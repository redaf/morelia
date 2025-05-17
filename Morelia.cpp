
#include <stdio.h>
#include "USINE-SDK-PUBLIC/sdk/UserModule.cpp"
#include "USINE-SDK-PUBLIC/sdk/UserUtils.cpp"

void log(const char *name)
{
    printf("[[MORELIA]] %s\n", name);
}

class Morelia : public UserModuleBase
{
private:
public:
    Morelia();
    ~Morelia();

    void onGetModuleInfo(TMasterInfo *pMasterInfo, TModuleInfo *pModuleInfo) override;

    void onGetParamInfo(int ParamIndex, TParamInfo *pParamInfo) override;
};

const AnsiCharPtr UserModuleBase::MODULE_NAME = "Morelia::MODULE_NAME";
const AnsiCharPtr UserModuleBase::MODULE_DESC = "Morelia::MODULE_DESC";

Morelia::Morelia()
{
    log(__func__);
}

Morelia::~Morelia()
{
    log(__func__);
}

void Morelia::onGetModuleInfo(TMasterInfo *pMasterInfo, TModuleInfo *pModuleInfo)
{
    log(__func__);
}

void Morelia::onGetParamInfo(int ParamIndex, TParamInfo *pParamInfo)
{
    log(__func__);
}

void CreateModule(void *&pModule, AnsiCharPtr optionalString, LongBool Flag, TMasterInfo *pMasterInfo, AnsiCharPtr optionalContent)
{
    log(__func__);
    pModule = new Morelia();
}

void DestroyModule(void *pModule)
{
    log(__func__);
    delete ((Morelia *)pModule);
}

void GetBrowserInfo(TModuleInfo *moduleInfo)
{
    log(__func__);
    moduleInfo->Name = UserModuleBase::MODULE_NAME;
    moduleInfo->Description = UserModuleBase::MODULE_DESC;
}
