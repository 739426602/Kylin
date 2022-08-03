#include "BaseApplication.h"

int kylin::BaseApplication::Initialize() 
{
	m_bQuit = false;
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