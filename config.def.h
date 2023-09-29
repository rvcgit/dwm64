/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
/*	"Cousine NF:size=10", */
	"rissole:size=12",
	"waffle:size=12",
	"-*-font logos-medium-*-*-*-10-*-*-*-p-0-iso10646-1",
	"font logos:pixelsize=14",
	"Hack Nerd Font:size=10",
};
static const char *exitmenu[]		= { "android_powermenu", NULL };
static const char dmenufont[]       = "sundae 12";
static const char col_gray1[]       = "#4c566a";
static const char col_gray2[]       = "#434c5e";
static const char col_gray3[]       = "#bdbdbd";
static const char col_gray4[]       = "#d8dee9";
static const char col_blue[]        = "#5e81ac";
static const char col_lblue[]       = "#81a1c1";
static const char col_black[]       = "#2e3440";
static const char col_red[]         = "#d08770";
static const char col_yellow[]      = "#ebcb8b";
static const char col_white[]       = "#eceff4";
static const char *colors[][3]      = {
	/*			fg         bg          border   */
	[SchemeNorm] =	 { col_gray3, col_gray1,  col_black },
	[SchemeSel]  =	 { col_lblue, col_gray1, col_blue },
/*	[SchemeWarn] =	 { col_yellow, col_gray1, col_red },
	[SchemeUrgent] = { col_white, col_red,    col_red }, */
};

/* tagging */
static const char *tags[] = { "i", " ii", " iii", " iv", " v" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 4,       0,           -1 },
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
     { NULL,       NULL },
	
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
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

//* commands */
static const char *dmenucmd[] = { "dmenu_recency", "-fn", "sundae 12", "-nb", col_gray1, "-nf", col_gray3, "-sb", col_yellow, "-sf", col_gray1, NULL };
static const char *termcmd[]  = { "st", "-f", "Cousine NF:size=10", NULL };
static const char *terminal[] = { "urxvtc", NULL };
static const char *files[] = { "pcmanfm", NULL };
static const char *web[] = { "firefox", NULL };
static const char *virtmanager[] = { "virt-manager", NULL };
static const char *rofi[] = { "launcher_ribbon", NULL };
static const char *rofimenu[] = { "launcher_text" ,NULL };
static const char *jgmenu[] = { "jgmenu_run", NULL };

/*static const char *exitmenu[]		= { "android_powermenu", NULL }; */

static const char *volup[] = { "pulseaudio-ctl", "up", NULL };
static const char *voldown[] = { "pulseaudio-ctl", "down", NULL };
static const char *voltoggle[] = { "pulseaudio-ctl", "mute", NULL };
static const char *togPlay[] = { "mpc", "toggle", NULL };
static const char *prevPlay[]= { "mpc", "prev", NULL };
static const char *nextPlay[] = { "mpc", "next", NULL };
static const char *togtouchpad[] = { "touchpad", NULL };

static const Key keys[] = {
	/* modifier			key		function	argument */
	{ MODKEY,                       XK_p,      	spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,		XK_p,		spawn,		{.v = rofi } },
	{ MODKEY|ControlMask,		XK_p,		spawn,		{.v = jgmenu } },
	{ MODKEY|ShiftMask,             XK_Return, 	spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,		XK_Return,	spawn,		{.v = terminal } },
	{ MODKEY|ShiftMask,		XK_b,	   	spawn,		{.v = web } },
	{ MODKEY|ShiftMask,		XK_f,		spawn,		{.v = files} },
	{ MODKEY|ShiftMask,		XK_v,		spawn,		{.v = virtmanager } },	
	{ MODKEY,                       XK_b,      	togglebar,      {0} },
	{ MODKEY,                       XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, 	zoom,           {0} },
	{ MODKEY,                       XK_Tab,    	view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      	killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
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
     { MODKEY|ControlMask,		  XK_l,	   spawn,		    {.v = exitmenu } },
     { 0,				XF86AudioRaiseVolume,	spawn,			{.v = volup } },
    	{ 0,				XF86AudioLowerVolume,	spawn,			{.v = voldown } },
    	{ 0,				XF86AudioMute,			spawn,			{.v = voltoggle } },
     { 0,				XF86AudioPlay,			spawn,			{.v = togPlay } },
     { 0,				XF86AudioPrev,			spawn,			{.v = prevPlay } },
     { 0, 			XF86AudioNext,			spawn,			{.v = nextPlay } },
    	{ 0,				XF86TouchpadToggle,		spawn,			{.v = togtouchpad } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
	{ ClkRootWin,		0,		Button2,	spawn,		{.v = rofimenu   } },
	{ ClkRootWin,		0,		Button3,	spawn,		{.v = jgmenu } },
};


