#pragma once
#include <direct.h>

#ifndef WIN32
	#include <sys/types.h>
#endif

class DirectoryFinder
{
public:
	DirectoryFinder(void);
	~DirectoryFinder(void);
};

