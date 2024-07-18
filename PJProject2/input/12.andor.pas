PROGRAM exprANDOR;

VAR i,j,k,l : BOOLEAN;

BEGIN
	i := TRUE; j := FALSE; k := FALSE; l := TRUE;

	WRITELN(i AND j);
	WRITELN(i AND i);
	WRITELN(k AND l);
    WRITELN(k AND j);
	WRITELN(i AND l AND k);
	
	WRITELN(i OR j);
	WRITELN(i OR i);
	WRITELN(k OR l);
    WRITELN(k OR j);
	WRITELN(i OR l OR k);
	
	WRITELN(i AND j OR k AND l);
	WRITELN(i OR j AND k OR l)
END.
