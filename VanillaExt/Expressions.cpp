/* Expressions.cpp */

#include "Common.hpp"

int Extension::Add(int First, int Second)
{
	return First + Second;
}

const TCHAR * Extension::HelloWorld()
{
	return Runtime.CopyString(_T("Hello world!"));
}

// 2
intptr_t Extension::PtrAllocateMemory(int _Bytes)
{
	if (_Bytes <= 0) return 0;

	void* _Mem = malloc(_Bytes);
	if (!_Mem) return 0;

	intptr_t _Ptr = reinterpret_cast<intptr_t>(_Mem);
	__AllocatedPointers.insert(_Ptr);
	return _Ptr;
}

// 3
int Extension::PtrReadInt(intptr_t _Ptr)
{
	if (__AllocatedPointers.count(_Ptr) == 0) return 0;

	return *reinterpret_cast<int*>(_Ptr);
}

// 4
intptr_t Extension::PtrReallocMemory(intptr_t _Ptr, int _Size)
{
	if (_Size <= 0) return 0;

	void* _Mem = realloc(reinterpret_cast<void*>(_Ptr), _Size);
	if (!_Mem) return 0;

	intptr_t _NEWPtr = reinterpret_cast<intptr_t>(_Mem);
	__AllocatedPointers.erase(_Ptr);
	__AllocatedPointers.insert(_NEWPtr);
	return _NEWPtr;
}

// 5
float Extension::PtrReadFloat(intptr_t _Ptr)
{
	if (__AllocatedPointers.count(_Ptr) == 0) return 0.0f;

	return *reinterpret_cast<float*>(_Ptr);
}

// 6
int Extension::MtxReadInt(const TCHAR* _Name, const TCHAR* _Variable)
{
	auto _IT = __IntMatrices.find(std::tstring(_Name));
	if (_IT == __IntMatrices.end())
		return 0;

	const std::vector<int>& _Matrix = _IT->second;
	std::tstring _Var(_Variable);

	if (_Var == _T("X")) return _Matrix[0];
	if (_Var == _T("Y") && _Matrix.size() > 1) return _Matrix[1];
	if (_Var == _T("Z") && _Matrix.size() > 2) return _Matrix[2];
	if (_Var == _T("W") && _Matrix.size() > 3) return _Matrix[3];
	return 0;
}

// 7
float Extension::MtxReadFloat(const TCHAR* _Name, const TCHAR* _Variable)
{
	auto _IT = __FloatMatrices.find(std::tstring(_Name));
	if (_IT == __FloatMatrices.end())
		return 0;

	const std::vector<float>& _Matrix = _IT->second;
	std::tstring _Var(_Variable);

	if (_Var == _T("X")) return _Matrix[0];
	if (_Var == _T("Y") && _Matrix.size() > 1) return _Matrix[1];
	if (_Var == _T("Z") && _Matrix.size() > 2) return _Matrix[2];
	if (_Var == _T("W") && _Matrix.size() > 3) return _Matrix[3];
	return 0;
}

/* ############################################################################# */

/* 8 */  int Extension::BitAND(int _A, int _B)				{ return _A & _B; }
/* 9 */  int Extension::BitOR(int _A, int _B)				{ return _A | _B; }
/* 10 */ int Extension::BitXOR(int _A, int _B)				{ return _A ^ _B; }
/* 11 */ int Extension::BitNOT(int _A)						{ return ~_A; }
/* 12 */ int Extension::BitNAND(int _A, int _B)				{ return ~(_A & _B); }
/* 13 */ int Extension::BitNOR(int _A, int _B)				{ return ~(_A | _B); }
/* 14 */ int Extension::BitXNOR(int _A, int _B)				{ return ~(_A ^ _B); }

/* 35 */ int Extension::BitIMPLY(int _A, int _B)			{ return (~_A) | _B; }
/* 36 */ int Extension::BitNIMPLY(int _A, int _B)			{ return _A & (~_B); }
/* 37 */ int Extension::BitCONVERSE(int _A, int _B)			{ return (~_B) | _A; }
/* 38 */ int Extension::BitNCONVERSE(int _A, int _B)		{ return _B & (~_A); }

