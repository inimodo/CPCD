//	     "C powered Colored Drawing"
//		  www.ucpsystems.com 2018
//		Windows only graphic library
//		    CPU based rendering
//				  V3.0.0

#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")

#define _CPCD_FULLRGB	
#define _CPCD_WINDOW				
#define _CPCD_NOBUFFER_
#define _CPCD_ONLYBUFFER
#define _CPCD_SINGLEFRAME	
#define _CPCD_SHOWCONSOL		

#define _CPCD_QUALITY		0.001F
#define _CPCD_BACKCOLOR		0

#define _CPCD_NULL			(void*)0x0
#define _CPCD_DATA_STRING	char*
#define _CPCD_DATA_DEF		short int
#define _CPCD_DATA_ULINT	unsigned long int
#define _CPCD_DATA_RAT		short int
#define _CPCD_DATA_UINT		unsigned int

#ifdef _CPCD_WINDOW

#define _CPCD_WINDOW_WINAME	"win32"
#define _CPCD_WINDOW_WIDTH	16*63
#define _CPCD_WINDOW_HEIGHT	9*63

#define _CPCD_DATA_HINTS	HINSTANCE
#define _CPCD_DATA_LPSTR	LPSTR
#define _CPCD_DATA_WPARAM	WPARAM
#define _CPCD_DATA_LPARAM	LPARAM
#define _CPCD_DATA_HWND		HWND
#define _CPCD_DATA_MSG		MSG
#define _CPCD_DATA_WNDC		WNDCLASSEX
#define _CPCD_DATA_HBRUSH	HBRUSH
#define _CPCD_DATA_HDC		HDC
#define _CPCD_DATA_COLR		COLORREF
#define _CPCD_DATA_HBITM	HBITMAP
#define _CDD_DATA_TIME		time_t

#define _CPCD_ALIASWINDOW	CPCD_WINDOW
typedef struct _CPCD_ALIASWINDOW _CPCD_ALIASWINDOW;
struct _CPCD_ALIASWINDOW {
	_CPCD_DATA_DEF	
		USI_WIDTH, 
		USI_HEIGHT, 
		USI_BACKCOLOR;
	_CPCD_DATA_STRING 
		C_WINDOWNAME;
};

#define _CPCD_MAIN_F		cdd_main
#define _CPCD_STARTUP_F		cdd_startup
#define _CPCD_END_F			cdd_end
#define _CPCD_UPDATE_F		cdd_update

#define _CPCD_UPDATE		_CPCD_DATA_DEF		_CPCD_UPDATE_F	(_CPCD_DATA_ULINT ui_frame,_CPCD_DATA_ULINT ui_time,_CPCD_DATA_MSG msg_info)
#define _CPCD_STARTUP		_CPCD_ALIASWINDOW*	_CPCD_STARTUP_F	(_CPCD_DATA_HINTS hInstance, _CPCD_DATA_HINTS hPrevInstance, _CPCD_DATA_LPSTR lpCmdLine, int nCmdShow)
#define _CPCD_MAIN		    _CPCD_DATA_DEF		_CPCD_MAIN_F	(_CPCD_DATA_HWND hwnd_handle)
#define _CPCD_END			void				_CPCD_END_F		(_CPCD_DATA_WPARAM wpr_wparam,_CPCD_DATA_ULINT ui_frame)

#endif

#define _CPCD_DM_FILLED		0x1FF
#define _CPCD_DM_OUTLINE	0x0FF

#define _CPCD_DATA_DRAWMODE CPCD_BOOL
typedef _CPCD_DATA_DEF _CPCD_DATA_DRAWMODE;

#ifdef _CPCD_FULLRGB
#define _CPCD_ALIASCOLOR	CPCD_COLOR	
#else
#define _CPCD_ALIASCOLOR _CPCD_DATA_DEF
#endif

#ifdef _CPCD_FULLRGB
typedef struct _CPCD_ALIASCOLOR _CPCD_ALIASCOLOR;
struct _CPCD_ALIASCOLOR {
	_CPCD_DATA_DEF		
		R, 
		G, 
		B;
};
#endif

#define _CPCD_ALIAS			CPCD_CANVAS
typedef struct _CPCD_ALIAS _CPCD_ALIAS;
struct _CPCD_ALIAS {
	_CPCD_ALIASCOLOR**		C_COLOR;
	_CPCD_DATA_DEF			USI_WIDTH;
	_CPCD_DATA_DEF			USI_HEIGHT;
};


