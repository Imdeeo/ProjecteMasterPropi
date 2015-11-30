#ifndef MI_PUTO_ENGINE_H
#define MI_PUTO_ENGINE_H

#include "EffectManager.h"
#include "MaterialManager.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "ContextManager.h"

class CUABEngine
{
	//UAB_BUILD_GET_SET(CStaticMeshManager *, StaticMeshManager)
	//UAB_BUILD_GET_SET(CRenderableObjectManager *, RenderableObjectManager)
	UAB_BUILD_GET_SET(CMaterialManager *, MaterialManager)
	UAB_BUILD_GET_SET(CEffectManager *, EffectManager)
	UAB_BUILD_GET_SET(CTextureManager *, TextureManager)
	UAB_BUILD_GET_SET(CRenderManager *, RenderManager)
	UAB_BUILD_GET_SET(CContextManager*, ContextManager)

	static CUABEngine * m_Instance;
	
	CUABEngine(void);
	
public:

	static CUABEngine * GetInstance();
	virtual ~CUABEngine(void);

	void Init();
};

#define UABEngine (*(CUABEngine::GetInstance()))
#endif //MI_PUTO_ENGINE_H