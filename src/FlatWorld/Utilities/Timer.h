#pragma once

#define _WINSOCKAPI_
#include <windows.h>

namespace FlatWorld
{
	class Timer
	{
	public:
		Timer(void);
		Timer(float timeCount);
		~Timer(void);

		void Update();
		bool Ready();
		bool ReadyAndReinit();
		float DT();

		void TimeScale(float timeScale);
		float TimeScale() { return _funScale; }

	private:
		void Init(float timeCount);

		//************ Timing variables ************
		LONGLONG _currentTime;//Current time
		LONGLONG _readyTime;//Time of the next update
		LONGLONG _dt;//Time of last update
		double _timeScale;
		DWORD _timeCount;
		BOOL _perfCount;
		LONGLONG _perfFrequ;
		//******** end of timing variables *********

		//************* Fun variables **************
		float _funScale;
		//******** end of fun variables ************
	};
}