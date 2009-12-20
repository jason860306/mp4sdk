/***************************************************************************

		font_cache.c

		Ϊ�˱���cache�Ĺ��̳��ִ�������Ƭ,
		cacheģ�������ָ����С֮�ڵ�������cache.
		ÿ��block�Ĵ�С������ͬ��,����Ҳ���ڿ����滻

		TIME LIST:
		CREATE	Rainy	2009-05-02 20:22:34

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/

#include <global.h>
#include "font_cache.h"

//#define MAX_CACHE_SIZE 0x200000			//���ռ�õ��ڴ��С
//#define MAX_FONT_SIZE	32				//֧��cache����������С

typedef struct XFONT_CACHE_BLOCK{
	struct XFONT_CACHE_BLOCK * prev;
	struct XFONT_CACHE_BLOCK * next;
	int index;
	XFONT_INFO info;
	XFONT * xfont;
	int size;
	int style;
	char data[1];
} XFONT_CACHE_BLOCK;

struct XFONT_CACHE{
	int blockcount;
	int max_cache_size;
	int max_font_size;
	int used_size;
	XFONT_CACHE_BLOCK * first;
	XFONT_CACHE_BLOCK * last;
	XFONT_CACHE_BLOCK * block_index[ 0x10000 ];
};

XFONT_CACHE * xfont_cache_open( int max_cache_size, int max_font_size )
{
	int i;
	XFONT_CACHE * handle = malloc( sizeof(XFONT_CACHE) );
	if( handle == NULL ) goto err;
	handle->max_cache_size = max_cache_size;
	handle->max_font_size = max_font_size;
	handle->used_size = 0;
	handle->blockcount = 0;
	handle->last = NULL;
	handle->first = NULL;
	for( i = 0; i < 0x10000; i++ )
		handle->block_index[i] = NULL;
	return handle;
err:
	return NULL;
}

int xfont_cache_close( XFONT_CACHE * handle )
{
	int i;
	for( i = 0; i < 0x10000; i++ )
	{
		if( handle->block_index[i] )
			free( handle->block_index[i] );
	}
	free( handle );
	return 0;
}

char * xfont_cache_read( XFONT_CACHE * handle, XFONT * xfont, XFONT_INFO * info, int code, int size, int style )
{
	XFONT_CACHE_BLOCK * block = handle->block_index[code];
	if( block )				//�ѻ���,��ȡ���ҵ�����
	{
		if( block->xfont != xfont ||
			block->size != size ||
			block->style != style )
			goto err;
		#if 0
		if( handle->first != block )	//�ж϶����Ƿ��Լ�
		{
			if( block->prev )						//��ǰ���ǰ������������
				block->prev->next = block->next;
			if( block->next )
				block->next->prev = block->prev;
				
			handle->first->prev = block;	//ԭ���ױ�Ϊ�ڶ���
			
			block->prev = NULL;				//�ҽӵ�����
			block->next = handle->first;
			handle->first = block;
		}
		#endif
		memcpy( info, &block->info, sizeof(XFONT_INFO) );
		return block->data;
	}
err:
	return NULL;
}

int xfont_cache_write( XFONT_CACHE * handle, XFONT * xfont, XFONT_INFO * info, int code, int size, int style, u8 * buffer )
{
	XFONT_CACHE_BLOCK * block = NULL;
	
	if( size > handle->max_font_size )					//�ж��Ƿ���cache֧�ֵķ�Χ��
		return -1;
		
	if( handle->block_index[code] != NULL )				//��ǰ�����Ѿ�����,��ֱ�ӷ���
		return 0;
	
	if( handle->used_size < handle->max_cache_size )	//С������ڴ�,�����µĿ�,�����ڶ�β
	{
		int blocksize = sizeof(XFONT_CACHE_BLOCK) + (handle->max_font_size*handle->max_font_size) - 1;
		block = malloc( blocksize );
		if( block == NULL )
		{
			return -1;			//���޶����ڴ淶Χ�ڳ������ڴ治��,���ش���
		}
		if( handle->first == NULL )
			handle->first = block;
		handle->blockcount++;
		handle->used_size += blocksize;
		//printf( "%d\n", handle->blockcount );
	}
	else					//���������µ��ڴ�,�滻���еĿ�
	{
		block = handle->first;		//ȡ���е�һ��
		handle->first = block->next;	//�ڶ����ɶ���
		if( block->next )
			block->next->prev = NULL;	//���׵�ǰ����ΪNULL
			
		handle->block_index[block->index] = NULL;	//�ڱ��������һ��
	}
	memcpy( block->data, buffer, size*size );	//�������ݵ�����
	memcpy( &block->info, info, sizeof(XFONT_INFO) );	//����INFO������
	block->xfont = xfont;
	block->size = size;
	block->style = style;
	block->next = NULL;
	block->prev = handle->last;						//���ص���β
	if( handle->last )
		handle->last->next = block;
	handle->last = block;
	block->index = code;
	handle->block_index[code] = block;
	
	return 0;
}


