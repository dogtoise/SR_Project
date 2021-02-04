#pragma once


class DirectXDevice
{
	DECLARE_SINGLETON(DirectXDevice)

private :
	DirectXDevice();
	~DirectXDevice();

public :
	// -------------------------------------------
	// PUBLIC METHODS
	// -------------------------------------------------
	inline const LPDIRECT3DDEVICE9 GetDevice() const { return m_pDevice; }

	HRESULT Init(HWND hwnd);
	void Shutdown();

	void RenderBegin();
	void RenderEnd();

private :
	// -------------------------------------------------
	// PROPERTIES
	// ----------------------------------------------
	LPDIRECT3D9 m_pSDK;
	LPDIRECT3DDEVICE9 m_pDevice;
	HWND m_hWnd;
};

#define DEVICE DirectXDevice::Get()->GetDevice()
#define RENDER_BEGIN DirectXDevice::Get()->RenderBegin();
#define RENDER_END DirectXDevice::Get()->RenderEnd();

