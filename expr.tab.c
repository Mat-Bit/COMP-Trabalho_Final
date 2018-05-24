
/*  A Bison parser, made from expr.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TADD	258
#define	TSUB	259
#define	TMUL	260
#define	TDIV	261
#define	TMENOR	262
#define	TMAIOR	263
#define	TATB	264
#define	TMENORIG	265
#define	TMAIORIG	266
#define	TCOM	267
#define	TDIF	268
#define	TCEE	269
#define	TCOU	270
#define	TNEG	271
#define	TIF	272
#define	TWHILE	273
#define	TELSE	274
#define	TAPAR	275
#define	TFPAR	276
#define	TACHA	277
#define	TFCHA	278
#define	TASP	279
#define	TINT	280
#define	TFLOAT	281
#define	TSTRING	282
#define	TID	283
#define	TPV	284
#define	TV	285
#define	TRET	286
#define	TPRINT	287
#define	TDO	288
#define	TREAD	289
#define	TVOID	290
#define	TLITERAL	291
#define	TRUE	292
#define	FALSE	293
#define	TEND	294
#define	T_FIM	295

#line 1 "expr.y"

#include <stdio.h>
#include <stdlib.h>
#include "eda.h"

tArvore *tabelaSimbolos;
FILE *arq_saida;
tAST *raiz;


typedef struct Atributo{
  tLista *listaId;
  tArvore *tabelaSimbolos;
  char id[MAXID];
  char mensagem[100];
  TIPO tipo;
  int ConstInt;
  float ConstFloat;
  tAST *ast;
  tMsg *msg;
//
}tAtributo;

#define YYSTYPE tAtributo
int __linha__ = 1;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		156
#define	YYFLAG		-32768
#define	YYNTBASE	41

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 71)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     8,    10,    18,    24,    26,    28,    32,
    34,    37,    42,    46,    49,    51,    55,    57,    59,    61,
    65,    67,    71,    74,    76,    78,    80,    82,    84,    86,
    88,    90,    92,    96,   100,   106,   114,   120,   125,   129,
   135,   141,   147,   154,   162,   165,   170,   174,   178,   182,
   184,   186,   190,   194,   196,   199,   203,   207,   209,   213,
   215,   217,   219,   223,   227,   229,   232,   236,   238,   240,
   242,   246,   250,   254,   258,   262
};

static const short yyrhs[] = {    42,
    47,     0,    47,     0,    42,    43,     0,    43,     0,    44,
    28,    20,    45,    47,    21,    47,     0,    44,    28,    20,
    21,    47,     0,    50,     0,    35,     0,    45,    30,    46,
     0,    46,     0,    50,    28,     0,    22,    48,    53,    23,
     0,    22,    53,    23,     0,    48,    49,     0,    49,     0,
    50,    51,    29,     0,    25,     0,    27,     0,    26,     0,
    51,    30,    28,     0,    28,     0,    22,    53,    23,     0,
    53,    54,     0,    54,     0,    56,     0,    57,     0,    58,
     0,    59,     0,    60,     0,    61,     0,    62,     0,    55,
     0,    31,    65,    29,     0,    31,    36,    29,     0,    17,
    20,    68,    21,    52,     0,    17,    20,    68,    21,    52,
    19,    52,     0,    18,    20,    68,    21,    52,     0,    28,
     9,    65,    29,     0,    28,     9,    36,     0,    32,    20,
    65,    21,    29,     0,    32,    20,    36,    21,    29,     0,
    34,    20,    28,    21,    29,     0,    34,    20,    39,    28,
    21,    29,     0,    33,    52,    18,    20,    68,    21,    29,
     0,    63,    29,     0,    28,    20,    64,    21,     0,    28,
    20,    21,     0,    64,    30,    65,     0,    64,    30,    36,
     0,    65,     0,    36,     0,    65,     3,    66,     0,    65,
     4,    66,     0,    66,     0,     4,    67,     0,    66,     5,
    67,     0,    66,     6,    67,     0,    67,     0,    20,    65,
    21,     0,    26,     0,    25,     0,    28,     0,    68,    14,
    69,     0,    68,    15,    69,     0,    69,     0,    16,    69,
     0,    20,    69,    21,     0,    37,     0,    38,     0,    70,
     0,    65,     8,    65,     0,    65,    11,    65,     0,    65,
     7,    65,     0,    65,    10,    65,     0,    65,    12,    65,
     0,    65,    13,    65,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    31,    32,    34,    35,    37,    38,    40,    41,    43,    44,
    46,    48,    49,    51,    52,    54,    56,    57,    58,    60,
    61,    63,    66,    67,    69,    70,    71,    72,    73,    74,
    75,    76,    78,    79,    81,    82,    84,    86,    87,    89,
    90,    92,    93,    95,    97,    99,   100,   102,   103,   104,
   105,   108,   109,   110,   111,   113,   114,   115,   117,   118,
   119,   120,   122,   123,   124,   126,   127,   128,   129,   130,
   132,   133,   134,   135,   136,   137
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","TADD","TSUB",
"TMUL","TDIV","TMENOR","TMAIOR","TATB","TMENORIG","TMAIORIG","TCOM","TDIF","TCEE",
"TCOU","TNEG","TIF","TWHILE","TELSE","TAPAR","TFPAR","TACHA","TFCHA","TASP",
"TINT","TFLOAT","TSTRING","TID","TPV","TV","TRET","TPRINT","TDO","TREAD","TVOID",
"TLITERAL","TRUE","FALSE","TEND","T_FIM","Programa","ListaFuncoes","Funcao",
"TipoRetorno","DeclParametros","Parametro","BlocoPrincipal","Declaracoes","Declaracao",
"Tipo","ListaId","Bloco","ListaCmd","Comando","Retorno","CmdSe","CmdEnquanto",
"CmdAtrib","CmdEscrita","CmdLeitura","CmdDoWhile","ChamadaProc","ChamadaFuncao",
"ListaParametros","ExpressaoAritimetica","TExpressaoAritimetica","FExpressaoAritmetica",
"ExpressaoLogica","FExpressaoLogica","ExpressaoRelacional", NULL
};
#endif

static const short yyr1[] = {     0,
    41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
    46,    47,    47,    48,    48,    49,    50,    50,    50,    51,
    51,    52,    53,    53,    54,    54,    54,    54,    54,    54,
    54,    54,    55,    55,    56,    56,    57,    58,    58,    59,
    59,    60,    60,    61,    62,    63,    63,    64,    64,    64,
    64,    65,    65,    65,    65,    66,    66,    66,    67,    67,
    67,    67,    68,    68,    68,    69,    69,    69,    69,    69,
    70,    70,    70,    70,    70,    70
};

static const short yyr2[] = {     0,
     2,     1,     2,     1,     7,     5,     1,     1,     3,     1,
     2,     4,     3,     2,     1,     3,     1,     1,     1,     3,
     1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     3,     3,     5,     7,     5,     4,     3,     5,
     5,     5,     6,     7,     2,     4,     3,     3,     3,     1,
     1,     3,     3,     1,     2,     3,     3,     1,     3,     1,
     1,     1,     3,     3,     1,     2,     3,     1,     1,     1,
     3,     3,     3,     3,     3,     3
};

static const short yydefact[] = {     0,
     0,    17,    19,    18,     8,     0,     4,     0,     2,     7,
     0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
     0,    24,    32,    25,    26,    27,    28,    29,    30,    31,
     0,     3,     1,     0,     0,     0,     0,     0,     0,     0,
    61,    60,    62,     0,     0,    54,    58,     0,     0,     0,
     0,    14,     0,    21,     0,    13,    23,    45,     0,     0,
     0,    68,    69,     0,     0,    65,    70,     0,    39,     0,
    47,    51,     0,    50,    55,     0,    34,     0,     0,    33,
     0,     0,     0,     0,     0,     0,     0,     0,    12,    16,
     0,     0,     0,    10,     0,    66,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    38,    46,
     0,    59,    52,    53,    56,    57,     0,     0,    22,     0,
     0,     0,    20,     6,     0,     0,    11,    67,    73,    71,
    74,    72,    75,    76,    63,    64,    35,    37,    49,    48,
    41,    40,     0,    42,     0,     9,     0,     0,     0,    43,
     5,    36,    44,     0,     0,     0
};

static const short yydefgoto[] = {   154,
     6,     7,     8,    93,    94,     9,    18,    19,    10,    55,
    50,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    30,    31,    73,    64,    46,    47,    65,    66,    67
};

static const short yypact[] = {   102,
   129,-32768,-32768,-32768,-32768,   102,-32768,   -23,-32768,-32768,
     1,    42,     8,    44,    45,    57,    62,   129,-32768,   -17,
   141,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    39,-32768,-32768,    79,    16,    16,    77,    35,   188,   106,
-32768,-32768,-32768,    75,     9,    90,-32768,    81,   167,   103,
    -9,-32768,   148,-32768,    86,-32768,-32768,-32768,   194,    16,
    16,-32768,-32768,   199,    10,-32768,-32768,    63,-32768,    54,
-32768,-32768,    46,   145,-32768,    12,-32768,   188,   188,-32768,
   188,   188,    87,    19,   160,   113,   117,    95,-32768,-32768,
   124,   146,    13,-32768,   139,-32768,   132,   149,   106,   106,
   106,   106,   106,   106,    16,    16,    57,    57,-32768,-32768,
    94,-32768,    90,    90,-32768,-32768,   157,   158,-32768,    16,
   161,   168,-32768,-32768,    48,   175,-32768,-32768,   145,   145,
   145,   145,   145,   145,-32768,-32768,   178,-32768,-32768,   145,
-32768,-32768,    97,-32768,   176,-32768,   146,    57,   189,-32768,
-32768,-32768,-32768,   204,   217,-32768
};

static const short yypgoto[] = {-32768,
-32768,   216,-32768,-32768,    98,    -6,-32768,   206,     0,-32768,
   -99,    -4,   -19,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -11,    72,   -35,   -26,   -54,-32768
};


#define	YYLAST		224


static const short yytable[] = {    33,
    20,    57,    45,    75,    34,    96,    98,   137,   138,    68,
    54,    78,    79,    53,    78,    79,    37,    20,    87,    39,
    35,    78,    79,   105,   106,    70,    74,    38,    76,    88,
   107,    60,   112,    57,     1,    61,    84,    80,    39,   118,
    41,    42,   125,    43,    85,   115,   116,    39,   152,    97,
   135,   136,    62,    63,    40,    71,    78,    79,    95,    41,
    42,    36,    43,    40,    48,    57,   110,    58,    41,    42,
    72,    43,     2,     3,     4,   111,   105,   106,    49,    44,
    39,    51,   109,   108,    39,   124,   126,   129,   130,   131,
   132,   133,   134,   143,    81,    82,    40,    39,    59,   140,
    40,    41,    42,    77,    43,    41,    42,   117,    43,    39,
   105,   106,    69,    40,    90,    91,    83,   149,    41,    42,
    86,    43,   122,     1,    95,    40,     2,     3,     4,   139,
    41,    42,   120,    43,    78,    79,     5,   121,    99,   100,
   151,   101,   102,   103,   104,    11,    12,    78,    79,   113,
   114,   123,   112,     2,     3,     4,    13,    11,    12,    14,
    15,    16,    17,    56,    11,    12,   127,     1,    13,   128,
    89,    14,    15,    16,    17,    13,    11,    12,    14,    15,
    16,    17,   119,    11,    12,   141,   142,    13,   145,   144,
    14,    15,    16,    17,    13,   147,   148,    14,    15,    16,
    17,    78,    79,   155,   150,    99,   100,    40,   101,   102,
   103,   104,    41,    42,    92,    43,   156,   153,     2,     3,
     4,    32,   146,    52
};

static const short yycheck[] = {     6,
     1,    21,    14,    39,    28,    60,    61,   107,   108,    36,
    28,     3,     4,    18,     3,     4,     9,    18,    28,     4,
    20,     3,     4,    14,    15,    37,    38,    20,    40,    39,
    21,    16,    21,    53,    22,    20,    48,    29,     4,    21,
    25,    26,    30,    28,    49,    81,    82,     4,   148,    61,
   105,   106,    37,    38,    20,    21,     3,     4,    59,    25,
    26,    20,    28,    20,    20,    85,    21,    29,    25,    26,
    36,    28,    25,    26,    27,    30,    14,    15,    22,    36,
     4,    20,    29,    21,     4,    92,    93,    99,   100,   101,
   102,   103,   104,   120,     5,     6,    20,     4,    20,   111,
    20,    25,    26,    29,    28,    25,    26,    21,    28,     4,
    14,    15,    36,    20,    29,    30,    36,    21,    25,    26,
    18,    28,    28,    22,   125,    20,    25,    26,    27,    36,
    25,    26,    20,    28,     3,     4,    35,    21,     7,     8,
   147,    10,    11,    12,    13,    17,    18,     3,     4,    78,
    79,    28,    21,    25,    26,    27,    28,    17,    18,    31,
    32,    33,    34,    23,    17,    18,    28,    22,    28,    21,
    23,    31,    32,    33,    34,    28,    17,    18,    31,    32,
    33,    34,    23,    17,    18,    29,    29,    28,    21,    29,
    31,    32,    33,    34,    28,    21,    19,    31,    32,    33,
    34,     3,     4,     0,    29,     7,     8,    20,    10,    11,
    12,    13,    25,    26,    21,    28,     0,    29,    25,    26,
    27,     6,   125,    18
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 32 "expr.y"
{yyval.ast = yyvsp[0].ast; raiz = yyval.ast;;
    break;}
case 12:
#line 48 "expr.y"
{yyval.ast = yyvsp[-1].ast;;
    break;}
case 13:
#line 49 "expr.y"
{yyval.ast = yyvsp[-1].ast;;
    break;}
case 16:
#line 54 "expr.y"
{insereTipo(yyvsp[-1].listaId, yyvsp[-2].tipo); insereListaNaArvore(yyvsp[-1].listaId, tabelaSimbolos);;
    break;}
case 17:
#line 56 "expr.y"
{yyval.tipo = T_INT;;
    break;}
case 18:
#line 57 "expr.y"
{yyval.tipo = T_STRING;;
    break;}
case 19:
#line 58 "expr.y"
{yyval.tipo = T_FLOAT;;
    break;}
case 20:
#line 60 "expr.y"
{insereLista(yyvsp[-2].listaId, yyvsp[0].id); yyval.listaId = yyvsp[-2].listaId;;
    break;}
case 21:
#line 61 "expr.y"
{yyval.listaId = criarLista(yyvsp[0].id);;
    break;}
case 22:
#line 63 "expr.y"
{yyval.ast = yyvsp[-1].ast;;
    break;}
case 23:
#line 66 "expr.y"
{yyval.ast = insereListaComando(yyvsp[-1].ast, yyvsp[0].ast, CMD);;
    break;}
case 24:
#line 67 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 25:
#line 69 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 26:
#line 70 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 27:
#line 71 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 28:
#line 72 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 29:
#line 73 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 30:
#line 74 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 31:
#line 75 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 32:
#line 76 "expr.y"
{yyval.ast = yyvsp[0].ast;;
    break;}
case 35:
#line 81 "expr.y"
{yyval.ast = criaCmdIf(yyvsp[-2].ast, yyvsp[0].ast, IFF);;
    break;}
case 36:
#line 82 "expr.y"
{yyval.ast = criaCmdIfElse(yyvsp[-4].ast, yyvsp[-2].ast, yyvsp[0].ast, IFEL);;
    break;}
case 37:
#line 84 "expr.y"
{yyval.ast = criaCmdWhile(yyvsp[-2].ast, yyvsp[0].ast, WLE);;
    break;}
case 38:
#line 86 "expr.y"
{yyval.ast = criaCmdAtrib(tabelaSimbolos, yyvsp[-1].ast, yyvsp[-3].id);;
    break;}
case 40:
#line 89 "expr.y"
{yyval.ast = cmdPrint(yyvsp[-2].ast, PRT);
    break;}
case 41:
#line 90 "expr.y"
{yyvsp[-2].msg = criaMensagem(yyvsp[-2].mensagem); yyval.ast = cmdPrint(criaLiteral(yyvsp[-2].msg, MSG), PRT);;
    break;}
case 44:
#line 95 "expr.y"
{yyval.ast = criaCmdDoWhile(yyvsp[-5].ast, yyvsp[-2].ast, DOWLE);;
    break;}
case 52:
#line 108 "expr.y"
{ yyval.ast = criaAst_ExpArit(yyvsp[-2].ast, yyvsp[0].ast, ADD);;
    break;}
case 53:
#line 109 "expr.y"
{ yyval.ast = criaAst_ExpArit(yyvsp[-2].ast, yyvsp[0].ast, SUB); ;
    break;}
case 54:
#line 110 "expr.y"
{ yyval.ast = yyvsp[0].ast; ;
    break;}
case 55:
#line 111 "expr.y"
{ yyval.ast = neg(yyvsp[0].ast); ;
    break;}
case 56:
#line 113 "expr.y"
{ yyval.ast = criaAst_ExpArit(yyvsp[-2].ast, yyvsp[0].ast, MUL); ;
    break;}
case 57:
#line 114 "expr.y"
{ yyval.ast = criaAst_ExpArit(yyvsp[-2].ast, yyvsp[0].ast, DIV); ;
    break;}
case 58:
#line 115 "expr.y"
{ yyval.ast = yyvsp[0].ast; ;
    break;}
case 59:
#line 117 "expr.y"
{ yyval.ast = yyvsp[-1].ast; ;
    break;}
case 60:
#line 118 "expr.y"
{yyval.ast = criar_ast_float(yyvsp[0].ConstFloat);;
    break;}
case 61:
#line 119 "expr.y"
{yyval.ast = criar_ast_int(yyvsp[0].ConstInt);;
    break;}
case 62:
#line 120 "expr.y"
{yyval.ast = criar_ast_id(tabelaSimbolos, yyvsp[0].id);;
    break;}
case 63:
#line 122 "expr.y"
{yyval.ast = criaAst_ExpLog(yyvsp[-2].ast, yyvsp[0].ast, EEE);;
    break;}
case 64:
#line 123 "expr.y"
{yyval.ast = criaAst_ExpLog(yyvsp[-2].ast, yyvsp[0].ast, OOU);;
    break;}
case 66:
#line 126 "expr.y"
{yyval.ast = criaAst_ExpLog(yyvsp[0].ast, NULL, NEG);;
    break;}
case 67:
#line 127 "expr.y"
{yyval.ast = yyvsp[-1].ast;;
    break;}
case 71:
#line 132 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, MAIOR);;
    break;}
case 72:
#line 133 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, MAIIG);;
    break;}
case 73:
#line 134 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, MENOR);;
    break;}
case 74:
#line 135 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, MENIG);;
    break;}
case 75:
#line 136 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, IGUAL);;
    break;}
case 76:
#line 137 "expr.y"
{yyval.ast = criaAst_ExpRelac(yyvsp[-2].ast, yyvsp[0].ast, DIF);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 139 "expr.y"

#include "lex.yy.c"

int yyerror (char *str)
{
	printf("[Linha%d]\tTipo de erro: %s\t antes do caracter: %s\n", __linha__,str, yytext);
}

int yywrap()
{
	return 1;
}
