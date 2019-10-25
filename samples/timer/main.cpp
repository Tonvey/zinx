#include "ZinxTimer.h"

int main()
{
    auto ch = new ZinxTimer();
    ZinxKernel::ZinxKernelInit();
    ZinxKernel::Zinx_Add_Channel(*ch);
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();
    return 0;
}
