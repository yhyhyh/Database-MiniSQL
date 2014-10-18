#ifndef _BUFFER_H 
#define _BUFFER_H

#define BLOCK_LEN			4096	// the size of one block
#define MAX_FILE_ACTIVE 	5		// limit the active files in the buffer
#define MAX_BLOCK			40		// the max number of the blocks
#include <afx.h>
struct fileInfo  {
	int type;				// 0-> data file£¬ 1 -> index file
	CString fileName;		// the name of the file
	int recordAmount;		// the number of record in the file
//	int freeNum;			// the free block number which could be used for the file
	int recordLength;		// the length of the record in the file
	fileInfo *next;			// the pointer points to the next file
	blockInfo *firstBlock;	// point to the first block within the file
};	
struct blockInfo  {
	int blockNum;	// the block number of the block,
					// which indicate it when it be newed
	bool dirtyBit;     // 0 -> flase£¬ 1 -> indicate dirty, write back
	blockInfo *next;  	// the pointer point to next block 
	fileInfo *file;     	// the pointer point to the file, which the block belongs to
	int charNum;	   	// the number of chars in the block
	char *cBlock;	   	// the array space for storing the records in the block in buffer
	int iTime;		// it indicate the age of the block in use 
	int lock;			// prevent the block from replacing
};
fileInfo* get_file_info(CString DB_Name,CString fileName, int m_fileType);
blockInfo * get_file_block(CString DB_Name,CString Table_Name,int fileType,int blockNum); 
#endif
