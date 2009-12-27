/***************************************************************************

		system.h

		��ǽӿڶ����ļ�.
		�ϲ�:�������
		�²�:ƽ̨�ӿڲ�

		TIME LIST:
		CREATE	Rainy	2008-10-17 22:06:47

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _system_h_
#define _system_h_

#ifdef		__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "platform_types.h"
#include <time.h>
//----------------------------------------------------------------------------
//������Ļģʽ
//����0 --ʧ��(��֧�ֵ�ɫ��ģʽ���߿�ȸ߶�)
//����1 --���óɹ�
//��Ļɫ��ѡ��
typedef enum COLOR_MODE{
	LCD_A8R8G8B8,
	LCD_R5G6B5,
	LCD_A1R5G5B5,
	COLOR_MODE_MAX
} COLOR_MODE;
s32 screen_set_mode( u32 width, u32 height, u32 colormode );
//������Ļ���
u32 screen_get_width( void );
//������Ļ�߶�
u32 screen_get_height( void );

//������Ļ����(����0--�ɹ�(��Χ0~100))
int screen_set_backlight( int value );

//������Ļ
void lcd_updateui( void );
//��ջ���
void lcd_clearui( u32 color );
//����32λ����
u32* lcd_bufferui( void );
//----------------------------------------------------------------------------
//ϵͳ��ʱ(����)
void sys_delay( u32 time );
//ִ��ϵͳ����
void sys_event( void );
//----------------------------------------------------------------------------
//��ȡ����
u32 sys_get_key( void );
//��ȡ��λ�豸
//����0--�ɹ� ����--ʧ��
#define POINTER_PRESS_MAX 255
#define POINTER_PRESS_MIN 0
int sys_get_pointer( int *x, int *y, int *press );
//����һ����0�����İ�����(ÿ�����ʾ��Ӧ�İ���������)
u16 *sys_key_state( void );
//----------------------------------------------------------------------------
//����ϵͳ����
void sys_volume( int volume );
//��ȡϵͳ����(����)
u32 sys_ticks( void );
//�����豸��ʼ��
s32 sys_sound_init( u32 freq , u32 bit , u32 channel );
//�����豸ж��
void sys_sound_deinit( void );
//���������豸��ʼ��
s32 sys_wavein_init( u32 freq , u32 bit , u32 channel );
//���������豸ж��
void sys_wavein_deinit( void );
//д��������
u32 sys_sound_write( void *data , u32 length );
//����������
u32 sys_wavein_read( void *data, u32 length );
//��������豸�Ƿ��д
s32 sys_sound_canwrite( void );
//ϵͳ��ʼ��
s32 sys_init( void );
//����Ŀ¼,����0--�ɹ� -1--ʧ��
int sys_mkdir( char *path );
//-------------------------------------------------------------------------
//File Find Functions(�ļ����ҽṹ)
typedef struct FILE_FIND_BLOCK{
	u32 attrib;
	u8* name;
	u32 size;
	time_t time_create;
	time_t time_write;
	time_t time_access;
	void *usrdat1;
	void *usrdat2;
	void *usrdat3;
	void *usrdat4;
} FILE_FIND_BLOCK;

typedef enum {
	FFD_READONLY = 0x1,
	FFD_WRITE = 0x2,
	FFD_SYSTEM = 0x4,
	FFD_HIDDEN = 0x8,
	FFD_VOLUME = 0x10,
	FFD_DIR = 0x20,
	FFD_ARCHIVE = 0x40,
	FFD_DIR_OR = 0x80,
	FFD_UNKNOW = 0x40000000,
	FFD_ALL = 0x4FFFFFFF,
	FFD_MAX
} FILE_ATTRIB;

//��һ�������ļ��Ĺ���
FILE_FIND_BLOCK *find_open( const u8 *path );
//�رղ����ļ�����
void find_close( FILE_FIND_BLOCK *block );
//������һ���ļ�
int find_next( FILE_FIND_BLOCK *block );
//-------------------------------------------------------------------------
#ifndef MAX_PATH
#define MAX_PATH 1024
#endif
//----------------------------·��������ӿ�-------------------------------
//��ȡ�����в���( argc -- ��������, argv -- ����ָ������ ,maxargc--�����ղ�������)
//argc == 0 -- �޲���
void sys_get_arg( int *argc,char *argv[] , int maxargc );
//��ȡ��ǰĿ¼
//����buf--�ɹ�,·���洢��buf��,����NULL--ʧ��
u8 *sys_get_dir( u8 *buf , int maxlen );
//��ȡӦ�ó�����·��
//����buf--�ɹ�,·���洢��buf��,����NULL--ʧ��
u8 *sys_get_path( u8 *buf , int maxlen );
//ע��֧�ֵ��ļ�����
u8 * sys_reg_filetype( void );

//---------------------------�߳̽ӿ�---------------------------------------

typedef enum SYS_THREAD_STATUS {	//�߳�״̬
	SYS_THREAD_STATUS_STANDBY,		//����״̬
	SYS_THREAD_STATUS_RUN,			//����״̬
	SYS_THREAD_STATUS_MAX
} SYS_THREAD_STATUS;

typedef struct SYS_THREAD SYS_THREAD;			//�̶߳���
extern int sys_thread_proc( void * param, SYS_THREAD * thread );	//�߳�ԭ��

//�����߳�(stack_size ջ����, sys_thread_proc �̺߳���, param �̲߳���, status �̳߳�ʼ״̬
SYS_THREAD * sys_create_thread( int stack_size, int (*sys_thread_proc)( void * param, SYS_THREAD * thread ), void * param, SYS_THREAD_STATUS status );
//�ر��߳�(����0�ɹ�)
int sys_delete_thread( SYS_THREAD * pThread );
//�����߳�
int sys_suspend_thread( SYS_THREAD * pThread );
//�ָ��߳�
int sys_resume_thread( SYS_THREAD * pThread );

/* �����߳����ȼ�
 */
typedef enum{
	PRIO_TYPE_IDLE,
	PRIO_TYPE_LOWEST,
	PRIO_TYPE_BELOW_NORMAL,
	PRIO_TYPE_NORMAL,
	PRIO_TYPE_ABOVE_NORMAL,
	PRIO_TYPE_HIGHEST,
	PRIO_TYPE_REALTIME,
	PRIO_TYPE_MAX
} PRIO_TYPE;

int sys_priority_thread( SYS_THREAD * pThread, PRIO_TYPE prio );

//----------------------------------------------------------------------------------
#define max(a, b)  (((a) > (b)) ? (a) : (b)) 
#define min(a, b)  (((a) < (b)) ? (a) : (b)) 

#ifdef __cplusplus
}
#endif

#endif

