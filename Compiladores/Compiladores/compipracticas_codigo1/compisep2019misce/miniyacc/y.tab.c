short yyini = 0;
short yyntoks = 5;
short yyr1[] = {
   2,   1,   3,   3,   3
};
short yyr2[] = {
   0,   1,   1,   1,   1
};
short yyadef[] = {
  -1,  -1,   0,   1,   2,   3,  -1,  -1,  -1,  -1,
   4
};
short yygdef[] = {
  -1,   1
};
short yyadsp[] = {
   4,   0,  -5,  -5,   6,  -5,   2,   4,   4,   4,
  -5
};
short yygdsp[] = {
 -11,   2
};
short yyact[] = {
   2,   7,   8,   7,   8,   3,  10,   9,   8,   4,
   5,   6
};
short yychk[] = {
   0,   1,   2,   1,   2,   1,   4,   3,   2,   6,
   6,   6
};
short yytrns[] = {
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   3,   4,   2,   0,   0,   1,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0
};

#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval;

int
yyparse()
{
	enum {
		StackSize = 100,
		ActSz = sizeof yyact / sizeof yyact[0],
	};
	struct {
		YYSTYPE val;
		int state;
	} stk[StackSize], *ps;
	int r, h, n, s, tk;
	YYSTYPE yyval;

	ps = stk;
	ps->state = s = yyini;
	tk = -1;
loop:
	n = yyadsp[s];
	if (tk < 0 && n > -yyntoks)
		tk = yytrns[yylex()];
	n += tk;
	if (n < 0 || n >= ActSz || yychk[n] != tk) {
		r = yyadef[s];
		if (r < 0)
			return -1;
		goto reduce;
	}
	n = yyact[n];
	if (n == -1)
		return -1;
	if (n < 0) {
		r = - (n+2);
		goto reduce;
	}
	tk = -1;
	yyval = yylval;
stack:
	ps++;
	if (ps-stk >= StackSize)
		return -2;
	s = n;
	ps->state = s;
	ps->val = yyval;
	goto loop;
reduce:
	ps -= yyr1[r];
	h = yyr2[r];
	s = ps->state;
	n = yygdsp[h] + s;
	if (n < 0 || n >= ActSz || yychk[n] != yyntoks+h)
		n = yygdef[h];
	else
		n = yyact[n];
	switch (r) {
	case 0:
#line 0 "hoc1.y"
		yyval = ps[1].val; return 0;
		break;
	case 1:
#line 0 "hoc1.y"
		break;
	case 2:
#line 0 "hoc1.y"
		break;
	case 3:
#line 0 "hoc1.y"
		break;
	case 4:
#line 0 "hoc1.y"
		break;
	}
	goto stack;
}
#line 9 "hoc1.y"

