#pragma once

#define AB_VERSION_MAJOR 1
#define AB_VERSION_MINOR 0
#define AB_VERSION_PATCH 0

#ifdef _WIN32
	#define AB_EXPORT __declspec(dllexport)
	#define AB_IMPORT __declspec(dllimport)
#else
	#define AB_EXPORT
	#define AB_IMPORT
#endif
