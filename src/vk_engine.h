﻿// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>
#include <vector>
#include <iostream>

class VulkanEngine {
public:

	bool _isInitialized{ false };
	int _frameNumber {0};
	VkInstance _instance; // Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger; // Vulkan debug output handle
	VkPhysicalDevice _chosenGPU; // GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands
	VkSurfaceKHR _surface; // Vulkan window surface
	VkExtent2D _windowExtent{ 1700 , 900 };

	VkSwapchainKHR _swapchain; // from other articles

	// image format expected by the windowing system
	VkFormat _swapchainImageFormat;

	//array of images from the swapchain
	std::vector<VkImage> _swapchainImages;

	//array of image-views from the swapchain
	std::vector<VkImageView> _swapchainImageViews;

	struct SDL_Window* _window{ nullptr };

	VkQueue _graphicsQueue; //queue we will submit to
	uint32_t _graphicsQueueFamily; //family of that queue

	VkCommandPool _commandPool; //the command pool for our commands
	VkCommandBuffer _mainCommandBuffer; //the buffer we will record into

	VkRenderPass _renderPass;

	std::vector<VkFramebuffer> _framebuffers;

	VkSemaphore _presentSemaphore, _renderSemaphore;
	VkFence _renderFence;

	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();

private:

	void init_vulkan();

	void init_swapchain();

	void init_commands();

	void init_default_renderpass();

	void init_framebuffers();

	void init_sync_structures();
};
