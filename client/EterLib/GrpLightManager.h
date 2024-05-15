#ifndef METIN2_CLIENT_ETERLIB_GRPLIGHTMANAGER_HPP
#define METIN2_CLIENT_ETERLIB_GRPLIGHTMANAGER_HPP

#pragma once

#include <base/Singleton.hpp>

#include "GrpBase.h"
#include "Util.h"
#include "Pool.h"

#include <deque>
#include <vector>
#include <unordered_map>

typedef DWORD TLightID;

enum ELightType
{
    LIGHT_TYPE_STATIC,
    // Continuously turning on light
    LIGHT_TYPE_DYNAMIC,
    // Immediately turning off light
};

class CLightBase
{
public:
    CLightBase()
    {
    };

    virtual ~CLightBase()
    {
    };

    void SetCurrentTime();

protected:
    static float ms_fCurTime;
};

class CLight : public CGraphicBase, public CLightBase
{
public:
    CLight();
    virtual ~CLight();

    void Initialize();
    void Clear();

    void Update();

    void SetParameter(TLightID id, const D3DLIGHT9 &c_rLight);

    void SetDistance(float fDistance);

    float GetDistance() const
    {
        return m_fDistance;
    }

    TLightID GetLightID()
    {
        return m_LightID;
    }

    bool isEdited()
    {
        return m_isEdited;
    }

    void SetDeviceLight(bool bActive);

    void SetDiffuseColor(float fr, float fg, float fb, float fa = 1.0f);
    void SetAmbientColor(float fr, float fg, float fb, float fa = 1.0f);
    void SetRange(float fRange);
    void SetPosition(float fx, float fy, float fz);

    const Vector3 &GetPosition() const;

    void BlendDiffuseColor(const DirectX::SimpleMath::Color &c_rColor, float fBlendTime, float fDelayTime = 0.0f);
    void BlendAmbientColor(const DirectX::SimpleMath::Color &c_rColor, float fBlendTime, float fDelayTime = 0.0f);
    void BlendRange(float fRange, float fBlendTime, float fDelayTime = 0.0f);

private:
    TLightID m_LightID; // Light ID. equal to D3D light index

    D3DLIGHT9 m_d3dLight;
    bool m_isEdited;
    float m_fDistance;

    TTransitorColor m_DiffuseColorTransitor;
    TTransitorColor m_AmbientColorTransitor;
    TTransitorFloat m_RangeTransitor;
};

class CLightManager : public CGraphicBase, public CLightBase, public CSingleton<CLightManager>
{
public:
    enum
    {
        LIGHT_LIMIT_DEFAULT = 3,
        //			LIGHT_MAX_NUM = 32,
    };

    typedef std::deque<TLightID> TLightIDDeque;
    typedef std::unordered_map<TLightID, CLight *> TLightMap;
    typedef std::vector<CLight *> TLightSortVector;

public:
    CLightManager();
    virtual ~CLightManager();

    void Destroy();

    void Initialize();

    // NOTE : FlushLight후 렌더링
    //        그 후 반드시 RestoreLight를 해줘야만 한다.
    void Update();
    void FlushLight();
    void RestoreLight();

    /////
    void RegisterLight(ELightType LightType, TLightID *poutLightID, D3DLIGHT9 &LightData);
    CLight *GetLight(TLightID LightID);
    void DeleteLight(TLightID LightID);
    /////

    void SetCenterPosition(const Vector3 &c_rv3Position);
    void SetLimitLightCount(DWORD dwLightCount);
    void SetSkipIndex(DWORD dwSkipIndex);

protected:
    TLightIDDeque m_NonUsingLightIDDeque;

    TLightMap m_LightMap;
    TLightSortVector m_LightSortVector;

    Vector3 m_v3CenterPosition;
    DWORD m_dwLimitLightCount;
    DWORD m_dwSkipIndex;

protected:
    TLightID NewLightID();
    void ReleaseLightID(TLightID LightID);

    CDynamicPool<CLight> m_LightPool;
};

#endif
