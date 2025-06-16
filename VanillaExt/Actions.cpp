/* Actions.cpp */

#include "Common.hpp"


void Extension::ActionExample(int ExampleParameter)
{
}

void Extension::SecondActionExample()
{
}

// 2
void Extension::PtrFreeMemory(intptr_t _Ptr)
{
	if (_Ptr == 0)
		return;

	if (__AllocatedPointers.count(_Ptr) == 0)
		return;

	__AllocatedPointers.erase(_Ptr);
	free(reinterpret_cast<void*>(_Ptr));
}

// 3
void Extension::PtrWriteInt(intptr_t _Ptr, int _Value)
{
	if (__AllocatedPointers.count(_Ptr) == 0)
		return;

	*reinterpret_cast<int*>(_Ptr) = _Value;
}

// 4 
void Extension::PtrCopyMemory(intptr_t _Source, intptr_t _Destination, int _Size)
{
	if (__AllocatedPointers.count(_Source) == 0 || __AllocatedPointers.count(_Destination) == 0)
		return;

	memcpy(reinterpret_cast<void*>(_Destination), reinterpret_cast<void*>(_Source), _Size);
}

// 5
void Extension::PtrWriteFloat(intptr_t _Ptr, float _Value)
{
	if (__AllocatedPointers.count(_Ptr) == 0)
		return;

	*reinterpret_cast<float*>(_Ptr) = _Value;
}

// 14
void Extension::MtxCreateInt(const TCHAR* _Name, const TCHAR* _Type)
{
	std::tstring _TName(_Name);
	std::tstring _TType(_Type);
	int _Size = 1;

	if (_TType == _T("int2")) _Size = 2;
	else if (_TType == _T("int3")) _Size = 3;
	else if (_TType == _T("int4")) _Size = 4;

	__IntMatrices[_TName] = std::vector<int>(_Size, 0);
}

// 15
void Extension::MtxDeleteInt(const TCHAR* _Name)	{ __IntMatrices.erase(std::tstring(_Name)); }

// 16
void Extension::MtxSetInt(const TCHAR* _Name, const TCHAR* _Variable, int _Value)
{
	auto& _Matrix = __IntMatrices[std::tstring(_Name)];
	std::tstring _Var(_Variable);

	if (_Var == _T("X")) _Matrix[0] = _Value;
	else if (_Var == _T("Y") && _Matrix.size() > 1) _Matrix[1] = _Value;
	else if (_Var == _T("Z") && _Matrix.size() > 2) _Matrix[2] = _Value;
	else if (_Var == _T("W") && _Matrix.size() > 3) _Matrix[3] = _Value;
}

// 6/7/8/9 //
void Extension::MtxOverrideInt1(const TCHAR* _Name, int x)									{	std::tstring _Key(_Name);	__IntMatrices[_Key] = { x };			}
void Extension::MtxOverrideInt2(const TCHAR* _Name, int x, int y)							{	std::tstring _Key(_Name);	__IntMatrices[_Key] = { x,y };			}
void Extension::MtxOverrideInt3(const TCHAR* _Name, int x, int y, int z)					{	std::tstring _Key(_Name);	__IntMatrices[_Key] = { x, y, z };		}
void Extension::MtxOverrideInt4(const TCHAR* _Name, int x, int y, int z, int w)				{	std::tstring _Key(_Name);	__IntMatrices[_Key] = { x, y, z, w };	}

/* ####################### */

// 17
void Extension::MtxCreateFloat(const TCHAR* _Name, const TCHAR* _Type)
{
	std::tstring _TName(_Name);
	std::tstring _TType(_Type);
	int _Size = 1;

	if (_TType == _T("float2")) _Size = 2;
	else if (_TType == _T("float3")) _Size = 3;
	else if (_TType == _T("float4")) _Size = 4;

	__FloatMatrices[_TName] = std::vector<float>(_Size, 0.0f);
}

// 18
void Extension::MtxDeleteFloat(const TCHAR* _Name) { __FloatMatrices.erase(std::tstring(_Name)); }

// 19
void Extension::MtxSetFloat(const TCHAR* _Name, const TCHAR* _Variable, float _Value)
{
	auto& _Matrix = __FloatMatrices[std::tstring(_Name)];
	std::tstring _Var(_Variable);

	if (_Var == _T("X")) _Matrix[0] = _Value;
	else if (_Var == _T("Y") && _Matrix.size() > 1) _Matrix[1] = _Value;
	else if (_Var == _T("Z") && _Matrix.size() > 2) _Matrix[2] = _Value;
	else if (_Var == _T("W") && _Matrix.size() > 3) _Matrix[3] = _Value;
}

