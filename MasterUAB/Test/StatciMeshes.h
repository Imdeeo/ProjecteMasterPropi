#pragma once
#include <string>
#include <vector>
class CStatciMeshes
{
protected:
	std::string 
	std::vector<CRenderableVertexs*> m_RVs;
	std::vector<CMaterial *> m_Materials;
	unsigned int m_NumVertexs, m_NumFaces;
public:
	CStatciMeshes();
	~CStatciMeshes();
	bool Load (const std::string &FileName);
	bool Reload ();
	void Render (CRenderManager *RM) const;
};

