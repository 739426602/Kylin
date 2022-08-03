#include <stdio.h>
#include "IApplication.h"

using namespace kylin;

namespace kylin 
{
	extern IApplication* g_pApp;
}

int main(int argc, char** argv) 
{
	int state;
	if ((state = g_pApp->Initialize()) != 0) 
	{
		printf("App Initialize failed");
		return state;
	}

	while (!g_pApp->IsQuit())
	{
		g_pApp->Tick();
	}

	g_pApp->Finalize();
	return 0;
}