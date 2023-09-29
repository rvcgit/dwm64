/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 6, .gappx = 6};
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
/* Added this from arch wiki for st config  */
/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
unsigned int blinktimeout = 800;  /* removed static from begining */

/*
 * thickness of underline and bar cursors   
 */
unsigned int cursorthickness = 2;  /* removed static from begining */


/* default TERM value */
char *termname = "st-256color";
/* Terminal colors (16 first used in escape sequence) */
/* removed "static" from staticconst char below */
const char *colorname[] = {
	/* 8 normal colors */
	"#1a1e22", /* "black" */
	"#d9381e",  /* "red3" */
	"#29ab87", /* "green3" */
	"#ffbf00", /* "yellow3" */
	"#4682b4", /* "blue2" */
	"#cc00ff", /* "magenta3" */
	"#00ffff", /* "cyan3" */
	"#b2beb5", /* "gray90" */

	/* 8 bright colors */
	"#525e54", /* "gray50" */ 
	"#ed2939", /* "red" */
	"#00fa9a", /* "green" */
	"#fafa37", /* "yellow" */
	"#6495ed", /* "blue" */
	"#ba55d3", /* "magenta" */
	"#40e0d0", /* "cyan" */
	"#e5e4e2", /* "white" */

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#d8dee9", /* 256 -> cursor */
	"#eceff4", /* 257 -> reverse cursor */
	"#c0c0c0", /* 258 -> used for defaulttcs */
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 255;
unsigned int defaultbg = 1;
unsigned int defaultcs = 256;  /*removed static at begining */
unsigned int defaultrcs = 258; /*removed static at begining */

/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 static unsigned int cursorshape = 2;
*/

/*
 * Default columns and rows numbers
 */
/*
static unsigned int cols = 80;
static unsigned int rows = 24;
*/
/*
 * Default colour and shape of the mouse cursor
 */

/*
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
*/

/*end st config part */

static const char *fonts[] = {
	"UbuntuMono Nerd Font:pixelsize=11:antialias=true",
	"waffle:size=10", 
	"-*-font logos-medium-*-*-*-10-*-*-*-p-0-iso10646-1",
	"font logos:pixelsize=14",
	"rissole:size=10:antialias=true",
};
static const char dmenufont[]       = "Hack Nerd Font:size=8";
static const char col_gray1[]       = "#1a1e22";
static const char col_gray2[]       = "#434c5e";
static const char col_gray3[]       = "#a6aabd";
static const char col_gray4[]       = "#d8dee9";
static const char col_blue[]        = "#4682b4";
static const char col_lblue[]       = "#82afff";
static const char col_black[]       = "#3D3C3A";
static const char col_red[]         = "#ed2939";
static const char col_yellow[]      = "#fafa37";
static const char col_lgreen[]      = "#00fa9a";
static const char col_white[]       = "#eceff4";
static const char *colors[][3]      = {
	/*			fg         bg          border   */
	[SchemeNorm] =	 { col_gray3, col_gray1,  col_black },
	[SchemeSel]  =	 { col_lgreen, col_gray1, col_blue },
/*	[SchemeWarn] =	 { col_yellow, col_gray1, col_red }, */
/*	[SchemeUrgent] = { col_white, col_red,    col_red }, */
};

/* tagging */
static const char *tags[] = { "΁΁΁α", " β", " γ", " δ", " ϵ" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp-2.10",     NULL,       NULL,       1<<3,            1,           -1 },
	{ "Navigator",  NULL,       NULL,       1 << 4,       0,           -1 },  /* for firefox, use Navigator OR firefox */
	{ "Virt-manager",  NULL,       NULL,       1 << 5,       0,           -1 },
	{"Gcolor3",     NULL,   NULL,   0,      1,      -1},
	{"ONLYOFFICE Desktop Editors",  NULL,   NULL, 1<<2,     1,      -1},
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
/*	{ "[]=",      tile }, */   /* first entry is default */
/*	{ "><>",      NULL }, */   /* no layout function means floating behavior */
/*	{ "[M]",      monocle }, */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ NULL,     NULL },
	
};


//* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* Multimedia Key Mapping */
#define XF86AudioLowerVolume	0x1008ff11
#define XF86AudioMute		0x1008ff12
#define XF86AudioRaiseVolume	0x1008ff13
#define XF86AudioPlay		0x1008ff14
#define XF86AudioStop		0x1008ff15
#define XF86AudioPrev		0x1008ff16
#define XF86AudioNext		0x1008ff17
#define XF86TouchpadToggle	0x1008ffa9

#define XF86MonBrightnessUp   0x1008FF02  /* Monitor/panel brightness */
#define XF86MonBrightnessDown 0x1008FF03  /* Monitor/panel brightness */
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

//* commands */
static const char *dmenucmd[] = { "dmenu_recency", "-fn","Monofur NF:size=11:antialias=true", "-p", " Search Recent:", "-nb", col_gray1, "-nf", col_gray3, "-sb", col_lblue, "-sf", col_gray1, NULL };
static const char *termcmd[]  = { "st", "-f", "Monofur NF:Book:size=11", NULL };
static const char *terminal[] = { "urxvtc", NULL };
static const char *files[] = { "pcmanfm", NULL };
static const char *web[] = { "firefox", NULL };
static const char *virtmanager[] = { "virt-manager", NULL };
static const char *rofi[] = { "rofi","-show","drun", NULL };
static const char *rofimenu[] = { "rofimenu", NULL };
static const char *jgmenu[] = { "jgmenu_run", NULL };

