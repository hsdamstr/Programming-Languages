PROGRAM simplearray;
 VAR  a : ARRAY [0..9] OF LONGINT;
      i : LONGINT;

BEGIN
	a[3] := 4;
	WRITELN(a[3]);
	i := 3;
	a[i] := 7;
	WRITELN(a[i]);
	i := i + 2;
	a[i] := 22;
	WRITELN(a[5])
END.
