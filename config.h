/* See LICENSE file for copyright and license details. */

/* Appearance */
#define NUMCOLORS 3

static const char colors[NUMCOLORS][ColLast][8] ={
  /* border   foreground  background   index|hex  description */
  { "#073642", "#fdf6e3", "#002b36" }, // 00|01 = normal 
  { "#586e75", "#fdf6e3", "#073642" }, // 01|02 = selected
  { "#005577", "#eeeeee", "#005577" }, // 01|02 = selected
};


/*
Solarized Dark Colors
base03 002b36 1c1c1c bg
base02 073642 262626 bg highlight
base0  839496 808080 basic text
base1  93a1a1 8a8a8a highlighted text
 */
static const char font[] = "Siji 12" "," "AnonymousPro 9";

/*static const char normbordercolor[]      = "#444444";
static const char normbgcolor[]          = "#222222";
static const char normfgcolor[]          = "#bbbbbb";
static const char selbordercolor[]       = "#005577";
static const char selbgcolor[]           = "#005577";
static const char selfgcolor[]           = "#eeeeee";*/
static const unsigned int borderpx       = 2;        /* border pixel of window */
static const unsigned int snap           = 8;       /* snap pixel */
static const Bool showbar                = True;     /* False means no bar */
static const Bool topbar                 = True;     /* False means bottom bar */
static const unsigned int systrayspacing = 2;
static const Bool showsystray            = True;
static const Bool transbar               = False;

static const Rule rules[] = {
  /* class            instance    title       tags mask     isfloating   monitor */
  { "Gimp",           NULL,       NULL,       0,            True,        -1 },
  { "Firefox",        NULL,       NULL,       1 << 8,       False,       -1 },
  { "Calculator", NULL,       NULL,       1 << 8,       True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

#include "maximize.c"
#include "gaplessgrid.c"

static const Layout layouts[] = {
  /* symbol   arrange function */
  { "\uE1AA\u3000\uE131\u3000\uE1AA", tile },    /* first entry is default */
  { "\uE1AA\u3000\uE135\u3000\uE1AA", NULL },    /* no layout function means floating behavior */
  { "\uE1AA\u3000\uE130\u3000\uE1AA", monocle },
  { "\uE1AA\u3000\uE134\u3000\uE1AA", gaplessgrid},
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Tag tags[] = {
/* name    	layout       	mfact  	nmaster*/
  { "\uE1EF", &layouts[0], 	-1,    	-1 }, // terminal
  { "\uE1D3", &layouts[0], 	-1,  	-1 }, // devel
  { "\uE26D", &layouts[0], 	-1,    	-1 }, // web
  { "\uE1EB", &layouts[0], 	-1,    	-1 }, // media
  { "\uE225", &layouts[0],      -1,    	-1 }, // management
  { "\uE1E5", &layouts[0],      -1,     -1 }, // design
  { "\uE1ED", &layouts[0],      -1,     -1 }, // reading
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]   = { "dmenu_run", NULL};
static const char *termcmd[]    = { "urxvtc", NULL };
static const char *emacscmd[]   = {"emacsclient","-c", NULL};
static const char *webbrowser[] = {"firefox", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = webbrowser } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emacscmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_h,      togglehorizontalmax, NULL},
	{ MODKEY|ControlMask|ShiftMask, XK_l,      togglehorizontalmax, NULL },
	{ MODKEY|ControlMask|ShiftMask, XK_j,      toggleverticalmax,   NULL },
	{ MODKEY|ControlMask|ShiftMask, XK_k,      toggleverticalmax,   NULL },
	{ MODKEY|ControlMask,           XK_m,      togglemaximize,      {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

