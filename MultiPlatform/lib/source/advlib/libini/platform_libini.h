/***************************************************************************

		platform_libini.h

		INI�ļ���д.

		TIME LIST:
		CREATE	Rainy	2009-05-01 21:07:04

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _platform_libini_h_
#define _platform_libini_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct INI_FILE INI_FILE;

int ini_file_test( void );

//INI�ļ��򿪷�ʽ
typedef enum INI_OPEN_MODE{	
	INI_OPEN_MODE_READ,			//ֻ����,�ļ������ڻ᷵�ش�����
	INI_OPEN_MODE_WRITE,		//��д��,�ļ������ڻ��Զ�����,��ԭ���ݱ����
	INI_OPEN_MODE_RW,			//��д��,�ļ������ڻ��Զ�����,����ԭ����
	INI_OPEN_MODE_END
}INI_OPEN_MODE;

//���µ�INI����,����ֵΪ0��ʾ�ɹ�,����ֵΪʧ��
//section:         INI������
//key:             INI������
//val:             INI��ֵ

//��һ��INI�ļ�
INI_FILE * ini_file_open( const char * path, INI_OPEN_MODE mode );
//�ر�һ��INI�ļ�
int ini_file_close( INI_FILE * ini_file );
//��ȡINI�ļ��е�һ���ַ���
int ini_file_read_string( INI_FILE * ini_file, const char * section, const char * key, char * val, int maxlen );
//��ȡINI�ļ��е�int����
int ini_file_read_int( INI_FILE * ini_file, const char * section, const char * key, int * val );
//��ȡINI�ļ��е�unsigned int����
int ini_file_read_uint( INI_FILE * ini_file, const char * section, const char * key, int * val );
//��ȡINI�ļ��е�double����
int ini_file_read_double( INI_FILE * ini_file, const char * section, const char * key, double * val );
//дINI�ļ��ַ�������
int ini_file_write_string( INI_FILE * ini_file, const char * section, const char * key, const char * val );
//дINI�ļ�int����
int ini_file_write_int( INI_FILE * ini_file, const char * section, const char * key, int val );
//дINI�ļ�unsigned int����
int ini_file_write_uint( INI_FILE * ini_file, const char * section, const char * key, unsigned int val );
//дINI�ļ�double����
int ini_file_write_double( INI_FILE * ini_file, const char * section, const char * key, double val );

#ifdef __cplusplus
}
#endif

#endif