// 10/11/12/13 //
void Extension::MtxOverrideFloat1(const TCHAR* _Name, float x)								{	std::tstring _Key(_Name);	__FloatMatrices[_Key] = { x };			}
void Extension::MtxOverrideFloat2(const TCHAR* _Name, float x, float y)						{	std::tstring _Key(_Name);	__FloatMatrices[_Key] = { x,y };		}
void Extension::MtxOverrideFloat3(const TCHAR* _Name, float x, float y, float z)			{	std::tstring _Key(_Name);	__FloatMatrices[_Key] = { x, y, z };	}
void Extension::MtxOverrideFloat4(const TCHAR* _Name, float x, float y, float z, float w)	{	std::tstring _Key(_Name);	__FloatMatrices[_Key] = { x, y, z, w };	}

/* ####################### */

// 20
void Extension::MtxCreateText(const TCHAR* _Name, const TCHAR* _Type)
{
	std::tstring _TName(_Name);
	std::tstring _TType(_Type);
	int _Size = 1;

	if (_TType == _T("text2")) _Size = 2;
	else if (_TType == _T("text3")) _Size = 3;
	else if (_TType == _T("text4")) _Size = 4;

	__TextMatrices[_Name] = std::vector<std::tstring>(_Size, _T(""));
}

// 21
void Extension::MtxDeleteText(const TCHAR* _Name)	{	__TextMatrices.erase(std::tstring(_Name));	}

// 22
void Extension::MtxSetText(const TCHAR* _Name, const TCHAR* _Variable, const TCHAR* _Value)
{
	auto _IT = __TextMatrices.find(std::tstring(_Name));
	if (_IT == __TextMatrices.end()) return;

	auto& _Matrix = _IT->second;
	std::tstring _Var(_Variable);
	std::tstring _Val(_Value);

	if (_Var == _T("X")) _Matrix[0] = _Val;
	else if (_Var == _T("Y") && _Matrix.size() > 1) _Matrix[1] = _Val;
	else if (_Var == _T("Z") && _Matrix.size() > 2) _Matrix[2] = _Val;
	else if (_Var == _T("W") && _Matrix.size() > 3) _Matrix[3] = _Val;
}

// 23/24/25/26 //
void Extension::MtxOverrideText1(const TCHAR* _Name, const TCHAR* x)													{	__TextMatrices[std::tstring(_Name)] = { std::tstring(x) };														}
void Extension::MtxOverrideText2(const TCHAR* _Name, const TCHAR* x, const TCHAR* y)									{	__TextMatrices[std::tstring(_Name)] = { std::tstring(x), std::tstring(y) };										}
void Extension::MtxOverrideText3(const TCHAR* _Name, const TCHAR* x, const TCHAR* y, const TCHAR* z)					{	__TextMatrices[std::tstring(_Name)] = { std::tstring(x), std::tstring(y), std::tstring(z) };					}
void Extension::MtxOverrideText4(const TCHAR* _Name, const TCHAR* x, const TCHAR* y, const TCHAR* z, const TCHAR* w)	{	__TextMatrices[std::tstring(_Name)] = { std::tstring(x), std::tstring(y), std::tstring(z), std::tstring(w) };	}

/* ####################### */

// 27
void Extension::ArrCreateInt(const TCHAR* _Name, int _Length)
{
	if (_Length < 0) return;
	__IntArrays[std::tstring(_Name)] = std::vector<int>(_Length, 0);
}

// 28
void Extension::ArrDeleteInt(const TCHAR* _Name)
{
	__IntArrays.erase(std::tstring(_Name));
}

// 29
void Extension::ArrSetInt(const TCHAR* _Name, int _Index, int _Value)
{
	auto _IT = __IntArrays.find(std::tstring(_Name));
	if (_IT == __IntArrays.end()) return;

	auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size()) return;
	_Arr[_Index] = _Value;
}

// 30
void Extension::ArrCreateFloat(const TCHAR* _Name, int _Length)
{
	if (_Length < 0) return;
	__FloatArrays[std::tstring(_Name)] = std::vector<float>(_Length, 0.0f);
}

// 31
void Extension::ArrDeleteFloat(const TCHAR* _Name)
{
	__FloatArrays.erase(std::tstring(_Name));
}

// 32
void Extension::ArrSetFloat(const TCHAR* _Name, int _Index, float _Value)
{
	auto _IT = __FloatArrays.find(std::tstring(_Name));
	if (_IT == __FloatArrays.end()) return;

	auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size()) return;
	_Arr[_Index] = _Value;
}

// 33
void Extension::ArrCreateText(const TCHAR* _Name, int _Length)
{
	if (_Length < 0) return;
	__TextArrays[std::tstring(_Name)] = std::vector<std::tstring>(_Length, _T(""));
}

// 34
void Extension::ArrDeleteText(const TCHAR* _Name)
{
	__TextArrays.erase(std::tstring(_Name));
}

// 35
void Extension::ArrSetText(const TCHAR* _Name, int _Index, const TCHAR* _Value)
{
	auto _IT = __TextArrays.find(std::tstring(_Name));
	if (_IT == __TextArrays.end()) return;

	auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size()) return;
	_Arr[_Index] = std::tstring(_Value);
}

