/***************************************************************************

		regexp.h

 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.

		TIME LIST:
		CREATE	Rainy	2009-04-15 21:13:40

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _regexp_h_
#define _regexp_h_

#ifdef	__cplusplus
extern "C" {
#endif

#define NSUBEXP  10
typedef struct regexp {
	char *startp[NSUBEXP];
	char *endp[NSUBEXP];
	char regstart;		/* Internal use only. */
	char reganch;		/* Internal use only. */
	char *regmust;		/* Internal use only. */
	int regmlen;		/* Internal use only. */
	char program[1];	/* Unwarranted chumminess with compiler. */
} regexp;

extern regexp *regcomp(const char *re);
extern int regexec(regexp *rp, const char *s);
extern void regsub(const regexp *rp, const char *src, char *dst);
extern void regerror(char *message);
extern void regfree(regexp *rp);

#ifdef __cplusplus
}
#endif

#endif


/***************************************************************************

		advkey.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-04-15 21:16:20

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _advkey_h_
#define _advkey_h_

#ifdef	__cplusplus
extern "C" {
#endif

//�˵�����
//���ؼ�ֵ,�ص��ǳ������°������Զ�����
u32 menu_get_key();

#ifdef __cplusplus
}
#endif

#endif
/***************************************************************************

		file_list.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-03-18 21:40:27

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _file_list_h_
#define _file_list_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct FILE_LIST FILE_LIST;

typedef enum {
	FILE_LIST_SORT_NAME,
	FILE_LIST_SORT_SIZE,
	FILE_LIST_SORT_TIME_CREATE,
	FILE_LIST_SORT_TIME_ACCESS,
	FILE_LIST_SORT_TIME_WRITE,
	FILE_LIST_SORT_DIR,
	FILE_LIST_SORT_MAX
} FILE_LIST_SORT;

typedef struct FILE_LIST_DATA{
	char fname[MAX_PATH];
	FILE_ATTRIB attrib;
	u32 size;
	time_t time_create;
	time_t time_write;
	time_t time_access;
} FILE_LIST_DATA;

void file_list_test( void );
FILE_LIST * file_list_open( const char * path, const char * pattern, FILE_ATTRIB attrib );
void file_list_sort( FILE_LIST * hlist, FILE_LIST_SORT sort );
void file_list_close( FILE_LIST * hlist );
FILE_LIST_DATA * file_list_read( FILE_LIST * hlist, int index );
int file_list_count( FILE_LIST * hlist );
int file_list_index( FILE_LIST * hlist, const char * fname );

#ifdef __cplusplus
}
#endif

#endif
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
/***************************************************************************

		platform_config.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-05-02 13:35:01

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _platform_config_h_
#define _platform_config_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum VALUE_TYPE {
	VALUE_TYPE_STRING,
	VALUE_TYPE_INT,
	VALUE_TYPE_UINT,
	VALUE_TYPE_DOUBLE,
	VALUE_TYPE_END
} VALUE_TYPE;

typedef struct CONFIG_LIST {
	char * section;
	char * key;
	int type;
	void * value;
} CONFIG_LIST;

typedef struct CONFIG_KEYS_LIST {
    VALUE_TYPE type;
    const char * key;
    void * value;
} CONFIG_KEYS_LIST;

int platform_config_load( const char * ini_path, CONFIG_LIST config_list[] );
int platform_config_save( const char * ini_path, CONFIG_LIST config_list[] );
int platform_load_keymap( const char * section, const char * ini_path, KEYMAP * keymap, KEYNAME * keyname );
int platform_save_keymap( const char * section, const char * ini_path, KEYMAP * keymap, KEYNAME * keyname );
int config_load_keys( INI_FILE * ini, const char * section, CONFIG_KEYS_LIST * config_list );
int config_save_keys( INI_FILE * ini, const char * section, CONFIG_KEYS_LIST * config_list );
int config_save_keymap( INI_FILE * ini, const char * section, KEYMAP * keymap, KEYNAME * keyname );
int config_load_keymap( INI_FILE * ini, const char * section, KEYMAP * keymap, KEYNAME * keyname );
int ini_config_save( INI_FILE * ini, CONFIG_LIST config_list[] );
int ini_config_load( INI_FILE * ini, CONFIG_LIST config_list[] );

#ifdef __cplusplus
}
#endif

#endif