#define _CPCD_ALIASVECTOR	CPCD_VECTOR
typedef struct _CPCD_ALIASVECTOR _CPCD_ALIASVECTOR;
struct _CPCD_ALIASVECTOR {
	_CPCD_DATA_DEF			X, Y;
};

#define _CPCD_LEFTUP	(_CPCD_ALIASVECTOR){0,0}
#define _CPCD_LEFTDOWN	(_CPCD_ALIASVECTOR){0,_CPCD_WINDOW_HEIGHT}
#define _CPCD_RIGHTDOWN (_CPCD_ALIASVECTOR){_CPCD_WINDOW_WIDTH,_CPCD_WINDOW_HEIGHT}
#define _CPCD_RIGHTUP	(_CPCD_ALIASVECTOR){_CPCD_WINDOW_WIDTH,0}
#define _CPCD_CENTER	(_CPCD_ALIASVECTOR){_CPCD_WINDOW_WIDTH/2,_CPCD_WINDOW_HEIGHT/2}

#define _CPCD_DM_LINE		0x22c
#define _CPCD_DM_TRI		0x33c
#define _CPCD_DM_RECT		0x44c

#define _CPCD_VECGRAPHIC	CPCD_VECTORGRAPHIC
#define _CPCD_UNIONTRANS	CPCD_TRANSFORM
#define _CPCD_UNIONLINE		CPCD_LINE

typedef struct _CPCD_VECGRAPHIC _CPCD_VECGRAPHIC;
typedef struct _CPCD_UNIONTRANS _CPCD_UNIONTRANS;
typedef struct _CPCD_UNIONLINE _CPCD_UNIONLINE;
struct _CPCD_UNIONTRANS {
	_CPCD_DATA_DEF			USI_ROTATION;
	_CPCD_ALIASVECTOR		V_POSITION;
	_CPCD_ALIASVECTOR		V_SCALE;
};
struct _CPCD_UNIONLINE {
	_CPCD_ALIASVECTOR		V_POS_ONE;
	_CPCD_ALIASVECTOR		V_POS_TWO;
	_CPCD_ALIASCOLOR		C_COLOR;
	_CPCD_DATA_DEF			USI_MODE;
	_CPCD_DATA_DEF			USI_DRAWMODE;
};
struct _CPCD_VECGRAPHIC {
	_CPCD_UNIONLINE*		L_LINES;
	_CPCD_DATA_DEF			USI_SINZE;
	_CPCD_UNIONTRANS		T_TRANSFORM;
};

#define _CPCD_SPRITE		CPCD_SPRITE
typedef struct _CPCD_SPRITE _CPCD_SPRITE;
struct _CPCD_SPRITE {
	_CPCD_ALIASCOLOR**		C_COLOR;
	_CPCD_DATA_DEF			USI_WIDTH;
	_CPCD_DATA_DEF			USI_HEIGHT;
	_CPCD_ALIASVECTOR		V_POSITION;
};

#define _CPCD_SBM_OVERRIDE	0x0CC 
#define _CPCD_SBM_COMPINE	0xCCC
#define _CPCD_SBM_BLEND		0xBCC
#define _CPCD_SBM_ADD		0xACC
#define _CPCD_C_RED			0x01C	
#define _CPCD_C_GREEN		0x02C	
#define _CPCD_C_BLUE		0x03C	
#define _CPCD_C_REDGREEN	0x12C	
#define _CPCD_C_REDBLUE		0x13C	
#define _CPCD_C_BLUEGRN		0x23C	

_CPCD_ALIAS			_CPCD_CREATE		(_CPCD_DATA_DEF		USI_WIDTH,
										_CPCD_DATA_DEF		USI_HEIGHT);

_CPCD_SPRITE		_CPCD_SPR_CREATE	(_CPCD_DATA_DEF		USI_WIDTH,
										_CPCD_DATA_DEF		USI_HEIGHT,
										_CPCD_ALIASVECTOR*	V_POSITION);

_CPCD_VECGRAPHIC	_CPCD_VG_CREATE		(_CPCD_UNIONTRANS*	T_TRANFORM);

void				_CPCD_CLEAR			(_CPCD_ALIAS*		CPCD_CANVAS);

void				_CPCD_DELETE		(_CPCD_ALIAS*		CPCD_CANVAS);

void				_CPCD_VG_PUSHLINE	(_CPCD_VECGRAPHIC *	VG_GRAPHIC,
										_CPCD_UNIONLINE		L_LINE);

void				_CPCD_DRAWBUFFER	(_CPCD_ALIAS*		CPCD_CANVAS);

void				_CPCD_VG_DRAW		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_VECGRAPHIC	VG_GRAPHIC);

