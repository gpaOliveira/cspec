/*
 *  cspec_private.c  :   Private functions
 *
 * See copyright notice in cspec.h
 *
 */

#include "cspec_private.h"
#include "cspec_output.h"

static CSpecOutputStruct* CSpec_output = 0;

int CSpec_StartDescribe(const char *descr)
{
	if( CSpec_output->startDescribeFun != 0)
	{
		CSpec_output->startDescribeFun(descr);
	}

	return 0;
}

void CSpec_EndDescribe()
{
	if( CSpec_output->endDescribeFun != 0)
	{
		CSpec_output->endDescribeFun();
	}
}

int CSpec_StartIt(const char *descr)
{
	if(CSpec_output->startItFun != 0)
	{
		CSpec_output->startItFun(descr);
	}

	return 0;
}

void CSpec_EndIt()
{
	if(CSpec_output->endItFun != 0)
	{
		CSpec_output->endItFun();
	}
}

void CSpec_Eval(const char*filename, int line_number, const char*assertion, int assertionResult)
{
	if(CSpec_output->evalFun != 0)
	{
		CSpec_output->evalFun(filename, line_number, assertion, assertionResult);
	}
}

void CSpec_Pending(const char* reason)
{
	if(CSpec_output->pendingFun != 0)
	{
		CSpec_output->pendingFun(reason);
	}
}

void CSpec_SetOutput(CSpecOutputStruct* output)
{
	CSpec_output = output;
}

