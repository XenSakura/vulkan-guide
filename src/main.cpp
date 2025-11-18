#include <vk_engine.h>
#include <memory>
int main(int argc, char* argv[])
{
	

	VulkanEngine engine;
	engine.init();	
	
	engine.run();	

	engine.cleanup();	


	return 0;
}

