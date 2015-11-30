#include "StaticMeshManager.h"
#include "XML\XMLTreeNode.h"


CStaticMeshManager::CStaticMeshManager(void)
{
}


CStaticMeshManager::~CStaticMeshManager(void)
{
}

bool CStaticMeshManager::Load(const std::string &FileName)
{
	m_Filename = FileName;

	CXMLTreeNode l_XML;
	if (l_XML.LoadFile(FileName.c_str()))
	{
		CXMLTreeNode l_Input = l_XML["static_meshes"];
		if (l_Input.Exists())
		{
			for (int i = 0; i < l_Input.GetNumChildren(); ++i)
			{
				CXMLTreeNode l_Element = l_Input(i);
				if (l_Element.GetName() == std::string("static_mesh"))
				{
					CStaticMesh* l_StaticMesh = new CStaticMesh();
					l_StaticMesh->Load(l_Element.GetPszProperty("filename"));
					AddResource(l_Element.GetPszProperty("name"),l_StaticMesh);
				}
			}
		}
	}
	else
	{
		printf("Can't open the file %s",FileName.c_str());
		return false;
	}
	return true;
}

bool CStaticMeshManager::Reload()
{
	bool resultat = true;
	Load(m_Filename);
	for(std::map<std::string,CStaticMesh*>::iterator it = m_Resources.begin(); it != m_Resources.end();it++)
	{
		resultat = resultat & it->second->Reload();
	}
	return resultat;
}