#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers.
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

//------------------------------------------------------------------------------------
// direct3d variables
const int frameBufferCount = 3; // number of buffers we want, 2 for double buffering, 3 for tripple buffering
const int threadCount = 1; // number of buffers we want, 2 for double buffering, 3 for tripple buffering
ID3D12Device* device; // direct3d device
IDXGISwapChain3* swapChain; // swapchain used to switch between render targets
ID3D12CommandQueue* commandQueue; // container for command lists
ID3D12DescriptorHeap* rtvDescriptorHeap; // a descriptor heap to hold resources like the render targets
ID3D12Resource* renderTargets[frameBufferCount]; // number of render targets equal to buffer count
ID3D12CommandAllocator* commandAllocator[frameBufferCount * threadCount]; // we want enough allocators for each buffer * number of threads (we only have one thread)
ID3D12GraphicsCommandList* commandList; // a command list we can record commands into, then execute them to render the frame
ID3D12Fence* fence[frameBufferCount];    // an object that is locked while our command list is being executed by the gpu. We need as many 
HANDLE fenceEvent; // a handle to an event when our fence is unlocked by the gpu
UINT64 fenceValue[frameBufferCount]; // this value is incremented each frame. each fence will have its own value

int frameIndex; // current rtv we are on
int rtvDescriptorSize; // size of the rtv descriptor on the device (all front and back buffers will be the same size)

//------------------------------------------------------------------------------------

// this will only call release if an object exists (prevents exceptions calling release on non existant objects)
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

//function declarations
// initializes direct3d 12
bool InitD3D();

// main application loop
void Mainloop();

// update the direct3d pipeline (update command lists)
void UpdateD3DPipeline();

// execute the command list
void Render(); 

// release com ojects and clean up memory
void Cleanup(); 

// wait until gpu is finished with command list
void WaitForPreviousFrame(); 