/* ####################### */

IMMDeviceEnumerator* pEnumerator = NULL;
IMMDevice* pDevice = NULL;
IAudioClient* pAudioClient = NULL;
IAudioMeterInformation* pMeterInfo = NULL;
bool									__MicrophoneActive = false;
std::chrono::steady_clock::time_point	__LastTime;

std::vector<float> __Samples;
int __SampleIndex = 0;

// 36
void Extension::DVMicrophoneCapture()
{
	float _Volume = -100.0f;
	HRESULT hr;

	if (!__MicrophoneActive)
	{
		/* com failed to initialize err: -201 */
		hr = CoInitialize(NULL);
		if (FAILED(hr))	{	_Volume = -201.0f;	return;		}

		/* failed to create mmdeviceenumerator instance err: -202 */
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
		if (FAILED(hr))	{	CoUninitialize();
							_Volume = -202.0f;	return;		}

		/* failed to get default microphone err: -203 */
		hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &pDevice);
		if (FAILED(hr))	{	pEnumerator->Release();
							CoUninitialize();
							_Volume = -203.0f;	return;		}

		/* failed to activate iaudioclient err: -204 */
		hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
		if (FAILED(hr))	{	pDevice->Release();
							pEnumerator->Release();
							CoUninitialize();
							_Volume = -204.0f;	return;		}

		/* failed to get audio mixing format: -205 */
		WAVEFORMATEX* pwfx = NULL;
		hr = pAudioClient->GetMixFormat(&pwfx);
		if (FAILED(hr))	{	pAudioClient->Release();
							pDevice->Release();
							pEnumerator->Release();
							CoUninitialize();
							_Volume = -205.0f;	return;		}

		/* failed to initialize iaudioclient err: -206 */
		hr = pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, 0, 10000000, 0, pwfx, NULL);
		if (FAILED(hr))	{	CoTaskMemFree(pwfx);
							pAudioClient->Release();
							pDevice->Release();
							pEnumerator->Release();
							CoUninitialize();
							_Volume = -206.0f;	return;		}

		/* failed to launch audio client err: -207 */
		hr = pAudioClient->Start();
		if (FAILED(hr))	{	pAudioClient->Release();
							pDevice->Release();
							pEnumerator->Release();
							CoUninitialize();
							_Volume = -207.0f;	return;		}

		/* failed to activate iaudiometerinformation for volume reading err: -208 */
		hr = pDevice->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL, NULL, (void**)&pMeterInfo);
		if (FAILED(hr))	{	pAudioClient->Stop();
							pAudioClient->Release();
							pDevice->Release();
							pEnumerator->Release();
							CoUninitialize();
							_Volume = -208.0f;	return;		}

		__MicrophoneActive = true;
		__LastTime = std::chrono::steady_clock::now();

		__Samples.resize(__DVMicrophoneSampleSize);
	}

	auto _CurrentTime = std::chrono::steady_clock::now();
	auto _ElapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(_CurrentTime - __LastTime).count();

	if (_ElapsedTime >= __DVMicrophoneDelay)
	{
		/* failed to retrieve peak value from microphone err: -209 */
		hr = pMeterInfo->GetPeakValue(&_Volume);
		if (FAILED(hr))	{	_Volume = -209.0f;	}

		__DVMicrophoneVol = _Volume;
		if (__SampleIndex >= __Samples.size()) {	__SampleIndex = 0;	}

		__Samples[__SampleIndex++] = _Volume;

		if (__SampleIndex >= __DVMicrophoneSampleSize && __DVMicrophoneSampleSize >= 1)
		{
			__SampleIndex = 0;

			if (__DVMicrophoneFreqCheck)
			{
				float _AverageVolune = 0.0f;
				__DVMicrophoneFreqHigh = __Samples[0];
				__DVMicrophoneFreqLow = __Samples[0];
				for (int i = 0; i < __DVMicrophoneSampleSize; ++i)
				{
					_AverageVolune += __Samples[i];
					__DVMicrophoneFreqHigh = fmax(__Samples[i], __DVMicrophoneFreqHigh);
					__DVMicrophoneFreqLow = fmin(__Samples[i], __DVMicrophoneFreqLow);
				}
				_AverageVolune /= __DVMicrophoneSampleSize;

				float _FrequencyLevelY = abs(_AverageVolune);
				__DVMicrophoneFreq = _FrequencyLevelY;
			}
		}

		__LastTime = _CurrentTime;
	}
}

// 37
void Extension::DVMicrophoneSetDelay(int x)
{
	__DVMicrophoneDelay = fmax(x, 0);
}

// 38
void Extension::DVMicrophoneSetSampleSize(int x)
{
	__DVMicrophoneSampleSize = fmax(x, 1);
	__Samples.resize(__DVMicrophoneSampleSize);
	__SampleIndex = 0;
}


/* End */
