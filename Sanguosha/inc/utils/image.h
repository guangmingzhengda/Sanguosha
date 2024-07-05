// image.h

#include <easyx.h>

void PutAlphaImage(int x, int y, IMAGE* pSrcImage);
void PutAlphaImage(IMAGE* pDstImage, int x, int y, IMAGE* pSrcImage);

// Parse R, G, B in a color.
#define PA(color) (((color) & 0xFF000000) >> 24)
#define PB(color) (((color) & 0x00FF0000) >> 16)
#define PG(color) (((color) & 0x0000FF00) >> 8)
#define PR(color) (((color) & 0x000000FF))

/********************************************************************
** Get the "alpha-ed" color.
**   s: Color of the source image.
**   d: Color of the destination image.
**   a: Alpha value.
*/
#define ARGB(s, d, a) RGB((PR(s) * a + PR(d) * (255 - a)) >> 8, (PG(s) * a + PG(d) * (255 - a)) >> 8, (PB(s) * a + PB(d) * (255 - a)) >> 8)