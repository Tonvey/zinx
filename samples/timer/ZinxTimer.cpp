#include "ZinxTimer.h"
#include <iostream>
using namespace std;
#ifdef __ZINX_EPOLL__
#include <sys/timerfd.h>
bool ZinxTimer::Init()
{
	//初始化的时候创建timer
	m_fd = timerfd_create(CLOCK_MONOTONIC, 0);

	itimerspec spec = { {1,0},{1,0} };
	int ret = timerfd_settime(m_fd, 0, &spec, nullptr);
	return ret == 0;
}
bool ZinxTimer::ReadFd(std::string & _input)
{
	uint64_t overtimes=0;
	int len = read(m_fd, (char*)&overtimes, sizeof(overtimes));
	if (len == sizeof(overtimes))
	{
		//string可以当做一个容器,存储二进制的数据
		_input.append((char*)&overtimes, sizeof(overtimes));
		return true;
	}
	return false;
}
#elif defined(__ZINX_KQUEUE__)
#include <sys/event.h>
#include <sys/types.h>
#include <unistd.h>
bool ZinxTimer::Init()
{
	//初始化的时候创建timer
    int ret = 0;
	return ret == 0;
}
bool ZinxTimer::ReadFd(std::string & _input)
{
    static int t = 10;
    --t;
    sleep(5);
    for(int i = 0 ; i<m_Timeouts;++i)
    {
        cout<<"HelloWorld"<<endl;
    }
    if(t<=0)
    {
        ZinxKernel::Zinx_Del_Channel(*this);
    }
	return false;
}
#endif

ZinxTimer::ZinxTimer()
	:m_fd(-1)
{
}

ZinxTimer::~ZinxTimer()
{
}

bool ZinxTimer::WriteFd(std::string & _output)
{
	return false;
}

void ZinxTimer::Fini()
{
	if (m_fd >= 0)
	{
		close(m_fd);
	}
}

int ZinxTimer::GetFd()
{
	return m_fd;
}

std::string ZinxTimer::GetChannelInfo()
{
	return "ZinxTimer";
}


AZinxHandler * ZinxTimer::GetInputNextStage(BytesMsg & _oInput)
{
	return nullptr;
}

