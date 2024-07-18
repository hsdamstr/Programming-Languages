PROGRAM exprDiv;

VAR i,j,k,l : LONGINT;

BEGIN
	WRITELN(51 DIV 17);
	WRITELN(52 DIV 17);
	i := 100; k := 2; l := 5;
	j := i DIV k DIV l;
	WRITELN(j);
	WRITELN('Enter integer l = ');
	READ(l);
	l := j + l DIV 4;
	WRITELN(l)
END.
