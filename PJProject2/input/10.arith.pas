PROGRAM arithExpr;

VAR i,j,k,l,m,s0 : LONGINT;

BEGIN
	i := 1; j := 2; k := 3; l := 4;
	m := i + 7;
	WRITELN(m);
	s0 := l - 5;
	WRITELN(s0);
	WRITELN(j*k*l);
	WRITELN(j*k-l);
	WRITELN(i+j+k*l);
	WRITELN(k + l DIV j -i);		
	WRITELN((i+j)*(k + (i*m)) DIV s0)
END.
