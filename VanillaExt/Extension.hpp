/* Extension.hpp */

#pragma once
#include "DarkEdif.hpp"

#include <unordered_set>
#include <cstdint>

class Extension
{
	public:

		RunHeader* rhPtr;
		RunObjectMultiPlatPtr rdPtr; // you should not need to access this (but i want)

		#ifdef __ANDROID__
			global<jobject> javaExtPtr;

		#elif defined(__APPLE__)
			void* const objCExtPtr;

		#endif

		Edif::Runtime Runtime;

		static const int MinimumBuild = 254;
		static const int Version = 1;

		// If you change OEFLAGS, make sure you modify RUNDATA so the data is available, or you'll get crashes!
		// For example, OEFLAGS::VALUES makes use of the AltVals rv struct.
		static const OEFLAGS OEFLAGS = OEFLAGS::NONE;
		static const OEPREFS OEPREFS = OEPREFS::NONE;

		static const int WindowProcPriority = 100;

		#ifdef _WIN32
			Extension(RunObject* const rdPtr, const EDITDATA* const edPtr, const CreateObjectInfo* const cobPtr);

		#elif defined(__ANDROID__)
			Extension(const EDITDATA* const edPtr, const jobject javaExtPtr);

		#else
			Extension(const EDITDATA* const edPtr, void* const objCExtPtr);

		#endif

	~Extension();

	// To add items to the Fusion Debugger, just uncomment this line.
	DarkEdif::FusionDebugger FusionDebugger;
	// After enabling it, you run FusionDebugger.AddItemToDebugger() inside Extension's constructor
	// As an example: std::tstring exampleDebuggerTextItem;

	/*  Add any data you want to store in your extension to this class
		(eg. what you'd normally store in rdPtr in old SDKs).

		Unlike rdPtr, you can store real C++ objects with constructors
		and destructors, without having to call them manually or store
		a pointer.
	*/

	// int MyVariable;

	/*  Add your actions, conditions and expressions as real class member
		functions here. The arguments (and return type for expressions) must
		match EXACTLY what you defined in the JSON.

		Remember to link the actions, conditions and expressions to their
		numeric IDs in the class constructor (Extension.cpp)
	*/

	/* ============================================================================================================= */

	/// Actions ///////////////////////////////////////////////////

		void ActionExample(int ExampleParameter); //IGNORE
		void SecondActionExample(); //IGNORE

		/* 2 */ void PtrFreeMemory	(intptr_t _Ptr);
		/* 3 */ void PtrWriteInt	(intptr_t _Ptr, int _Value);
		/* 4 */ void PtrCopyMemory	(intptr_t _Source, intptr_t _Destination, int _Size);
		/* 5 */ void PtrWriteFloat	(intptr_t _Ptr, float _Value);

		/* ################# */

		/* 14 */ void MtxCreateInt	(const TCHAR* _Name, const TCHAR* _Type);
		/* 15 */ void MtxDeleteInt	(const TCHAR* _Name);
		/* 16 */ void MtxSetInt		(const TCHAR* _Name, const TCHAR* _Variable, int _Value);

				/* 6 */ void MtxOverrideInt1	(const TCHAR* _Name, int x);
				/* 7 */ void MtxOverrideInt2	(const TCHAR* _Name, int x, int y);
				/* 8 */ void MtxOverrideInt3	(const TCHAR* _Name, int x, int y, int z);
				/* 9 */ void MtxOverrideInt4	(const TCHAR* _Name, int x, int y, int z, int w);

		/* 17 */ void MtxCreateFloat	(const TCHAR* _Name, const TCHAR* _Type);
		/* 18 */ void MtxDeleteFloat	(const TCHAR* _Name);
		/* 19 */ void MtxSetFloat		(const TCHAR* _Name, const TCHAR* _Variable, float _Value);

				/* 10 */ void MtxOverrideFloat1	(const TCHAR* _Name, float x);
				/* 11 */ void MtxOverrideFloat2	(const TCHAR* _Name, float x, float y);
				/* 12 */ void MtxOverrideFloat3	(const TCHAR* _Name, float x, float y, float z);
				/* 13 */ void MtxOverrideFloat4	(const TCHAR* _Name, float x, float y, float z, float w);

