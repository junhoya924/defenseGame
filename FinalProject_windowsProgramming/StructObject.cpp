#include "StdAfx.h"
#include "StructObject.h"


CStructObject::CStructObject(void)
{
}


CStructObject::~CStructObject(void)
{
}


int CStructObject::getMoney()
{
	return this->m_money;
}

long CStructObject::getX()
{
	return this->m_corX;
}
long CStructObject::getY()
{
	return this->m_corY;
}