void				_CPCD_CPUSHADER		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASCOLOR(*cpu_shader)
										(_CPCD_ALIASCOLOR,_CPCD_ALIASVECTOR));

void				_CPCD_DRAWSPRITE	(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_SPRITE		SPR_SPRITE,
										_CPCD_DATA_DRAWMODE	DM_MODE,
										_CPCD_DATA_DRAWMODE	DM_VALUE);

void				_CPCD_DRAWRECT		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASVECTOR	V_LEFTUPPER,
										_CPCD_ALIASVECTOR	V_RIGHTBOT,
										_CPCD_ALIASCOLOR	C_COLOR,
										_CPCD_DATA_DRAWMODE	DM_MODE);

void				_CPCD_DRAWTRI		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASVECTOR	V_ONE,
										_CPCD_ALIASVECTOR	V_TWO,
										_CPCD_ALIASVECTOR	V_THREE,
										_CPCD_ALIASCOLOR	C_COLOR,
										_CPCD_DATA_DRAWMODE	DM_MODE);

void				_CPCD_DRAWLINE		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASVECTOR	V_LEFT,
										_CPCD_ALIASVECTOR	V_RIGH,
										_CPCD_ALIASCOLOR	C_COLOR);

void				_CPCD_VG_DRAWRECT	(_CPCD_VECGRAPHIC*	VG_GRAPHIC,
										_CPCD_ALIASVECTOR	V_LEFTUPPER,
										_CPCD_ALIASVECTOR	V_RIGHTBOT,
										_CPCD_ALIASCOLOR	C_COLOR,
										_CPCD_DATA_DRAWMODE	DM_MODE);

void				_CPCD_VG_DRAWTRI	(_CPCD_VECGRAPHIC*	VG_GRAPHIC,
										_CPCD_ALIASVECTOR	V_ONE,
										_CPCD_ALIASVECTOR	V_TWO,
										_CPCD_ALIASVECTOR	V_THREE,
										_CPCD_ALIASCOLOR	C_COLOR,
										_CPCD_DATA_DRAWMODE	DM_MODE);

void				_CPCD_VG_DRAWLINE	(_CPCD_VECGRAPHIC*	VG_GRAPHIC,
										_CPCD_ALIASVECTOR	V_LEFT,
										_CPCD_ALIASVECTOR	V_RIGH,
										_CPCD_ALIASCOLOR	C_COLOR);

void				_CPCD_SETPIXEL		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASVECTOR	V_POINT,
										_CPCD_ALIASCOLOR		C_COLOR);
_CPCD_ALIASCOLOR	_CPCD_GETPIXEL		(_CPCD_ALIAS*		CPCD_CANVAS,
										_CPCD_ALIASVECTOR	V_POINT);

int					_CPCD_COLORCMP		(_CPCD_ALIASCOLOR C_ONE,
										_CPCD_ALIASCOLOR C_TWO);
_CPCD_ALIASCOLOR	_CPCD_COLORSUB		(_CPCD_ALIASCOLOR C_ONE,
										_CPCD_ALIASCOLOR C_TWO);	

_CPCD_ALIASCOLOR	_CPCD_COLORDIV		(_CPCD_ALIASCOLOR C_ONE,
										_CPCD_ALIASCOLOR C_TWO);

_CPCD_ALIASCOLOR	_CPCD_COLORMULTI	(_CPCD_ALIASCOLOR C_ONE,
										_CPCD_ALIASCOLOR C_TWO);

_CPCD_ALIASCOLOR	_CPCD_COLORADD		(_CPCD_ALIASCOLOR C_ONE,
										_CPCD_ALIASCOLOR C_TWO);

int					_CPCD_VECCMP		(_CPCD_ALIASVECTOR V_ONE,
										_CPCD_ALIASVECTOR V_TWO);

_CPCD_ALIASVECTOR	_CPCD_VECADD		(_CPCD_ALIASVECTOR V_ONE,
										_CPCD_ALIASVECTOR V_TWO);

_CPCD_ALIASVECTOR	_CPCD_VECSUB		(_CPCD_ALIASVECTOR V_ONE,
										_CPCD_ALIASVECTOR V_TWO);

_CPCD_ALIASVECTOR	_CPCD_VECMULTI		(_CPCD_ALIASVECTOR V_ONE,
										_CPCD_ALIASVECTOR V_TWO);

_CPCD_ALIASVECTOR	_CPCD_VECDIV		(_CPCD_ALIASVECTOR V_ONE,
										_CPCD_ALIASVECTOR V_TWO);



