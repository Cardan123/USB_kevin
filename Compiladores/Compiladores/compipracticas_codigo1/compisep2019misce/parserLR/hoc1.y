%token NUMBER
%left '+' '-'
%left '*' '/'
%% 
exp:      NUMBER          { $$ = $1;  }
        | exp '+' exp     { $$ = $1+$3;  }
        | exp '-' exp     { $$ = $1-$3;  }
        | exp '*' exp     { $$ = $1*$3;  }
        | exp '/' exp     { $$ = $1/$3;  }
        | '(' exp ')'     { $$ = $2;}
	;
%%
