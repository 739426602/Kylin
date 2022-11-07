#pragma once

#include "stdafx.h"
#include "helper.h"
#include <stdexcept>
#include "WindowsApplication.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;


namespace kylin
{
	class D3D12WindowsApplication : public WindowsApplication
	{

	public:
		void CreateMainWindow() final;
		void Tick() final;

		std::wstring GetAssetFullPath(LPCWSTR assetName);

		void OnDestroy();
		void OnUpdate();
		void OnRender();

		void GetHardwareAdapter(
			_In_ IDXGIFactory1* pFactory,
			_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
			bool requestHighPerformanceAdapter = false);



	private:
		static const UINT FrameCount = 2;
		static const UINT TextureWidth = 256;
		static const UINT TextureHeight = 256;
		static const UINT TexturePixelSize = 4;

		struct Vertex
		{
			XMFLOAT3 position;
			XMFLOAT2 uv;
		};
		// Pipeline objects.
		CD3DX12_VIEWPORT m_viewport;
		CD3DX12_RECT m_scissorRect;
		ComPtr<IDXGISwapChain3> m_swapChain;
		ComPtr<ID3D12Device> m_device;
		ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
		ComPtr<ID3D12CommandAllocator> m_commandAllocator;
		ComPtr<ID3D12CommandQueue> m_commandQueue;
		ComPtr<ID3D12RootSignature> m_rootSignature;
		ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
		ComPtr<ID3D12DescriptorHeap> m_srvHeap;
		ComPtr<ID3D12PipelineState> m_pipelineState;
		ComPtr<ID3D12GraphicsCommandList> m_commandList;
		UINT m_rtvDescriptorSize;

		// App resources.
		ComPtr<ID3D12Resource> m_vertexBuffer;
		D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
		ComPtr<ID3D12Resource> m_texture;

		// Synchronization objects.
		UINT m_frameIndex;
		HANDLE m_fenceEvent;
		ComPtr<ID3D12Fence> m_fence;
		UINT64 m_fenceValue;
		bool m_useWarpDevice = false;
		std::wstring m_assetsPath;
		float m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);

		void LoadPipeline();
		void LoadAssets();
		std::vector<UINT8> GenerateTextureData();
		void PopulateCommandList();
		void WaitForPreviousFrame();
	};
}