/***************************************************************************

		platform_data.h

		ƽ̨������������.

		TIME LIST:
		CREATE	Rainy	2009-05-02 17:07:14

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _platform_data_h_
#define _platform_data_h_

#ifdef	__cplusplus
extern "C" {
#endif

//Font�������
extern char xfont_nls_path[ MAX_PATH ];		//�������ת����Ŀ¼
extern char xfont_fonts_path[ MAX_PATH ];		//����Ŀ¼
extern char xfont_default_font[ MAX_PATH ];		//Ĭ��GUI�����ļ�·��
extern XFONT_CODE_PAGE xfont_default_codepage;	//Ĭ��GUI�������ҳ
extern int xfont_cache_memory_size;			//xfont���õ�cacheռ���ڴ��С
extern int xfont_cache_font_max_size;					//xfont���õ�cache��������С
extern NLS_FILE_NAME * nls_fname;   //ȫ��NLS�ļ����б�

//GUI�������
extern int gui_default_line_height;		//Ĭ�ϵ��и�
extern int gui_default_font_size;		//Ĭ�ϵ������С

#ifdef __cplusplus
}
#endif

#endif
