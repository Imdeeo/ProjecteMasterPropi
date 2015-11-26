#include "StaticMeshManager.h"


CStaticMeshManager::CStaticMeshManager(void)
{
}


CStaticMeshManager::~CStaticMeshManager(void)
{
}

bool CStaticMeshManager::Load(const std::string &FileName)
{
	m_Filename = FileName;
	return true;
}

bool CStaticMeshManager::Reload()
{
	this->Destroy();
	Load(m_Filename);
	return false;
}