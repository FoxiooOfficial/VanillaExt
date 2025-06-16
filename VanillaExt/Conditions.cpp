/* Conditions.cpp */

#include "Common.hpp"

bool Extension::AreTwoNumbersEqual(int First, int Second)
{
	return First == Second;
}

/* 1 */ bool Extension::IsPointerValid(intptr_t _Ptr)					{ return __AllocatedPointers.count(_Ptr) > 0; }
/* 2 */	bool Extension::IsPointerNull(intptr_t _Ptr)					{ return _Ptr == 0; }

/* 3 */	bool Extension::IsPointerValueInt(intptr_t _Ptr, int _Value)			{ return _Ptr == _Value; }
/* 4 */	bool Extension::IsPointerValueFloat(intptr_t _Ptr, float _Value)		{ return _Ptr == _Value; }
/* 5 */	bool Extension::IsPointerValueText(intptr_t _Ptr, const TCHAR* _Text)	{ return _tcscmp(reinterpret_cast<const TCHAR*>(_Ptr), _Text) == 0; }

/* End */
