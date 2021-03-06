#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <X11/XKBlib.h>

#include <X11/extensions/xf86vmode.h>
#include <X11/extensions/Xinerama.h>
#include <X11/extensions/Xrandr.h>
#include <X11/extensions/XInput2.h>

#include <GL/glx.h>

typedef struct x11display_s
{
	Display *dpy;
	int scr;
	Window root, win, gl_win, old_win;
	Colormap cmap;
	GLXContext ctx;
	XVisualInfo *visinfo;
	XSetWindowAttributes wa;
	XIM im;
	XIC ic;
	Atom wmDeleteWindow;

	Atom wmState;
	struct featureset_s {
		bool wmStateFullscreen;
	} features;
	bool modeset;
	unsigned int win_width, win_height;
} x11display_t;

typedef int (* x11wndproc_t)(void *, int, int, int);

// defined by glx_imp.c, used also by in_x11.c
extern x11display_t x11display;
