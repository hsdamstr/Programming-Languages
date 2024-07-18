PROGRAM ifcond;

VAR     a : BOOLEAN;
        b : LONGINT;

BEGIN
	a := FALSE;
	b := 0  - 2;
	IF (a) THEN
		WRITELN(1)
	ELSE 
		WRITELN(0);


	IF (b<0) THEN
		IF (a) THEN
			WRITELN(0)
		ELSE
			WRITELN(1)

	ELSE 
		WRITELN(0)
END.
