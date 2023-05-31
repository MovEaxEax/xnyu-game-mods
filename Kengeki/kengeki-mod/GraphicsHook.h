#pragma once

typedef void(__stdcall* InstallGraphicHookT)(std::string functionName, void* functionHookBefore, void* functionHookAfter);
InstallGraphicHookT pInstallGraphicHook = nullptr;
typedef void(__stdcall* RemoveGraphicHookT)(std::string functionName);
RemoveGraphicHookT pRemoveGraphicHook = nullptr;

void InitGraphicsHook()
{
	/*
	
	Hook specific function of the graphic engine. Write a function with the
	correct type definition of the desired graphics function and pass it
	as void* parameter to the SetGraphicHook() funciton. Also type the name of the
	function. There can be 10 hooks at a time active;

	pSetGraphicHook("DrawIndexed", (void*)MyDrawIndexedHook);
	pSetGraphicHook("CheckCounter", (void*)MyCheckCounterHook);
	etc.

	*/
}

