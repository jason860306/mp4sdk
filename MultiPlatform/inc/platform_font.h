/***************************************************************************

		font.h

		No description.

		TIME LIST:
		CREATE	Rainy	2008-10-17 21:59:25

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _font_h_
#define _font_h_

#ifdef		__cplusplus
extern "C" {
#endif

typedef struct XFONT_INFO {
	int bitmap_width;
	int bitmap_height;
	int bitmap_left;
	int bitmap_top;
	int font_width;
} XFONT_INFO;

typedef struct STRING_INFO{
	s32 width;
	s32 height;
	s32 length;
} STRING_INFO;

typedef enum XFONT_CODE_PAGE {
	XFONT_CP_DEFAULT = 0,		//ʹ�����ֵ�����ó�ʼ��ʱ�趨��Ĭ�ϲ���
	XFONT_CP_437 = 437,
	XFONT_CP_874 = 874,
	XFONT_CP_932 = 932,
	XFONT_CP_936 = 936,
	XFONT_CP_949 = 949,
	XFONT_CP_950 = 950,
	XFONT_CP_1250 = 1250,
	XFONT_CP_1251 = 1251,
	XFONT_CP_1253 = 1253,
	XFONT_CP_1254 = 1254,
	XFONT_CP_1256 = 1256,
	XFONT_CP_MAX
} XFONT_CODE_PAGE;

int textout_init( char * fname, int size, int line_height, int word_spacing, int style, XFONT_CODE_PAGE codepage );
int textout_deinit( void );

STRING_INFO* textout( const char *str, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO* textout_line( const char *str, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextout_line( u32 * buf, int bufwidth, int bufheight, const char *string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextout( u32 *buf, int bufwidth, int bufheight, const char * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );

STRING_INFO* textoutW( const wchar_t *str, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO* textoutW_line( const wchar_t *str, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextoutW_line( u32 * buf, int bufwidth, int bufheight, const wchar_t *string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextoutW( u32 *buf, int bufwidth, int bufheight, const wchar_t * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );

STRING_INFO * mtextout16_line( u16 * buf, int bufwidth, int bufheight, const char *string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextout16( u16 *buf, int bufwidth, int bufheight, const char * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );

STRING_INFO * mtextoutW16_line( u16 * buf, int bufwidth, int bufheight, const wchar_t *string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextoutW16( u16 *buf, int bufwidth, int bufheight, const wchar_t * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );

STRING_INFO * mtextout555( u16 *buf, int bufwidth, int bufheight, const char * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );
STRING_INFO * mtextoutW555( u16 *buf, int bufwidth, int bufheight, const wchar_t * string, int min_x, int min_y, int max_x, int max_y, unsigned int fontcolor, unsigned int bgcolor );

enum{
	XFONT_STYLE_NORMAL   =  0x0,
	XFONT_STYLE_BOLD     =  0x1,
	XFONT_STYLE_ITALIC   =  0x2,
};


typedef struct XFONT XFONT;

typedef enum XFONT_BLEND_MODE {
	XFONT_BLEND_MODE_COVER,		//ָ����ɫ����
	XFONT_BLEND_MODE_ALPHA,		//��ԭ�������
} XFONT_BLEND_MODE;

XFONT * xfont_open( const char * path );
int xfont_uread( XFONT * xfont, int code, int size, int style, u8 * buf, int limit, XFONT_INFO * info );
void xfont_close( XFONT * xfont );
void xfont_udraw( XFONT * xfont, int code, int size, int style, u32 color, u32 bgcolor, COLOR_MODE color_mode, XFONT_BLEND_MODE blending_mode,
 int startx, int starty, int pitch,
 void * buf, int * width, int * height, int limit );
int xfont_getsize( XFONT * xfont, int code, int size, int style, XFONT_INFO * info );
const char * xfont_name( XFONT * xfont );

//����/ж�����õ�cacheϵͳ
int xfont_cache_init( void );
int xfont_cache_deinit( void );

#ifdef __cplusplus
}
#endif

#endif

/***************************************************************************

		font_nls.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-04-24 22:04:25

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _font_nls_h_
#define _font_nls_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct NLS_FILE_NAME {
	XFONT_CODE_PAGE code_page;
	char * fname;
} NLS_FILE_NAME;

typedef struct XFONT_NLS XFONT_NLS;
int xfont_nls_close( XFONT_NLS * hnls );
XFONT_NLS * xfont_nls_open( XFONT_CODE_PAGE code_page );
u16 xfont_nls_a2u( XFONT_NLS * hnls, u16 achar );
u16 xfont_nls_u2a( XFONT_NLS * hnls, u16 uchar );

#ifdef __cplusplus
}
#endif

#endif
/***************************************************************************

		textout.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-12-26 17:39:05

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.

***************************************************************************/
#ifndef _textout_h_
#define _textout_h_

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif
