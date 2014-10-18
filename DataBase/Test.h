#include "Buffer.h"
struct Info{
	public:
	fileInfo *fileHandle;
	blockInfo *blockHandle; 
	Info():fileHandle(NULL),blockHandle(NULL){
	};
};
 
