PROGRAM exprLog;

VAR i,j,k,l: LONGINT;
    m : BOOLEAN;

BEGIN
	i := 1; j := 2; k := 3; l := 4;

	m := i<j;
	WRITELN(m);
	WRITELN(l>k);
	WRITELN(NOT (l>k));
    WRITELN(FALSE OR ((i<j) AND (k <> l)))

END.
