#include "StandardEngineFramework.h"
#include "UIDGen.h"


IMPLEMENT_SINGLETON(UIDGen)

UIDGen::UIDGen()
{

}
UIDGen::~UIDGen()
{
}

LONGLONG UIDGen::GetUID()
{
	return nextID++;
}

LONGLONG UIDGen::nextID;