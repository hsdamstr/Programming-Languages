PROGRAM exprRel;

VAR i,j,k,l : LONGINT;

BEGIN
	i := 1; j := 2; k := 3; l := 4;

	WRITELN(i = j);
	WRITELN(i <> i);
	WRITELN(k = k);
    WRITELN(k <> l);
	WRITELN((i = 0) = (j = 0));

	WRITELN(i < j);
	WRITELN(i <= i);
	WRITELN(l < k);
    WRITELN(k <= j);
	WRITELN((i <= j) <> FALSE);

	WRITELN(i > j);
	WRITELN(i >= i);
	WRITELN(l > k);
    WRITELN(j >= k);
	WRITELN((i >= j) = TRUE)
END.
