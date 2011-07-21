#pragma once

#ifdef _WIN32
	#ifdef FWAPI_EXPORT_SYMBOLS
		#define FWAPI __declspec( dllexport )
	#else
		#define FWAPI __declspec( dllimport )
	#endif
#else
	#define FWAPI
#endif

#define APIENTRY __stdcall