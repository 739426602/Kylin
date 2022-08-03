#pragma once
#include "IRuntimeModule.h"

namespace kylin 
{
	class IApplication : public IRuntimeModule 
	{
	public:
		virtual ~IApplication() {};
		virtual int Initialize() = 0;
		virtual void Finalize() = 0;

		virtual void Tick() = 0;

		virtual bool IsQuit() = 0;
	};
}