		/* 20 */ void MtxCreateText	(const TCHAR* _Name, const TCHAR* _Type);
		/* 21 */ void MtxDeleteText	(const TCHAR* _Name);
		/* 22 */ void MtxSetText	(const TCHAR* _Name, const TCHAR* _Variable, const TCHAR* _Value);

				/* 23 */ void MtxOverrideText1(const TCHAR* _Name, const TCHAR* x);
				/* 24 */ void MtxOverrideText2(const TCHAR* _Name, const TCHAR* x, const TCHAR* y);
				/* 25 */ void MtxOverrideText3(const TCHAR* _Name, const TCHAR* x, const TCHAR* y, const TCHAR* z);
				/* 26 */ void MtxOverrideText4(const TCHAR* _Name, const TCHAR* x, const TCHAR* y, const TCHAR* z, const TCHAR* w);

		/* ################# */

		/* 27 */ void ArrCreateInt		(const TCHAR* _Name, int _Length);
		/* 28 */ void ArrDeleteInt		(const TCHAR* _Name);
		/* 29 */ void ArrSetInt			(const TCHAR* _Name, int _Index, int _Value);

		/* 30 */ void ArrCreateFloat	(const TCHAR* _Name, int _Length);
		/* 31 */ void ArrDeleteFloat	(const TCHAR* _Name);
		/* 32 */ void ArrSetFloat		(const TCHAR* _Name, int _Index, float _Value);

		/* 33 */ void ArrCreateText		(const TCHAR* _Name, int _Length);
		/* 34 */ void ArrDeleteText		(const TCHAR* _Name);
		/* 35 */ void ArrSetText		(const TCHAR* _Name, int _Index, const TCHAR* _Value);

		/* ################# */

		/* 36 */ void DVMicrophoneCapture		();
		/* 37 */ void DVMicrophoneSetDelay		(int x);
		/* 38 */ void DVMicrophoneSetSampleSize	(int x);
		/* 39 */ void DVMicrophoneRefresh		();
		/* 40 */ void DVMicrophoneRefreshList	();
		/* 41 */ void DVMicrophoneSetDevice		(const TCHAR* _DeviceIndex);

	/// Conditions ///////////////////////////////////////////////////

		bool AreTwoNumbersEqual(int FirstNumber, int SecondNumber);

		/* 1 */ bool IsPointerValid	(intptr_t _Ptr);
		/* 2 */ bool IsPointerNull	(intptr_t _Ptr);

		/* 3 */ bool IsPointerValueInt		(intptr_t _Ptr, int _Value);
		/* 4 */ bool IsPointerValueFloat	(intptr_t _Ptr, float _Value);
		/* 5 */ bool IsPointerValueText		(intptr_t _Ptr, const TCHAR* _Text);

	/// Expressions ///////////////////////////////////////////////////

		int Add(int FirstNumber, int SecondNumber);
		const TCHAR * HelloWorld();

		/* 2 */ intptr_t PtrAllocateMemory	(int _Bytes);
		/* 3 */ int      PtrReadInt			(intptr_t _Ptr);
		/* 4 */ intptr_t PtrReallocMemory	(intptr_t _Ptr, int _Size);
		/* 5 */ float    PtrReadFloat		(intptr_t _Ptr);

		/* 6 */  int			MtxReadInt		(const TCHAR* _Name, const TCHAR* _Variable);
		/* 7 */  float			MtxReadFloat	(const TCHAR* _Name, const TCHAR* _Variable);
		/* 31 */ const TCHAR*	MtxReadText		(const TCHAR* _Name, const TCHAR* _Variable);

		/* 8 */  int BitAND		(int _A, int _B);
		/* 9 */  int BitOR		(int _A, int _B);
		/* 10 */ int BitXOR		(int _A, int _B);
		/* 11 */ int BitNOT		(int _A);
		/* 12 */ int BitNAND	(int _A, int _B);
		/* 13 */ int BitNOR		(int _A, int _B);
		/* 14 */ int BitXNOR	(int _A, int _B);

		/* 35 */ int BitIMPLY		(int _A, int _B);
		/* 36 */ int BitNIMPLY		(int _A, int _B);
		/* 37 */ int BitCONVERSE	(int _A, int _B);
		/* 38 */ int BitNCONVERSE	(int _A, int _B);

		/* 15 */ int BitShiftLeft	(int _A, int _Shift);
		/* 16 */ int BitShiftRight	(int _A, int _Shift);
		/* 17 */ int BitRotateLeft	(int _A, int _Shift);
		/* 18 */ int BitRotateRight	(int _A, int _Shift);

