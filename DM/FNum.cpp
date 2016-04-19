#include "stdafx.h"
#include "FNum.h"


FNum::FNum()
	:n(0)
{
}

FNum::FNum(unsigned int n)
	:n(n)
{
	k.resize(n - 2);
}