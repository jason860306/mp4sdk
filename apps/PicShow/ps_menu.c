/***************************************************************************

		ps_menu.c

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-04-12 20:26:01

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/

#include "ps_common.h"

static MENU_CMD menu_cmd;

static MENU_STATE menu_zoom_fit_height( void * param )
{
	current_zoom_mode = ZOOM_MODE_HEIGHT;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_zoom_fit_width( void * param )
{
	current_zoom_mode = ZOOM_MODE_WIDTH;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_zoom_fit_origin( void * param )
{
	current_zoom_mode = ZOOM_MODE_ORIGIN;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_zoom_fit_50p( void * param )
{
	current_zoom_mode = ZOOM_MODE_50;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_zoom_fit_25p( void * param )
{
	current_zoom_mode = ZOOM_MODE_25;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_zoom_fit_12p( void * param )
{
	current_zoom_mode = ZOOM_MODE_12_5;
	menu_cmd = MENU_CMD_REZOOM;
	return MENU_STATE_EXIT;
}

PICSHOW_MENU zoom_rate_menu[] = {
{		"�߶���Ӧ",			menu_zoom_fit_height		,NULL		},
{		"�����Ӧ",			menu_zoom_fit_width			,NULL		},
{		"ԭʼ��С",			menu_zoom_fit_origin		,NULL		},
{		"50%",				menu_zoom_fit_50p			,NULL		},
{		"25%",				menu_zoom_fit_25p			,NULL		},
{		"%12.5",			menu_zoom_fit_12p			,NULL		},
{		NULL,				NULL			,NULL		},
};

static MENU_STATE menu_zoom_set_default( void * param )
{
	default_zoom_mode = current_zoom_mode;
	return MENU_STATE_EXIT;
}

PICSHOW_MENU zoom_menu[] = {
{		"���ű���>>",			NULL		,zoom_rate_menu		},
{		"��ΪĬ�����ŷ�ʽ",			menu_zoom_set_default			,NULL		},
{		NULL,				NULL			,NULL		},
};

static MENU_STATE menu_slip_enable( void * param )
{
	use_slip_key = 1;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_slip_disable( void * param )
{
	use_slip_key = 0;
	return MENU_STATE_EXIT;
}

KEYNAME ps_keyname[] = {
{	"UP",PSKEY_UP				},
{	"DOWN",PSKEY_DOWN			},	
{	"LEFT",PSKEY_LEFT			},
{	"RIGHT",PSKEY_RIGHT			},
{	"PAGE UP",PSKEY_PAGE_UP				},
{	"PAGE DOWN",PSKEY_PAGE_DOWN			},	
{	"PAGE LEFT",PSKEY_PAGE_LEFT			},
{	"PAGE RIGHT",PSKEY_PAGE_RIGHT			},
{	"ZOOMIN",PSKEY_ZOOMIN			},
{	"ZOOMOUT",PSKEY_ZOOMOUT			},
{	"PREV",PSKEY_PREV			},
{	"NEXT",PSKEY_NEXT			},
{	"EXIT",PSKEY_EXIT			},
{	"ZOOM STEP",PSKEY_ZOOM_STEP			},
{	"FIT WIDTH",PSKEY_ZOOM_TYPE_WIDTH			},
{	"FIT HEIGHT",PSKEY_ZOOM_TYPE_HEIGHT			},
{	"Origin",PSKEY_ZOOM_TYPE_ORIGIN			},
{	"Menu",PSKEY_MENU			},
{	NULL, 0			}
};

KEYNAME sys_keyname[] = {
{	"UP"	,			SYSKEY_UP				},
{	"DOWN"	,		SYSKEY_DOWN		  },
{	"LEFT"	,		SYSKEY_LEFT		  },
{	"RIGHT",		SYSKEY_RIGHT	  },
{	"A",				SYSKEY_A			  },
{	"B",				SYSKEY_B			  },
{	"C",				SYSKEY_C			  },
{	"D",				SYSKEY_D			  },
{	"SELECT"	,	SYSKEY_SELECT	  },
{	"START",		SYSKEY_START	  },
{	"L",				SYSKEY_L			  },
{	"R",				SYSKEY_R			  },
{	"MENU"	,		SYSKEY_MENU		  },
{	"VOLUP",		SYSKEY_VOLUP	  },
{	"VOLDOWN",	SYSKEY_VOLDOWN  },
{	"POWER",		SYSKEY_POWER	  },
{	"ESCAPE"	,	SYSKEY_ESCAPE	  },
{	"E",				SYSKEY_E			  },
{	"F",				SYSKEY_F			  },
{	"SAVE"	,		SYSKEY_SAVE		  },
{	"LOAD"	,		SYSKEY_LOAD		  },
{	NULL,							0							  }
};

static MENU_STATE menu_keyset_right0( void * param )
{
	XGUI_KeySet( pskeymap_right0, sys_keyname, ps_keyname, "Key Setting" );
	return MENU_STATE_CONTINUE;
}

static MENU_STATE menu_keyset_right90( void * param )
{
	XGUI_KeySet( pskeymap_right90, sys_keyname, ps_keyname, "Key Setting" );
	return MENU_STATE_CONTINUE;
}

static MENU_STATE menu_keyset_right180( void * param )
{
	XGUI_KeySet( pskeymap_right180, sys_keyname, ps_keyname, "Key Setting" );
	return MENU_STATE_CONTINUE;
}

static MENU_STATE menu_keyset_right270( void * param )
{
	XGUI_KeySet( pskeymap_right270, sys_keyname, ps_keyname, "Key Setting" );
	return MENU_STATE_CONTINUE;
}

PICSHOW_MENU keyset_menu[] = {
{		"��������",			menu_keyset_right0		,NULL		},
{		"��ת90�Ȱ���",		menu_keyset_right90		,NULL		},
{		"��ת180�Ȱ���",	menu_keyset_right180	,NULL		},
{		"��ת270�Ȱ���",	menu_keyset_right270	,NULL		},
{		NULL,				NULL			,NULL		},
};

static MENU_STATE menu_set_dir( void * param )
{
	strcpy( PicDir, CurrDir );
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_preview_enable( void * param )
{
	load_preview = 1;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_preview_disable( void * param )
{
	load_preview = 0;
	return MENU_STATE_EXIT;
}

PICSHOW_MENU ctrl_menu[] = {
{		"�򿪻���Ч��",			menu_slip_enable		,NULL		},
{		"�رջ���Ч��",			menu_slip_disable		,NULL		},
{		"�򿪼���Ԥ��",			menu_preview_enable				,NULL		},
{		"�رռ���Ԥ��",			menu_preview_disable				,NULL		},
{		"��ΪĬ��ͼƬĿ¼",			menu_set_dir				,NULL		},
{		"��������>>",			NULL				,keyset_menu		},
{		NULL,				NULL			,NULL		},
};


static MENU_STATE menu_direction_0( void * param )
{
	PicShow_direction = BITMAP_ZOOM_RIGHT0;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_90( void * param )
{
	PicShow_direction = BITMAP_ZOOM_RIGHT90;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_180( void * param )
{
	PicShow_direction = BITMAP_ZOOM_RIGHT180;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_270( void * param )
{
	PicShow_direction = BITMAP_ZOOM_RIGHT270;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_auto90( void * param )
{
	PicShow_auto_direction = AUTO_DIRECTION_90;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_auto270( void * param )
{
	PicShow_auto_direction = AUTO_DIRECTION_270;
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_direction_same( void * param )
{
	PicShow_auto_direction = AUTO_DIRECTION_SAME;
	return MENU_STATE_EXIT;
}

PICSHOW_MENU direction_auto_menu[] = {
{		"�Զ���ת(90��)",			menu_direction_auto90		,NULL		},
{		"�Զ���ת(270��)",			menu_direction_auto270		,NULL		},
{		"����ǰһ��״̬",			menu_direction_same		,NULL		},
{		NULL,			NULL					,NULL		},
};

PICSHOW_MENU direction_menu[] = {
{		"����",			menu_direction_0		,NULL		},
{		"��ת90��",		menu_direction_90		,NULL		},
{		"��ת180��",	menu_direction_180		,NULL		},
{		"��ת270��",	menu_direction_270		,NULL		},
{		"Ĭ����ʾ��ʽ>>",	NULL		,direction_auto_menu		},
{		NULL,			NULL					,NULL		},
};

static MENU_STATE menu_back( void * param )
{
	return MENU_STATE_EXIT;
}

static MENU_STATE menu_exit( void * param )
{
	run_flag = EXIT;
	menu_cmd = MENU_CMD_EXIT;
	return MENU_STATE_EXIT;
}

PICSHOW_MENU main_menu[] = {
{		"�ص����",			menu_back		,NULL		},
{		"��������>>",		NULL			,zoom_menu	},
{		"��������>>",		NULL			,ctrl_menu	},
{		"��ʾ����>>",		NULL			,direction_menu	},
{		"�˳����",			menu_exit		,NULL		},
{		NULL,				NULL			,NULL		},
};

ERRCODE RootCallBack( struct XGUI_WND * hWnd , XGUI_MSG * msg )
{
	static u32 * bg = NULL;
	int x, y;
	
	int pitch = screen_get_width();
	
	switch( msg->type )
	{
		case XGUI_MSG_DRAW:
		{
			u32 * dst = lcd_bufferui();
			u32 * src = bg;
			int max_x = screen_get_width();
			int max_y = screen_get_height();
			
			XGUI_RECT *rect = (XGUI_RECT *)msg->data;
			if( src == NULL )
			{
				XGUI_RectFill( hWnd, rect, 0x000000 );
				break;
			}
			
			max_x = (rect->right - rect->left);
			max_y = (rect->bottom - rect->top);
			for( y = 0; y < max_y; y+=4 )
			{
				src = bg + rect->left/4 + (screen_get_width()/4) * ((rect->top+y)/4);
				//src += 
				dst = lcd_bufferui() + rect->left + screen_get_width() * (rect->top+y);
				
				for( x = 0; x < max_x; x+=4 )
				{
					dst[0] = *src;
					dst[1] = *src;
					dst[2] = *src;
					dst[3] = *src;
					dst[pitch+0] = *src;
					dst[pitch+1] = *src;
					dst[pitch+2] = *src;
					dst[pitch+3] = *src;
					dst[pitch*2+0] = *src;
					dst[pitch*2+1] = *src;
					dst[pitch*2+2] = *src;
					dst[pitch*2+3] = *src;
					dst[pitch*3+0] = *src;
					dst[pitch*3+1] = *src;
					dst[pitch*3+2] = *src;
					dst[pitch*3+3] = *src;
					dst += 4;
					src ++;
				}
				dst += pitch*3;
			}
			break;
		}
		case XGUI_MSG_INIT:
		{	//����ͼ��ʾ����
			u32 * src = lcd_bufferui();
			u32 * dst;
			int max_x = screen_get_width()/4;
			int max_y = screen_get_height()/4;
			
			bg = malloc( max_x*max_y*4 );
			if( bg == NULL )
			{
				TRACE_LOG("malloc error");
				break;
			}
			dst = bg;
			for( y = 0; y < max_y; y++ )
			{
				for( x = 0; x < max_x; x++ )
				{
					*dst =(	(src[0]&0xF0F0F0)+
							(src[1]&0xF0F0F0)+
							(src[2]&0xF0F0F0)+
							(src[3]&0xF0F0F0)+
							(src[pitch+0]&0xF0F0F0)+
							(src[pitch+1]&0xF0F0F0)+
							(src[pitch+2]&0xF0F0F0)+
							(src[pitch+3]&0xF0F0F0)+
							(src[pitch*2+0]&0xF0F0F0)+
							(src[pitch*2+1]&0xF0F0F0)+
							(src[pitch*2+2]&0xF0F0F0)+
							(src[pitch*2+3]&0xF0F0F0)+
							(src[pitch*3+0]&0xF0F0F0)+
							(src[pitch*3+1]&0xF0F0F0)+
							(src[pitch*3+2]&0xF0F0F0)+
							(src[pitch*3+3]&0xF0F0F0)
							)>>4;
					src += 4;
					dst ++;
				}
				src += pitch*3;
			}
			break;
		}
		case XGUI_MSG_DESTROY:
		{
			if(bg)
				free(bg);
			break;
		}
	}
	return ERRCODE_NONE;
}

PICSHOW_MENU_HANDLE * hMenu;

MENU_CMD PicShow_Menu( void )
{
	XGUI_Init( RootCallBack );
	hMenu = PicShow_CreateMenu( main_menu, "main menu", 0, 0, XGUI_GetDesktop() );
	XGUI_WindowsManager();
	PicShow_DestroyMenu( hMenu );
	XGUI_DeInit();
	return MENU_CMD_NORMAL;
}


