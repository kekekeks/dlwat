#include <dlfcn.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
	if(argc<2)
	{
		printf("Usage: lib [symbol]\n");
		return 1;
	}
	void* handle = dlopen(argv[1], 1);
	if(handle == NULL)
	{
		printf("%s\n", dlerror());
		return 2;
	}
	printf("Loaded, handle: %p\n", handle);
	if(argc>2)
	{
		void* ptr= dlsym(handle, argv[2]);
		if(ptr == 0)
			printf("Unable to resolve symbol: %s\n", dlerror());
		else
			printf("Resolved to %p\n", ptr);
	}
	dlclose(handle);
	printf("Unloaded\n");


}
