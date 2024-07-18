PROGRAM exprMul;

VAR i,j,k,l : LONGINT;

BEGIN
	WRITELN(10*20);
	i := 7; k := 0-3; l := -4;
	j := i * k * l;
	WRITELN(j);
	l := j + 4 * j;
	WRITELN(l)
END.
