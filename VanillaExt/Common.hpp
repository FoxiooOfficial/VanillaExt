/* Common.hpp */

#pragma once

	/* Do not move XXXEXT after #include of DarkEdif.h! */
	// #define TGFEXT	// TGF2, Fusion 2.x Std, Fusion 2.x Dev
	// #define PROEXT	// Fusion 2.x Dev only
	#define MMFEXT		// Fusion 2.x, Fusion 2.x Dev

#include "DarkEdif.hpp"

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files
struct EDITDATA
{
	NO_DEFAULT_CTORS_OR_DTORS(EDITDATA);
	// Header - required
	extHeader		eHeader;

	// Object's data

//	short			swidth;
//	short			sheight;

	// Keep DarkEdif variables as last. Undefined behaviour otherwise.
	DarkEdif::Properties Props;
};

class Extension;

#include "Extension.hpp"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <tchar.h>
#include <limits>
#include <cmath>

#include <audioclient.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <chrono>
#include <windows.h>

extern std::unordered_set<intptr_t>									__AllocatedPointers;

extern std::unordered_map<std::tstring, std::vector<int>>			__IntMatrices;
extern std::unordered_map<std::tstring, std::vector<float>>			__FloatMatrices;
extern std::unordered_map<std::tstring, std::vector<std::tstring>>	__TextMatrices;

extern std::unordered_map<std::tstring, std::vector<int>>			__IntArrays;
extern std::unordered_map<std::tstring, std::vector<float>>			__FloatArrays;
extern std::unordered_map<std::tstring, std::vector<std::tstring>>	__TextArrays;

extern int		__DVMicrophoneDelay;
extern int		__DVMicrophoneSampleSize;
extern bool		__DVMicrophoneFreqCheck;
extern float	__DVMicrophoneVol;
extern float	__DVMicrophoneFreq;
extern float	__DVMicrophoneFreqHigh;
extern float	__DVMicrophoneFreqLow;

/* End */
