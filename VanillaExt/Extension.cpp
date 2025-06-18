#include "Common.cpp"

#include <cstdint>
#include <unordered_set>

///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

#ifdef _WIN32
Extension::Extension(RunObject* const _rdPtr, const EDITDATA* const edPtr, const CreateObjectInfo* const cobPtr) :
	rdPtr(_rdPtr), rhPtr(_rdPtr->get_rHo()->get_AdRunHeader()), Runtime(this), FusionDebugger(this)
#elif defined(__ANDROID__)
Extension::Extension(const EDITDATA* const edPtr, const jobject javaExtPtr) :
	javaExtPtr(javaExtPtr, "Extension::javaExtPtr from Extension ctor"),
	Runtime(this, this->javaExtPtr), FusionDebugger(this)
#else
Extension::Extension(const EDITDATA* const edPtr, void* const objCExtPtr) :
	objCExtPtr(objCExtPtr), Runtime(this, objCExtPtr), FusionDebugger(this)
#endif
{
	/*
		Link all your action/condition/expression functions to their IDs to match the
		IDs in the JSON here
	*/

	/* ============================================================================================================= */

	/// Actions ///////////////////////////////////////////////////

		LinkAction(0, ActionExample);
		LinkAction(1, SecondActionExample);

		LinkAction(2, PtrFreeMemory);
		LinkAction(3, PtrWriteInt);
		LinkAction(4, PtrCopyMemory);
		LinkAction(5, PtrWriteFloat);

		LinkAction(6, MtxOverrideInt1);
		LinkAction(7, MtxOverrideInt2);
		LinkAction(8, MtxOverrideInt3);
		LinkAction(9, MtxOverrideInt4);

		LinkAction(10, MtxOverrideFloat1);
		LinkAction(11, MtxOverrideFloat2);
		LinkAction(12, MtxOverrideFloat3);
		LinkAction(13, MtxOverrideFloat4);

		LinkAction(14, MtxCreateInt);
		LinkAction(15, MtxDeleteInt);
		LinkAction(16, MtxSetInt);

		LinkAction(17, MtxCreateFloat);
		LinkAction(18, MtxDeleteFloat);
		LinkAction(19, MtxSetFloat);

		LinkAction(20, MtxCreateText);
		LinkAction(21, MtxDeleteText);
		LinkAction(22, MtxSetText);

		LinkAction(23, MtxOverrideText1);
		LinkAction(24, MtxOverrideText2);
		LinkAction(25, MtxOverrideText3);
		LinkAction(26, MtxOverrideText4);

		LinkAction(27, ArrCreateInt);
		LinkAction(28, ArrDeleteInt);
		LinkAction(29, ArrSetInt);

		LinkAction(30, ArrCreateFloat);
		LinkAction(31, ArrDeleteFloat);
		LinkAction(32, ArrSetFloat);

		LinkAction(33, ArrCreateText);
		LinkAction(34, ArrDeleteText);
		LinkAction(35, ArrSetText);

		LinkAction(36, DVMicrophoneCapture);
		LinkAction(37, DVMicrophoneSetDelay);
		LinkAction(38, DVMicrophoneSetSampleSize);
		LinkAction(39, DVMicrophoneRefresh);
		LinkAction(40, DVMicrophoneRefreshList);
		LinkAction(41, DVMicrophoneSetDevice);

	/// Conditions ///////////////////////////////////////////////////

		LinkCondition(0, AreTwoNumbersEqual);
		LinkCondition(1, IsPointerValid);
		LinkCondition(2, IsPointerNull);

		LinkCondition(3, IsPointerValueInt);
		LinkCondition(4, IsPointerValueFloat);
		LinkCondition(5, IsPointerValueText);

	/// Expressions ///////////////////////////////////////////////////

		LinkExpression(0, Add);
		LinkExpression(1, HelloWorld);
		LinkExpression(2, PtrAllocateMemory);
		LinkExpression(3, PtrReadInt);
		LinkExpression(4, PtrReallocMemory);
		LinkExpression(5, PtrReadFloat);
		LinkExpression(6, MtxReadInt);
		LinkExpression(7, MtxReadFloat);

		LinkExpression(8, BitAND);
		LinkExpression(9, BitOR);
		LinkExpression(10, BitXOR);
		LinkExpression(11, BitNOT);
		LinkExpression(12, BitNAND);
		LinkExpression(13, BitNOR);
		LinkExpression(14, BitXNOR);

		LinkExpression(35, BitIMPLY);
		LinkExpression(36, BitNIMPLY);
		LinkExpression(37, BitCONVERSE);
		LinkExpression(38, BitNCONVERSE);

		LinkExpression(15, BitShiftLeft);
		LinkExpression(16, BitShiftRight);
		LinkExpression(17, BitRotateLeft);
		LinkExpression(18, BitRotateRight);

		LinkExpression(19, Iff);
		LinkExpression(20, IfElse);
		LinkExpression(21, ConditionEqual);
		LinkExpression(22, ConditionNotEqual);
		LinkExpression(23, ConditionLess);
		LinkExpression(24, ConditionLessEqual);
		LinkExpression(25, ConditionGreater);
		LinkExpression(26, ConditionGreaterEqual);

		LinkExpression(27, IfText);
		LinkExpression(28, IfElseText);
		LinkExpression(29, ConditionEqualText);
		LinkExpression(30, ConditionNotEqualText);

		LinkExpression(31, MtxReadText);

		LinkExpression(32, ArrGetInt);
		LinkExpression(33, ArrGetFloat);
		LinkExpression(34, ArrGetText);

		LinkExpression(39, Sin);
		LinkExpression(40, Cos);
		LinkExpression(41, Tan);
		LinkExpression(42, Cosec);
		LinkExpression(43, Sec);
		LinkExpression(44, Ctan);

		LinkExpression(45, ASin);
		LinkExpression(46, ACos);
		LinkExpression(47, ATan);

		LinkExpression(48, Sinh);
		LinkExpression(49, Cosh);
		LinkExpression(50, Tanh);

		LinkExpression(51, ASinh);
		LinkExpression(52, ACosh);
		LinkExpression(53, ATanh);

		LinkExpression(54, ConvDegToRad);
		LinkExpression(55, ConvRadToDeg);

		LinkExpression(56, ConditionV);
		LinkExpression(57, ConditionText);

		LinkExpression(58, DVMicrphoneGet);
		LinkExpression(59, DVMicrphoneGetDelay);
		LinkExpression(60, DVMicrphoneGetdB);
		LinkExpression(61, DVMicrphoneGetFraq);
		LinkExpression(62, DVMicrphoneGetSampleSize);
		LinkExpression(63, DVMicrphoneGetFraqHigh);
		LinkExpression(64, DVMicrphoneGetFraqLow);
		LinkExpression(65, DVMicrphoneGetName);

		LinkExpression(66, DVMicrophoneGetCount);
		LinkExpression(67, DVMicrophoneGetID);
		LinkExpression(68, DVMicrophoneGetName);
		LinkExpression(69, DVMicrophoneGetCurrentID);

		LinkExpression(70, DVMicrphoneGetFraqLowdB);
		LinkExpression(71, DVMicrphoneGetFraqHighdB);
		LinkExpression(72, DVMicrphoneGetFraqdB);

		LinkExpression(73, DVMicrophoneFreqCheck);
		LinkExpression(74, DVMicrophoneIsActive);

		LinkExpression(75, GetLastError);

		/* ============================================================================================================= */

	/*
		This is where you'd do anything you'd do in CreateRunObject in the original SDK

		It's the only place you'll get access to edPtr at runtime, so you should transfer
		anything from edPtr to the extension class here.

	*/

	// Don't use "this" inside these lambda functions, always ext.
	// There can be nothing in the [] section of the lambda.
	// If you're not sure about lambdas, you can remove this debugger stuff without any side effects;
	// it's just an example of how to use the debugger. You can view it in Fusion itself to see.
	/*
	FusionDebugger.AddItemToDebugger(
		// reader function for your debug item
		[](Extension *ext, std::tstring &writeTo) {
			writeTo = _T("My text is: ") + ext->exampleDebuggerTextItem;
		},
		// writer function (can be null if you don't want user to be able to edit it in debugger)
		[](Extension *ext, std::tstring &newText)
		{
			ext->exampleDebuggerTextItem = newText;
			return true; // accept the changes
		}, 500, NULL
	);
	*/


	// Read object DarkEdif properties; you can pass property name, or property index
	// This will work on all platforms the same way.
	//bool checkboxWithinFolder = edPtr->Props.IsPropChecked("Checkbox within folder"sv);
	//std::tstring editable6Text = edPtr->Props.GetPropertyStr("Editable 6"sv);

	// These lines do nothing, but prevent the compiler warning the variables are unused
	//(void)checkboxWithinFolder;
	//(void)editable6Text;
}

