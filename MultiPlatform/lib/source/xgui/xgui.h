/***************************************************************************

		xgui.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-02-09 11:47:28

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _xgui_h_
#define _xgui_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef int ERRCODE;
#define XGUI_COLOR u32
#define XGUI_MAXNAME 256

enum{
	XGUI_KEY_NUM_0 = 0x1,
	XGUI_KEY_NUM_1 = 0x2,
	XGUI_KEY_NUM_2 = 0x4,
	XGUI_KEY_NUM_3 = 0x8,
	XGUI_KEY_NUM_4 = 0x10,
	XGUI_KEY_NUM_5 = 0x20,
	XGUI_KEY_NUM_6 = 0x40,
	XGUI_KEY_NUM_7 = 0x80,
	XGUI_KEY_NUM_8 = 0x100,
	XGUI_KEY_NUM_9 = 0x200,
};

enum{
	XGUI_KEY_WORD_A = 0x1,
	XGUI_KEY_WORD_B = 0x2,
	XGUI_KEY_WORD_C = 0x4,
	XGUI_KEY_WORD_D = 0x8,
	XGUI_KEY_WORD_E = 0x10,
	XGUI_KEY_WORD_F = 0x20,
	XGUI_KEY_WORD_G = 0x40,
	XGUI_KEY_WORD_H = 0x80,
	XGUI_KEY_WORD_I = 0x100,
	XGUI_KEY_WORD_J = 0x200,
};

enum{
	XGUI_KEY_FUNC_UP = 0x1,
	XGUI_KEY_FUNC_DOWN = 0x2,
	XGUI_KEY_FUNC_LEFT = 0x4,
	XGUI_KEY_FUNC_RIGHT = 0x8,
	XGUI_KEY_FUNC_ENTER = 0x10,
	XGUI_KEY_FUNC_CTRL = 0x20,
	XGUI_KEY_FUNC_SHIFT = 0x40,
	XGUI_KEY_FUNC_ALT = 0x80,
	XGUI_KEY_FUNC_ESC  = 0x100,
};

typedef struct XGUI_KEYDATA{
	u32 word;				//��ĸ
	u32 numsym;			//���ֺͷ���
	u32 func;				//���ܼ�
	u32 other;			//����
} XGUI_KEYDATA;

enum{
	XGUI_MSG_KEYDOWN,
	XGUI_MSG_DRAW,
	XGUI_MSG_INIT,
	XGUI_MSG_DESTROY,
};

enum{
	ERRCODE_NONE = 0,
	ERRCODE_MALLOC,
	ERRCODE_NOTPREPARE,
	ERRCODE_RECALL,
	ERRCODE_PARAM,
	ERRCODE_OPEN,
};

typedef struct XGUI_MSG{
	int type;
	void * data;
} XGUI_MSG;

typedef struct XGUI_RECT{
  int left; 
  int top; 
  int right; 
  int bottom; 
} XGUI_RECT;

typedef struct XGUI_IMAGE{
	int width;
	int height;
	u8 *data;
} XGUI_IMAGE;

typedef struct XGUI_WND{
	XGUI_RECT rect;
	XGUI_RECT inval;
	wchar_t name[XGUI_MAXNAME];
	ERRCODE (* CallBack)( struct XGUI_WND * hWnd , XGUI_MSG * msg );
	void *param;
	u32 status;
	struct XGUI_WND * prev;
	struct XGUI_WND * next;
	struct XGUI_WND * parent;
	struct XGUI_WND * child;
} XGUI_WND, *XGUI_HWND;

void XGUI_TEST( void );

ERRCODE XGUI_Init( ERRCODE (* RootCallBack)( struct XGUI_WND * hWnd , XGUI_MSG * msg ) );

ERRCODE XGUI_DeInit( void );

//��������
XGUI_WND * XGUI_CreateWindow( char *name ,
 int x, int y, int width, int height, XGUI_WND * parent,
 ERRCODE (* CallBack)( XGUI_WND * hWnd , XGUI_MSG * msg ), void *param  );
 
//���ٴ���
ERRCODE XGUI_DestroyWindow( XGUI_WND * hWnd );

//ת���������굽��������
void XGUI_RectConv_Abs2Wnd( XGUI_RECT * abs, XGUI_RECT * wnd, XGUI_WND * hWnd );

//��ȡָ�����ھ���
XGUI_RECT * XGUI_GetWndRect( XGUI_WND * hWnd );

//��ȡ���ڸ߶�
int XGUI_GetWndHeight( XGUI_WND * hWnd );

//��ȡ���ڿ��
int XGUI_GetWndWidth( XGUI_WND * hWnd );

//��ȡ�����Զ������
void * XGUI_GetWndUsrParam( XGUI_WND * hWnd );

//��ȡ���洰����ʵ���
XGUI_WND * XGUI_GetDesktop( void );

//���ô����Զ������
void XGUI_SetWndUsrParam( XGUI_WND * hWnd, void *param );

//����������ʾģʽ
ERRCODE XGUI_SetScreenMode( int width, int height, int mode );

//���봰��ѭ��
ERRCODE XGUI_WindowsManager( void );

//������(֧��Alpha����)
void XGUI_RectFill( XGUI_WND * hWnd, XGUI_RECT *rect, XGUI_COLOR color );

//���ô�����Ч(���ػ�)
ERRCODE XGUI_SetWndInval( XGUI_WND * hWnd );

//�뿪GUIѭ��,�������ͷ���Դ
ERRCODE XGUI_Leave( void );

//���ý��㴰��
ERRCODE XGUI_SetFocusWnd( XGUI_WND * hWnd );

#ifdef __cplusplus
}
#endif

#endif
