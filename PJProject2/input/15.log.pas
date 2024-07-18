PROGRAM exprLog;

VAR i,j,k,l : LONGINT;
    m: BOOLEAN;
BEGIN
	i := 1; j := 2; k := 3; l := 4;

	m := i<j;
	WRITELN(NOT m);
	WRITELN(i = j);
	WRITELN(i = i);
	WRITELN(l > k);
	WRITELN(j >= j);
	WRITELN(k <= i);
	WRITELN(i <> j);
	WRITELN(NOT (l>k));
	WRITELN((i > j) OR (l > k));
	WRITELN((j > i) AND (l > k));
    	WRITELN(((i = j) OR (i <j)) AND (k <> l))

END.
