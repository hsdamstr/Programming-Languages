PROGRAM simplearray;
 VAR  a : ARRAY [2..9] OF LONGINT;
      i, j: LONGINT;

BEGIN
	i := 8;
	a[i] := 9;
	WRITELN(a[i]);
	j := 9;
	a[j] := 19;
	WRITELN(a[j]);
	WRITELN(a[a[i]])
END.