		/* 19 */ float	Iff						(int _Condition, float _ValueTrue);
		/* 20 */ float	IfElse					(int _Condition, float _ValueTrue, float _ValueFalse);

		/* 21 */ int	ConditionEqual			(float _A, float _B);
		/* 22 */ int	ConditionNotEqual		(float _A, float _B);
		/* 23 */ int	ConditionLess			(float _A, float _B);
		/* 24 */ int	ConditionLessEqual		(float _A, float _B);
		/* 25 */ int	ConditionGreater		(float _A, float _B);
		/* 26 */ int	ConditionGreaterEqual	(float _A, float _B);
		/* 56 */ int	ConditionV				(float _A, const TCHAR* _Condition, float _B);

		/* 27 */ const TCHAR*	IfText		(int _Condition, const TCHAR* _ValueTrue);
		/* 28 */ const TCHAR*	IfElseText	(int _Condition, const TCHAR* _ValueTrue, const TCHAR* _ValueFalse);

		/* 29 */ int ConditionEqualText		(const TCHAR* _A, const TCHAR* _B);
		/* 30 */ int ConditionNotEqualText	(const TCHAR* _A, const TCHAR* _B);
		/* 57 */ int ConditionText(const TCHAR* _A, const TCHAR* _Condition, const TCHAR* _B);

		/* 32 */ int			ArrGetInt	(const TCHAR* _Name, int _Index);
		/* 33 */ float			ArrGetFloat	(const TCHAR* _Name, int _Index);
		/* 34 */ const TCHAR*	ArrGetText	(const TCHAR* _Name, int _Index);

		/* 39 */ float Sin(float _X);
		/* 40 */ float Cos(float _X);
		/* 41 */ float Tan(float _X);
		/* 42 */ float Cosec(float _X);
		/* 43 */ float Sec(float _X);
		/* 44 */ float Ctan(float _X);

		/* 45 */ float ASin(float _X);
		/* 46 */ float ACos(float _X);
		/* 47 */ float ATan(float _X);

		/* 48 */ float Sinh(float _X);
		/* 49 */ float Cosh(float _X);
		/* 50 */ float Tanh(float _X);

		/* 51 */ float ASinh(float _X);
		/* 52 */ float ACosh(float _X);
		/* 53 */ float ATanh(float _X);

		/* 54 */ float ConvDegToRad(float _Deg);
		/* 55 */ float ConvRadToDeg(float _Deg);

		/* 58 */ float			DVMicrphoneGet			();
		/* 59 */ int			DVMicrphoneGetDelay		();
		/* 60 */ float			DVMicrphoneGetdB		();
		/* 61 */ float			DVMicrphoneGetFraq		();
		/* 62 */ int			DVMicrphoneGetSampleSize();
		/* 63 */ float			DVMicrphoneGetFraqHigh	();
		/* 64 */ float			DVMicrphoneGetFraqLow	();
		/* 65 */ const TCHAR*	DVMicrphoneGetName		();
		/* 66 */ int			DVMicrophoneGetCount	();
		/* 67 */ const TCHAR*	DVMicrophoneGetID		(int _Index);
		/* 68 */ const TCHAR*	DVMicrophoneGetName		(int _Index);
		/* 69 */ const TCHAR*	DVMicrophoneGetCurrentID();

		/* 70 */ float			DVMicrphoneGetFraqLowdB ();
		/* 71 */ float			DVMicrphoneGetFraqHighdB();
		/* 72 */ float			DVMicrphoneGetFraqdB	();

		/* 73 */ int			DVMicrophoneFreqCheck();
		/* 74 */ int			DVMicrophoneIsActive();

		/* 75 */ const TCHAR*	GetLastError();

	/* ============================================================================================================= */

	/* These are called if there's no function linked to an ID */

	void UnlinkedAction(int ID);
	long UnlinkedCondition(int ID);
	long UnlinkedExpression(int ID);

	/*  These replace the functions like HandleRunObject that used to be
		implemented in Runtime.cpp. They work exactly the same, but they're
		inside the extension class.
	*/

	REFLAG Handle();
	REFLAG Display();

	short FusionRuntimePaused();
	short FusionRuntimeContinued();
};

/* End */
