/* Common.cpp */

#include "Common.hpp"

std::unordered_set<intptr_t>									__AllocatedPointers;

std::unordered_map<std::tstring, std::vector<int>>				__IntMatrices;
std::unordered_map<std::tstring, std::vector<float>>			__FloatMatrices;
std::unordered_map<std::tstring, std::vector<std::tstring>>		__TextMatrices;

std::unordered_map<std::tstring, std::vector<int>>				__IntArrays;
std::unordered_map<std::tstring, std::vector<float>>			__FloatArrays;
std::unordered_map<std::tstring, std::vector<std::tstring>>		__TextArrays;

int		__DVMicrophoneDelay = 100;
int		__DVMicrophoneSampleSize = 10;
bool	__DVMicrophoneFreqCheck = false;
float	__DVMicrophoneVol = 0.0f;
float	__DVMicrophoneFreq = 0.0f;
float	__DVMicrophoneFreqHigh = 0.0f;
float	__DVMicrophoneFreqLow = 0.0f;

/* End */
