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
		void CreateMainWindow();

		std::wstring GetAssetFullPath(LPCWSTR assetName);

		void LoadAssets();
		void LoadPipeline();
		void OnDestroy();
		void OnUpdate();
		void OnRender();
		void PopulateCommandList();
		void WaitForPreviousFrame();

		void GetHardwareAdapter(
			_In_ IDXGIFactory1* pFactory,
			_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
			bool requestHighPerformanceAdapter = false);

		static const UINT FrameCount = 2;

		bool m_useWarpDevice = false;

		std::wstring  m_assetsPath;

		float m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);
		UINT m_frameIndex = 0;
		UINT m_rtvDescriptorSize = 0;

		// Pipeline objects.
		CD3DX12_VIEWPORT m_viewport = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));
		CD3DX12_RECT m_scissorRect = CD3DX12_RECT(0, 0, static_cast<LONG>(width), static_cast<LONG>(height));
		ComPtr<IDXGISwapChain3> m_swapChain;
		ComPtr<ID3D12Device> m_device;
		ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
		ComPtr<ID3D12CommandAllocator> m_commandAllocator;
		ComPtr<ID3D12CommandQueue> m_commandQueue;
		ComPtr<ID3D12RootSignature> m_rootSignature;
		ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
		ComPtr<ID3D12PipelineState> m_pipelineState;
		ComPtr<ID3D12GraphicsCommandList> m_commandList;

		// App resources.
		ComPtr<ID3D12Resource> m_vertexBuffer;
		D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

		// Synchronization objects.
		HANDLE m_fenceEvent;
		ComPtr<ID3D12Fence> m_fence;
		UINT64 m_fenceValue;
	};

	struct Vertex
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};
}