/* 15 */ int Extension::BitShiftLeft(int _A, int _Shift)	{ return _A << _Shift; }
/* 16 */ int Extension::BitShiftRight(int _A, int _Shift)	{ return _A >> _Shift; }

// 17
int Extension::BitRotateLeft(int _A, int _Shift)
{
	unsigned int _Bits = sizeof(int) * 8;
		_Shift = _Shift % _Bits;

	return (_A << _Shift) | ((unsigned int)_A >> (_Bits - _Shift));
}

// 18
int Extension::BitRotateRight(int _A, int _Shift)
{
	unsigned int _Bits = sizeof(int) * 8;
	_Shift = _Shift % _Bits;

	return ((unsigned int)_A >> _Shift) | (_A << (_Bits - _Shift));
}

/* ############################################################################# */

/* 19 */ float Extension::Iff(int _Condition, float _ValueTrue)							{ return _Condition ? _ValueTrue : 0; }
/* 20 */ float Extension::IfElse(int _Condition, float _ValueTrue, float _ValueFalse)	{ return _Condition ? _ValueTrue : _ValueFalse; }

/* 21 */ int Extension::ConditionEqual(float _A, float _B)				{ return _A == _B;	}
/* 22 */ int Extension::ConditionNotEqual(float _A, float _B)			{ return _A != _B;	}
/* 23 */ int Extension::ConditionLess(float _A, float _B)				{ return _A <  _B;	}
/* 24 */ int Extension::ConditionLessEqual(float _A, float _B)			{ return _A <= _B;	}
/* 25 */ int Extension::ConditionGreater(float _A, float _B)			{ return _A >  _B;	}
/* 26 */ int Extension::ConditionGreaterEqual(float _A, float _B)		{ return _A >= _B;	}

/* 56 */ int Extension::ConditionV(float _A, const TCHAR* _Condition, float _B)
{
	std::tstring _Con(_Condition);

	if (_Con == _T("=="))		{ return _A == _B;	}
	else if (_Con == _T("!="))	{ return _A != _B;	}
	else if (_Con == _T("<"))	{ return _A <  _B;	}
	else if (_Con == _T("<="))	{ return _A <= _B;	}
	else if (_Con == _T(">"))	{ return _A >  _B;	}
	else if (_Con == _T(">="))	{ return _A >= _B;	}

	else						{ return 0;			}
}

/* ---------------------------------------------------------------------------- */

/* 27 */ const TCHAR* Extension::IfText(int _Condition, const TCHAR* _ValueTrue)										{ return _Condition ? Runtime.CopyString(_ValueTrue) : Runtime.CopyString(_T("")); }
/* 28 */ const TCHAR* Extension::IfElseText(int _Condition, const TCHAR* _ValueTrue, const TCHAR* _ValueFalse)			{ return Runtime.CopyString(_Condition ? _ValueTrue : _ValueFalse); }

/* 29 */ int Extension::ConditionEqualText(const TCHAR* _A, const TCHAR* _B)			{ return _tcscmp(_A, _B) == 0; }
/* 30 */ int Extension::ConditionNotEqualText(const TCHAR* _A, const TCHAR* _B)			{ return _tcscmp(_A, _B) != 0; }

/* 57 */ int Extension::ConditionText(const TCHAR* _A, const TCHAR* _Condition, const TCHAR* _B)
{
	std::tstring _Con(_Condition);

	if (_Con == _T("=="))		{ return _tcscmp(_A, _B) == 0; }
	else if (_Con == _T("!="))	{ return _tcscmp(_A, _B) != 0; }

	else { return 0; }
}

/* #############################################################################  */

// 31
const TCHAR* Extension::MtxReadText(const TCHAR* _Name, const TCHAR* _Variable)
{
	auto _IT = __TextMatrices.find(std::tstring(_Name));
	if (_IT == __TextMatrices.end())	return Runtime.CopyString(_T(""));

	const auto& _Matrix = _IT->second;

	std::tstring _Var(_Variable);
	std::tstring _Res;

	if (_Var == _T("X")) _Res = _Matrix[0];
	else if (_Var == _T("Y") && _Matrix.size() > 1) _Res = _Matrix[1];
	else if (_Var == _T("Z") && _Matrix.size() > 2) _Res = _Matrix[2];
	else if (_Var == _T("W") && _Matrix.size() > 3) _Res = _Matrix[3];
	return Runtime.CopyString(_Res.c_str());
}