Extension::~Extension()
{

}


REFLAG Extension::Handle()
{
	/*
		If your extension will draw to the MMF window you should first
		check if anything about its display has changed :

			if (rdPtr->roc.rcChanged)
			  return REFLAG::DISPLAY;
			else
			  return REFLAG::NONE;

		You will also need to make sure you change this flag yourself
		to 1 whenever you want to redraw your object

		If your extension won't draw to the window, but it still needs
		to do something every MMF loop use :

			return REFLAG::NONE;

		If you don't need to do something every loop, use :

			return REFLAG::ONE_SHOT;

		This doesn't mean this function can never run again. If you want MMF
		to handle your object again (causing this code to run) use this function:

			Runtime.Rehandle();

		At the end of the loop this code will run

	*/

	// Will not be called next loop
	return REFLAG::ONE_SHOT;
}


REFLAG Extension::Display()
{
	/*
		If you return REFLAG_DISPLAY in Handle() this routine will run.
	*/

	// Ok
	return REFLAG::DISPLAY;
}

short Extension::FusionRuntimePaused()
{

	// Ok
	return 0;
}

short Extension::FusionRuntimeContinued()
{

	// Ok
	return 0;
}


// These are called if there's no function linked to an ID

void Extension::UnlinkedAction(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedAction() called"), _T("Running a fallback for action ID %d. Make sure you ran LinkAction()."), ID);
}

long Extension::UnlinkedCondition(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedCondition() called"), _T("Running a fallback for condition ID %d. Make sure you ran LinkCondition()."), ID);
	return 0;
}

long Extension::UnlinkedExpression(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedExpression() called"), _T("Running a fallback for expression ID %d. Make sure you ran LinkExpression()."), ID);
	// Unlinked A/C/E is fatal error, but try not to return null string and definitely crash it
	if ((size_t)ID < Edif::SDK->ExpressionInfos.size() && Edif::SDK->ExpressionInfos[ID]->Flags.ef == ExpReturnType::String)
		return (long)Runtime.CopyString(_T(""));
	return 0;
}
