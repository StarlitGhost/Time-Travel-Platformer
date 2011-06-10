#pragma once

#include <windows.h>

namespace FlatWorld
{
	class CTimer
	{
	public:
		CTimer(void);
		CTimer(float timeCount);
		~CTimer(void);

		void Update();
		bool Ready();
		float DT();

	private:
		void Init(float timeCount);

		//************ Timing variables ************
		LONGLONG timeNow;//Current time
		LONGLONG timeNext;//Time of the next update
		LONGLONG timeLast;//Time of last update
		double timeScale;
		DWORD timeCount;
		BOOL perfCount;
		LONGLONG perfFrequ;
		//******** end of timing variables *********
	};
}
