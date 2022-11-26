#pragma once

#define AB_VERSION_MAJOR 1
#define AB_VERSION_MINOR 0
#define AB_VERSION_PATCH 0

#ifdef _WIN32
	#define RENDERER_EXPORT __declspec(dllexport)
	#define RENDERER_IMPORT __declspec(dllimport)
#else
	#define RENDERER_EXPORT
	#define RENDERER_IMPORT
#endif
