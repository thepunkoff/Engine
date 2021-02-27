#pragma once

#ifdef NG_PLATFORM_WINDOWS
	#ifdef NG_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#else 
	#error Engine only supports windows 
#endif

#ifdef NG_DEBUG
	#define NG_ENABLE_ASSERTS
#endif

#ifdef NG_ENABLE_ASSERTS
	#define NG_ASSERT(x, ...) { if(!(x)) { NG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NG_CORE_ASSERT(x, ...) { if(!(x)) { NG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NG_ASSERT(x, ...)
	#define NG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)