// 32
int Extension::ArrGetInt(const TCHAR* _Name, int _Index)
{
	auto _IT = __IntArrays.find(std::tstring(_Name));
	if (_IT == __IntArrays.end()) return 0;

	const auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size()) return 0;
	return _Arr[_Index];
}

// 33
float Extension::ArrGetFloat(const TCHAR* _Name, int _Index)
{
	auto _IT = __FloatArrays.find(std::tstring(_Name));
	if (_IT == __FloatArrays.end()) return 0.0f;

	const auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size()) return 0.0f;
	return _Arr[_Index];
}

// 34
const TCHAR* Extension::ArrGetText(const TCHAR* _Name, int _Index)
{
	auto _IT = __TextArrays.find(std::tstring(_Name));
	if (_IT == __TextArrays.end())
		return Runtime.CopyString(_T(""));

	const auto& _Arr = _IT->second;

	if (_Index < 0 || _Index >= (int)_Arr.size())
		return Runtime.CopyString(_T(""));

	return Runtime.CopyString(_Arr[_Index].c_str());
}

/* 39 */ float Extension::Sin(float _X)		{ return sin(_X); }
/* 40 */ float Extension::Cos(float _X)		{ return cos(_X); }
/* 41 */ float Extension::Tan(float _X)		{ return tan(_X); }
/* 42 */ float Extension::Cosec(float _X)	{ return 1.0 / sin(_X); }
/* 43 */ float Extension::Sec(float _X)		{ return 1.0 / cos(_X); }
/* 44 */ float Extension::Ctan(float _X)	{ return 1.0 / tan(_X); }

/* 45 */ float Extension::ASin(float _X) { return asin(_X); }
/* 46 */ float Extension::ACos(float _X) { return acos(_X); }
/* 47 */ float Extension::ATan(float _X) { return atan(_X); }

/* 48 */ float Extension::Sinh(float _X) { return sinh(_X); }
/* 49 */ float Extension::Cosh(float _X) { return cosh(_X); }
/* 50 */ float Extension::Tanh(float _X) { return tanh(_X); }

/* 51 */ float Extension::ASinh(float _X) { return asinh(_X); }
/* 52 */ float Extension::ACosh(float _X) { return acosh(_X); }
/* 53 */ float Extension::ATanh(float _X) { return atanh(_X); }

/* 54 */ float Extension::ConvDegToRad(float _Deg) { return _Deg * (3.14159265359 / 180.0); }
/* 55 */ float Extension::ConvRadToDeg(float _Deg) { return _Deg * (180.0 / 3.14159265359); }

/* ############################################################ */

/* 58 */ float Extension::DVMicrphoneGet() { return __DVMicrophoneVol; }
/* 59 */ int Extension::DVMicrphoneGetDelay()	{ return __DVMicrophoneDelay; }

/* 60 */
float Extension::DVMicrphoneGetdB()
{
	if (__DVMicrophoneVol > 0.0f)	{	return 20.0f * log10(__DVMicrophoneVol); }
	else							{	return __DVMicrophoneVol;				 }
}

/* 61 */
float Extension::DVMicrphoneGetFraq()
{
	__DVMicrophoneFreqCheck = true;
	return __DVMicrophoneFreq;
}

/* 62 */ int Extension::DVMicrphoneGetSampleSize()	{ return __DVMicrophoneSampleSize; }

/* 63 */
float Extension::DVMicrphoneGetFraqHigh()
{
	__DVMicrophoneFreqCheck = true;
	return __DVMicrophoneFreqHigh;
}

/* 64 */
float Extension::DVMicrphoneGetFraqLow()
{
	__DVMicrophoneFreqCheck = true;
	return __DVMicrophoneFreqLow;
}

/* End */
