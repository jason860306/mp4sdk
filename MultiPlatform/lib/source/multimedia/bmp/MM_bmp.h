/***************************************************************************

		MM_bmp.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-02-25 20:53:55

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _MM_bmp_h_
#define _MM_bmp_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct MM_IMAGE_BMP MM_IMAGE_BMP;

//Microsoft BMP File
MM_IMAGE_BMP * MM_bmp_open( u8 *path );
//����1--��ȡʧ��, ����0--�ɹ�
int MM_bmp_read( MM_IMAGE_BMP * bmp, void *buf, int width, int height );
int MM_bmp_readline	( MM_IMAGE_BMP * bmp, void *buf, int scanline );
//�ر�bmp�ļ�,����ֵ0:�ɹ� -1ʧ��
void MM_bmp_close( MM_IMAGE_BMP *bmp );
//��ȡͼƬ��С
//���ط�0--��ȡʧ��, ����0--�ɹ�
int MM_bmp_size( MM_IMAGE_BMP * bmp, int * width, int * height  );

#ifdef __cplusplus
}
#endif

#endif
