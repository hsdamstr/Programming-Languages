PROGRAM exprMix;

VAR i,j,k,l,m : LONGINT;
    n: BOOLEAN;
BEGIN
	WRITE('i= ');
	READ(i);
	WRITE('j= ');
	READ(j);
	WRITE('k= ');
	READ(k);
	WRITE('l= ');
	READ(l);
	WRITE('m= ');
	READ(m);
	n := (k < j + l) AND (NOT (i <> k));
	WRITELN(n);
	WRITELN((i*l > j*k) OR (1 <=m));
	WRITELN((k*l > j+k+l) AND (i <> j) OR (l >m));
	WRITELN((l DIV j - i > m) AND (k + l * m <> l + k * m))
END.
