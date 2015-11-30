// Test.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "StaticMesh.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CStaticMesh statmesh;
	bool loaded = statmesh.Load("Data\\Level\\Meshes\\Box001.mesh");
	if (loaded)
		printf("loaded");
	else
		printf("caca");
	return 0;
}

