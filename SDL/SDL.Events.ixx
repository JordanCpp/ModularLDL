// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstdint>

export module SDL.Events;

import SDL.Types;
import SDL.Key;
import SDL.Mod;

export
{
	typedef struct 
	{
		Uint8 scancode;			/* hardware specific scancode */
		SDLKey sym;			/* SDL virtual keysym */
		SDLMod mod;			/* current key modifiers */
		Uint16 unicode;			/* translated character */
	} SDL_keysym;

	typedef struct
	{
		Uint8 type;	/* SDL_ACTIVEEVENT */
		Uint8 gain;	/* Whether given states were gained or lost (1/0) */
		Uint8 state;	/* A mask of the focus states */
	} SDL_ActiveEvent;

	typedef struct
	{
		Uint8 type;	/* SDL_KEYDOWN or SDL_KEYUP */
		Uint8 which;	/* The keyboard device index */
		Uint8 state;	/* SDL_PRESSED or SDL_RELEASED */
		SDL_keysym keysym;
	} SDL_KeyboardEvent;

	typedef struct {
		Uint8 type;	/* SDL_MOUSEMOTION */
		Uint8 which;	/* The mouse device index */
		Uint8 state;	/* The current button state */
		Uint16 x, y;	/* The X/Y coordinates of the mouse */
		Sint16 xrel;	/* The relative motion in the X direction */
		Sint16 yrel;	/* The relative motion in the Y direction */
	} SDL_MouseMotionEvent;


	typedef struct
	{
		Uint8 type;	/* SDL_MOUSEBUTTONDOWN or SDL_MOUSEBUTTONUP */
		Uint8 which;	/* The mouse device index */
		Uint8 button;	/* The mouse button index */
		Uint8 state;	/* SDL_PRESSED or SDL_RELEASED */
		Uint16 x, y;	/* The X/Y coordinates of the mouse at press time */
	} SDL_MouseButtonEvent;


	/* Joystick axis motion event structure */
	typedef struct {
		Uint8 type;	/* SDL_JOYAXISMOTION */
		Uint8 which;	/* The joystick device index */
		Uint8 axis;	/* The joystick axis index */
		Sint16 value;	/* The axis value (range: -32768 to 32767) */
	} SDL_JoyAxisEvent;

	/* Joystick trackball motion event structure */
	typedef struct {
		Uint8 type;	/* SDL_JOYBALLMOTION */
		Uint8 which;	/* The joystick device index */
		Uint8 ball;	/* The joystick trackball index */
		Sint16 xrel;	/* The relative motion in the X direction */
		Sint16 yrel;	/* The relative motion in the Y direction */
	} SDL_JoyBallEvent;

	/* Joystick hat position change event structure */
	typedef struct {
		Uint8 type;	/* SDL_JOYHATMOTION */
		Uint8 which;	/* The joystick device index */
		Uint8 hat;	/* The joystick hat index */
		Uint8 value;	/* The hat position value:
					SDL_HAT_LEFTUP   SDL_HAT_UP       SDL_HAT_RIGHTUP
					SDL_HAT_LEFT     SDL_HAT_CENTERED SDL_HAT_RIGHT
					SDL_HAT_LEFTDOWN SDL_HAT_DOWN     SDL_HAT_RIGHTDOWN
				   Note that zero means the POV is centered.
				*/
	} SDL_JoyHatEvent;

	/* Joystick button event structure */
	typedef struct {
		Uint8 type;	/* SDL_JOYBUTTONDOWN or SDL_JOYBUTTONUP */
		Uint8 which;	/* The joystick device index */
		Uint8 button;	/* The joystick button index */
		Uint8 state;	/* SDL_PRESSED or SDL_RELEASED */
	} SDL_JoyButtonEvent;

	/* The "window resized" event
	   When you get this event, you are responsible for setting a new video
	   mode with the new width and height.
	 */
	typedef struct {
		Uint8 type;	/* SDL_VIDEORESIZE */
		int w;		/* New width */
		int h;		/* New height */
	} SDL_ResizeEvent;

	/* The "screen redraw" event */
	typedef struct {
		Uint8 type;	/* SDL_VIDEOEXPOSE */
	} SDL_ExposeEvent;

	/* The "quit requested" event */
	typedef struct {
		Uint8 type;	/* SDL_QUIT */
	} SDL_QuitEvent;

	/* A user-defined event type */
	typedef struct {
		Uint8 type;	/* SDL_USEREVENT through SDL_NUMEVENTS-1 */
		int code;	/* User defined event code */
		void* data1;	/* User defined data pointer */
		void* data2;	/* User defined data pointer */
	} SDL_UserEvent;


	struct SDL_SysWMmsg;
	typedef struct SDL_SysWMmsg SDL_SysWMmsg;
	typedef struct {
		Uint8 type;
		SDL_SysWMmsg* msg;
	} SDL_SysWMEvent;

	typedef union
	{
		Uint8 type;
		SDL_ActiveEvent active;
		SDL_KeyboardEvent key;
		SDL_MouseMotionEvent motion;
		SDL_MouseButtonEvent button;
		SDL_JoyAxisEvent jaxis;
		SDL_JoyBallEvent jball;
		SDL_JoyHatEvent jhat;
		SDL_JoyButtonEvent jbutton;
		SDL_ResizeEvent resize;
		SDL_ExposeEvent expose;
		SDL_QuitEvent quit;
		SDL_UserEvent user;
		SDL_SysWMEvent syswm;
	} SDL_Event;

	enum {
		SDL_NOEVENT = 0,			/* Unused (do not remove) */
		SDL_ACTIVEEVENT,			/* Application loses/gains visibility */
		SDL_KEYDOWN,			    /* Keys pressed */
		SDL_KEYUP,			        /* Keys released */
		SDL_MOUSEMOTION,			/* Mouse moved */
		SDL_MOUSEBUTTONDOWN,		/* Mouse button pressed */
		SDL_MOUSEBUTTONUP,		    /* Mouse button released */
		SDL_JOYAXISMOTION,		    /* Joystick axis motion */
		SDL_JOYBALLMOTION,		    /* Joystick trackball motion */
		SDL_JOYHATMOTION,		    /* Joystick hat position change */
		SDL_JOYBUTTONDOWN,		    /* Joystick button pressed */
		SDL_JOYBUTTONUP,			/* Joystick button released */
		SDL_QUIT,			        /* User-requested quit */
		SDL_SYSWMEVENT,			    /* System specific event */
		SDL_EVENT_RESERVEDA,		/* Reserved for future use.. */
		SDL_EVENT_RESERVEDB,		/* Reserved for future use.. */
		SDL_VIDEORESIZE,			/* User resized video mode */
		SDL_VIDEOEXPOSE,			/* Screen needs to be redrawn */
		SDL_EVENT_RESERVED2,		/* Reserved for future use.. */
		SDL_EVENT_RESERVED3,		/* Reserved for future use.. */
		SDL_EVENT_RESERVED4,		/* Reserved for future use.. */
		SDL_EVENT_RESERVED5,		/* Reserved for future use.. */
		SDL_EVENT_RESERVED6,		/* Reserved for future use.. */
		SDL_EVENT_RESERVED7,		/* Reserved for future use.. */
		/* Events SDL_USEREVENT through SDL_MAXEVENTS-1 are for your use */
		SDL_USEREVENT = 24,
		/* This last event is only for bounding internal arrays
	   It is the number of bits in the event mask datatype -- Uint32
		 */
		SDL_NUMEVENTS = 32
	};

	inline int(__cdecl* SDL_PollEvent)(SDL_Event* event) = nullptr;
}