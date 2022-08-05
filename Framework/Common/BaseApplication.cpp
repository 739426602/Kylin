#include "BaseApplication.h"

bool kylin::BaseApplication::m_bQuit = false;

int kylin::BaseApplication::Initialize() 
{
	return 0;
}

void kylin::BaseApplication::Tick() 
{
}

void kylin::BaseApplication::Finalize() 
{
}

bool kylin::BaseApplication::IsQuit() 
{
	return m_bQuit;
}