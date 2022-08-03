#pragma once

namespace kylin 
{
	class IRuntimeModule 
	{
	public:
		virtual ~IRuntimeModule() {};
		virtual int Initialize() = 0;
		virtual void Finalize() = 0;

		virtual void Tick() = 0;
	};
}