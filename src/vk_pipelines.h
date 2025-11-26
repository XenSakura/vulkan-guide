#pragma once 
#include <vk_types.h>

namespace vkutil {
	bool load_shader_module(const char* filePath, VkDevice device, VkShaderModule* outShaderModule);

};

//specifically graphics pipeline builder
//documentation on each stage of the pipeline here:
//https://docs.vulkan.org/refpages/latest/refpages/source/VkPipeline.html
class PipelineBuilder
{
private:
	std::vector<VkPipelineShaderStageCreateInfo> _shaderStages;

	VkPipelineInputAssemblyStateCreateInfo _inputAssembly;
	VkPipelineRasterizationStateCreateInfo _rasterizer;
	VkPipelineColorBlendAttachmentState _colorBlendAttachment;
	VkPipelineMultisampleStateCreateInfo _multisampling;
	
	VkPipelineDepthStencilStateCreateInfo _depthStencil;
	VkPipelineRenderingCreateInfo _renderInfo;
	VkFormat _colorAttachmentFormat;
public:
	PipelineBuilder() { clear(); }

	VkPipelineLayout _pipelineLayout;

	void clear();

	VkPipeline build_pipeline(VkDevice device);

	void set_shaders(VkShaderModule vertexShader, VkShaderModule fragmentShader);

	void set_input_topology(VkPrimitiveTopology topology);

	void set_polygon_mode(VkPolygonMode mode);

	void set_cull_mode(VkCullModeFlags cullMode, VkFrontFace frontFace);

	//TODO: by default turned off, we can turn on later
	void set_multisampling();

	void disable_blending();

	void enable_blending_additive();

	void enable_blending_alphablend();

	void set_color_attachment_format(VkFormat format);

	void set_depth_format(VkFormat format);

	void disable_depthtest();

	void enable_depthtest(bool depthWriteEnable, VkCompareOp op);
};
