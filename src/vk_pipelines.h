#pragma once 
#include <vk_types.h>

namespace vkutil {
	bool load_shader_module(const char* filePath, VkDevice device, VkShaderModule* outShaderModule);

};

//specifically graphics pipeline builder
class PipelineBuilder
{
	std::vector<VkPipelineShaderStageCreateInfo> _shaderStages;
};
