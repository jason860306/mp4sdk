/***************************************************************************

		miniio.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-01-28 12:31:05

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _miniio_h_
#define _miniio_h_

#ifdef	__cplusplus
extern "C" {
#endif

//��printf����,�����ui����
void ui_printf( const char *format ,...);
//�ɶ�λ�����dprintf
void lprintf( u32 x, u32 y ,const char *format ,...);
//�ɶ�λ�����printf, ���Զ���䱳��ɫ
void loc_printf( u32 x, u32 y ,const char *format ,...);
//���debug��Ļ,����printf���긴λ
void DbgCon_Cls( void );
//��printf���긴λ
void DbgCon_Reset( void );
//����debug����ɫ��
void DbgCon_SetColor( u32 font, u32 bg );

#ifdef __cplusplus
}
#endif

#endif

