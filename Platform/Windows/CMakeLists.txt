add_executable(Windows WindowsApplication.cpp D3D12WindowsApplication.cpp)
target_link_libraries(Windows 
	Common
    d3d12
    dxgi
	d3dcompiler
)