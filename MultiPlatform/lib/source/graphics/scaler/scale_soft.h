/***************************************************************************

		scale_soft.h

		defalut.

		TIME LIST:
		CREATE	Rainy	2009-07-24 12:16:45

		Copyright (c)  ChinaChip 2007-2009
***************************************************************************/
#ifndef _scale_soft_h_
#define _scale_soft_h_

#ifdef	__cplusplus
extern "C" {
#endif

/* RGB565ģʽ��������Сͼ��һ��(2x֮��)
 * sw Դ��� dw Ŀ����
 * sh Դ�߶� dh Ŀ��߶�
 * scanline  ��ǰ���ŵ�Ŀ��ɨ����
 * dst Ŀ���ַ
 * src Դ��ַ(���ŵĵ�ǰ�е�ַ)
 * Դ�߶�����������
 * rgb32_rgb565_scale_line rgb32��ʽתrgb565����
 * rgb565_rgb565_scale_line rgb565��ʽתrgb565����
 */
// void rgb32_rgb565_scale_line( u16 * dst, u32 * src, int sw, int dw, int sh, int dh, int scanline );
void rgb32_rgb32_scale_line( u32 * dst, u32 * src, int sw, int dw, int sh, int dh, int scanline );
/*
void rgb565_rgb565_scale_line( u16 * dst, u16 * src, int sw, int dw, int sh, int dh, int scanline );
void rgb32_yuv422_scale_line( u8 * y, u8 * u, u8 *v, u32 * src, int sw, int dw, int sh, int dh, int scanline );
void rgb565_yuv422_scale_line( u8 * y, u8 * u, u8 *v, u16 * src, int sw, int dw, int sh, int dh, int scanline );
*/
/*
 * �Ŵ�ͼ��һ��, src������2��,dst���һ��, h_weight/dh == ��һ�е�Ȩ��
 */
/*
void rgb32_rgb565_normal_vertical_blowup( u32 * src, u16 * dst, int sw, int h_weight, int dh );
void rgb32_rgb565_rotate90_vertical_blowup( u32 * src, u16 * dst, int sw, int h_weight, int dh, int fbw );

void rgb32_rgb32_normal_horizontal_blowup( u32 * buf, u32 * src, int sw, int dw );
*/

void rgb32_rgb32_blowup_line( u32 * buf, u32 * src, int sw, int dw, int sh, int dh, int scanline );

#ifdef __cplusplus
}
#endif

#endif
