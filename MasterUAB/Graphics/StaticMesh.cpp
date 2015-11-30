#include <stdio.h>
#include "UABEngine.h"
#include "StaticMesh.h"
#include "RenderManager.h"

#include "Material.h"
#include "RenderableVertexs.h"

#define HEADER 65109
#define FOOTER 22014

CStaticMesh::CStaticMesh(void):CNamed("")
{
}

CStaticMesh::~CStaticMesh(void)
{
}

bool CStaticMesh::Load(const std::string &FileName)
{
	unsigned short int header_footer=0;
	size_t readed;
	m_Name = FileName;
	FILE* p_file;
	fopen_s(&p_file,FileName.c_str(),"rb");

	if(!p_file)
	{
		printf("Can't open the file %s",FileName.c_str());
		return false;
	}
	while(EOF!=header_footer)
	{
		readed = fread_s(&header_footer,1,1,1,p_file);
	}

	fclose(p_file);
	return true;
}

bool CStaticMesh::Reload()
{
	for(size_t i = 0;i<m_Materials.size();i++)
		delete m_Materials[i];
	m_Materials.clear();
	for(size_t i = 0;i<m_RVs.size();i++)
		delete m_RVs[i];
	m_RVs.clear();
	return Load(m_Name);
}

void CStaticMesh::Render(CRenderManager *RM) const
{
	//CUABEngine::GetInstance()->GetContextManager()->Draw(new CRenderableVertexs(),,,)
}