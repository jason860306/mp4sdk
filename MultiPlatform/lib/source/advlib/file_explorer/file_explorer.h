/***************************************************************************

		file_explorer.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-04-14 21:08:19

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _file_explorer_h_
#define _file_explorer_h_

#ifdef	__cplusplus
extern "C" {
#endif

/*
file_explorer_openfile
һ���򵥵Ĺ����򿪶Ի���,����֮�󽫴�һ�����ļ��ĶԻ���,
���û�ѡ����Ҫ�򿪵��ļ�,ʹ��ANSI����

char * path			��ʼ��ַ
char * filter		������ʽƥ���ļ�(����,�����ļ�ʹ��".*")
char * return_path	���صĵ�ַ,�����ʹ��MAX_PATH��С��char������

���path��������������ļ�·��,��������˼���ȴ�����Ŀ¼,�ٶ�λ��굽�ļ���
*/
int file_explorer_openfile( char * path, char * filter,char * return_path, const char * custom_msg );

/*
�ûص��ķ�ʽ���ļ�,���û�ѡ���ļ���,�ص������ͱ�����,������������ͬfile_explorer_openfile
int (*func)(char *path)
path���û�ѡ�����ļ�·��
����ֵ0----��������ļ�
      1----�˳��ļ����
*/
int file_explorer_openfile_shell( char * path, char * filter,char * return_path, const char * custom_msg, int (*func)(char *path) );


#ifdef __cplusplus
}
#endif

#endif
