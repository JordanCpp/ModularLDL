// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

export module SDL.Surface;

import SDL.Types;
import SDL.PixelFormat;
import SDL.Rect;

export
{
	const Uint32 SDL_SWSURFACE = 0x00000000;	/* Surface is in system memory */
	const Uint32 SDL_HWSURFACE = 0x00000001;	/* Surface is in video memory */
	const Uint32 SDL_ASYNCBLIT = 0x00000004;	/* Use asynchronous blits if possible */
	/* Available for SDL_SetVideoMode() */
	const Uint32 SDL_ANYFORMAT = 0x10000000;	/* Allow any video depth/pixel-format */
	const Uint32 SDL_HWPALETTE = 0x20000000;	/* Surface has exclusive palette */
	const Uint32 SDL_DOUBLEBUF = 0x40000000;	/* Set up double-buffered video mode */
	const Uint32 SDL_FULLSCREEN = 0x80000000;	/* Surface is a full screen display */
	const Uint32 SDL_OPENGL = 0x00000002;      /* Create an OpenGL rendering context */
	const Uint32 SDL_OPENGLBLIT = 0x0000000A;	/* Create an OpenGL rendering context and use it for blitting */
	const Uint32 SDL_RESIZABLE = 0x00000010;	/* This video mode may be resized */
	const Uint32 SDL_NOFRAME = 0x00000020;	/* No window caption or edge frame */
	/* Used internally (read-only) */
	const Uint32 SDL_HWACCEL = 0x00000100;	/* Blit uses hardware acceleration */
	const Uint32 SDL_SRCCOLORKEY = 0x00001000;	/* Blit uses a source color key */
	const Uint32 SDL_RLEACCELOK = 0x00002000;	/* Private flag */
	const Uint32 SDL_RLEACCEL = 0x00004000;	/* Surface is RLE encoded */
	const Uint32 SDL_SRCALPHA = 0x00010000;	/* Blit uses source alpha blending */
	const Uint32 SDL_PREALLOC = 0x01000000;	/* Surface uses preallocated memory */

	struct SDL_Surface
	{
		Uint32 flags;				/* Read-only */
		SDL_PixelFormat* format;	/* Read-only */
		int w, h;				    /* Read-only */
		Uint16 pitch;				/* Read-only */
		void* pixels;				/* Read-write */
		int offset;				    /* Private */

		/* Hardware-specific surface info */
		struct private_hwdata* hwdata;

		/* clipping information */
		SDL_Rect clip_rect;			/* Read-only */
		Uint32 unused1;				/* for binary compatibility */

		/* Allow recursive locks */
		Uint32 locked;				/* Private */

		/* info for fast blit mapping to other surfaces */
		struct SDL_BlitMap* map;		/* Private */

		/* format version, bumped at every change to invalidate blit maps */
		unsigned int format_version;		/* Private */

		/* Reference count -- used when freeing surface */
		int refcount;				/* Read-mostly */
	};

	inline SDL_Surface* (__cdecl* SDL_SetVideoMode)(int width, int height, int bpp, Uint32 flags) = nullptr;
	inline void(__cdecl* SDL_WM_SetCaption)(const char* title, const char* icon) = nullptr;
}