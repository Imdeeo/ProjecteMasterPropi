#include "Named.h"
#include "XML\XMLTreeNode.h"
#include "assert.h"


CNamed::CNamed()
{
	assert(!"This method mustn't be called");
}

CNamed::CNamed(const CXMLTreeNode &TreeNode)
{
}

CNamed::CNamed(const std::string &Name):
m_Name(Name)
{

}

void CNamed::SetName(const std::string &Name)
{
	m_Name = Name;
}
const std::string& CNamed::GetName()
{
	return m_Name;
}