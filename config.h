/* appearance */
static const unsigned int borderpx  = 1;
static const unsigned int gappx     = 5;
static const unsigned int snap      = 20;
static const unsigned int showbar   = 1;
static const unsigned int topbar    = 1;
static const char *fonts[]          = { "Cantarell:size=14", "JetBrainsMono NerdFont:size=16" };
static const char col_bg[]			= "#151515";
static const char col_fg[]			= "#cccccc";
static const char col_black[]		= "#191919";
static const char col_yellow[]      = "#e1b655";
static const char col_disabled[]    = "#606060";
static const char *colors[][3]      = {
	/*               fg                bg          border   */
	[SchemeNorm]     = { col_fg,	   col_bg,	   col_black  },
	[SchemeSel]      = { col_bg,	   col_yellow, col_yellow },
	[SchemeIcon]     = { col_yellow,   col_bg,	   col_yellow },
	[SchemeDisabled] = { col_disabled, col_bg,     col_yellow },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class					instance    title       tags mask     isfloating   monitor */
	{ "steam",					NULL,       NULL,       1 << 0,       0,           -1 },
	{ "league of legends.exe",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "discord",				NULL,       NULL,       1 << 3,       0,           1 },
};

/* layouts */
static const float mfact		= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster		= 1;    /* number of clients in master area */
static const int resizehints	= 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* keybinds */
static const Key keys[] = {
	/* modifier                     key           function        argument */
	STACKKEYS(MODKEY,							  focus)
	STACKKEYS(MODKEY|ShiftMask,	                  push)
	TAGKEYS(                        XK_1,                         0)
	TAGKEYS(                        XK_2,                         1)
	TAGKEYS(                        XK_3,                         2)
	TAGKEYS(                        XK_4,                         3)
	TAGKEYS(                        XK_5,                         4)
	TAGKEYS(                        XK_6,                         5)
	TAGKEYS(                        XK_7,                         6)
	TAGKEYS(                        XK_8,                         7)
	TAGKEYS(                        XK_9,                         8)
	{ MODKEY,                       XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,         setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,       view,           {0} },
	{ MODKEY,						XK_w,         killclient,     {0} },
	{ MODKEY,                       XK_t,         setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,         togglefullscr,  {0} },
	{ MODKEY,			            XK_s,         togglefloating, {0} },
	{ MODKEY,                       XK_0,         view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,         tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,     focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,    focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,    tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_BackSpace, quit,           {0} },
};

/* button definitions */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
