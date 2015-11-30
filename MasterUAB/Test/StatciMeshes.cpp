#include "StatciMeshes.h"


#include <stdio.h>
#include "RenderManager.h"

#define HEADER 65109
#define FOOTER 22014

CStatciMeshes::CStatciMeshes():CNamed("")
{
}
CStatciMeshes::~CStatciMeshes()
{
}
bool CStatciMeshes::Load(const std::string &FileName)
{
	unsigned int header_footer;
	m_Name = FileName;
	FILE* p_file;

	p_file = fopen(FileName.c_str(),"rb");


	
	if(!p_file)
	{
		printf("Can't open the file %s",FileName.c_str());
		return false;
	}



	return true;
}

bool CStatciMeshes::Reload()
{
	for(size_t i = 0;i<m_Materials.size();i++)
		delete m_Materials[i];
	m_Materials.clear;
	for(size_t i = 0;i<m_RVs.size();i++)
		delete m_RVs[i];
	m_RVs.clear;
	return Load(m_Name);
}

void CStatciMeshes::Render(CRenderManager *RM) const
{
	//CUABEngine::GetInstance()->GetContextManager()->Draw(new CRenderableVertexs(),,,)
}