static const char *exitmenu[]		= { "rofi-exit-menu", NULL };

static const char *volup[] = { "pulseaudio-ctl", "up", NULL };
static const char *voldown[] = { "pulseaudio-ctl", "down", NULL };
static const char *voltoggle[] = { "pulseaudio-ctl", "mute", NULL };
static const char *togPlay[] = { "mpc", "toggle", NULL };
static const char *prevPlay[]= { "mpc", "prev", NULL };
static const char *nextPlay[] = { "mpc", "next", NULL };
static const char *togtouchpad[] = { "touchpad", NULL };
static const char *backlightup[] = { "sudo", "light", "-A", "3", NULL }; /* increase brightness by 5 */
static const char *backlightdn[] = { "sudo", "light", "-U", "3", NULL }; /* decrease brightness by 5 */

static const Key keys[] = {
	/* modifier			key		function	argument */
	{ MODKEY,		XK_p,      	spawn,      {.v = dmenucmd } },
	{ MODKEY|ShiftMask,	XK_p,		spawn,		{.v = rofi } },
	{ MODKEY|ControlMask,	XK_p,		spawn,		{.v = jgmenu } },
	{ MODKEY|ShiftMask,	XK_Return, 	spawn,      {.v = termcmd } },
	{ MODKEY|ControlMask,	XK_Return,	spawn,		{.v = terminal } },
	{ MODKEY|ShiftMask,	XK_b,	   	spawn,		{.v = web } },
	{ MODKEY|ShiftMask,	XK_f,		spawn,		{.v = files} },
	{ MODKEY|ShiftMask,	XK_v,		spawn,		{.v = virtmanager } },	
	{ MODKEY,		XK_b,      	togglebar,      {0} },
	{ MODKEY,		XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,		XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY,		XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY,		XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,		XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,		XK_l,      	setmfact,       {.f = +0.05} },
	{ MODKEY,		XK_Return, 	zoom,           {0} },
	{ MODKEY,		XK_Tab,    	view,           {0} },
	{ MODKEY|ShiftMask,	XK_c,      	killclient,     {0} },
	{ MODKEY,		XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,		XK_f,      	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,		XK_m,      	setlayout,      {.v = &layouts[2]} },
	{ MODKEY,		XK_space,  	setlayout,      {0} },
	{ MODKEY|ShiftMask,	XK_space,	togglefloating, {0} },
	{ MODKEY,		XK_0,		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,	XK_0,		tag,            {.ui = ~0 } },
	{ MODKEY,		XK_comma,	focusmon,       {.i = -1 } },
	{ MODKEY,		XK_period,	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,	XK_comma,	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,	XK_period,	tagmon,         {.i = +1 } },
	{ MODKEY,		XK_minus,	setgaps,        {.i = -3 } },
	{ MODKEY,		XK_equal,	setgaps,        {.i = +3 } },
	{ MODKEY|ShiftMask,	XK_minus,	setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,	XK_equal,	setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(		XK_1,           0)
	TAGKEYS(		XK_2,           1)
	TAGKEYS(		XK_3,           2)
	TAGKEYS(		XK_4,           3)
	TAGKEYS(		XK_5,           4)
	TAGKEYS(		XK_6,           5)
	TAGKEYS(		XK_7,           6)
	TAGKEYS(		XK_8,           7)
	TAGKEYS(		XK_9,           8)
	{ MODKEY|ShiftMask,	XK_q,      	quit,	{0} },
     	{ MODKEY|ControlMask,	XK_l,		spawn,	{.v = exitmenu } },
     	{ 0,	XF86AudioRaiseVolume,		spawn,	{.v = volup } },
    	{ 0,	XF86AudioLowerVolume,		spawn,	{.v = voldown } },
    	{ 0,	XF86AudioMute,			spawn,	{.v = voltoggle } },
     	{ 0,	XF86AudioPlay,			spawn,	{.v = togPlay } },
     	{ 0,	XF86AudioPrev,			spawn,	{.v = prevPlay } },
     	{ 0, 	XF86AudioNext,			spawn,	{.v = nextPlay } },
    	{ 0,	XF86TouchpadToggle,		spawn,	{.v = togtouchpad } },
	{ 0,	XF86MonBrightnessUp,		spawn,	{.v = backlightup } },
	{ 0,	XF86MonBrightnessDown,		spawn,	{.v = backlightdn } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button         	function        argument */
	{ ClkLtSymbol,          0,              Button1,       	setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,       	setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,       	zoom,           {0} },
	{ ClkStatusText,        0,              Button2,       	spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,       	movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,       	togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,       	resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,       	view,           {0} },
	{ ClkTagBar,            0,              Button3,       	toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,       	tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,       	toggletag,      {0} },
	{ ClkRootWin,		0,		Button3,	spawn,		{.v = rofimenu   } },
	{ ClkRootWin,		0,		Button2,	spawn,		{.v = exitmenu } },
};


