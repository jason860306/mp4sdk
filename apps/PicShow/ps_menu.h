/***************************************************************************

		ps_menu.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-04-12 20:26:04

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _ps_menu_h_
#define _ps_menu_h_

#ifdef	__cplusplus
extern "C" {
#endif

//�˵����صĸ�������
typedef enum MENU_CMD {
	MENU_CMD_NORMAL,		//��������,����PicShow
	MENU_CMD_EXIT,			//�˳�����,return.
	MENU_CMD_REZOOM,		//������
	MENU_CMD_END
} MENU_CMD;

MENU_CMD PicShow_Menu( void );
extern KEYNAME ps_keyname[];

#ifdef __cplusplus
}
#endif

#endif
