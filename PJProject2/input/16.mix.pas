PROGRAM exprMix;

VAR i,j,k,l : LONGINT;
    m: BOOLEAN;

BEGIN
	i := 1; j := 2; k := 3; l := 4;

	m := k<j + l;
	WRITELN(m);
	WRITELN(i*l > j*k);
	WRITELN(k*l >= j+k+l)
END.
