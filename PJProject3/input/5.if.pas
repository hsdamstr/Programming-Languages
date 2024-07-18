PROGRAM ifinput;
	VAR a,b : LONGINT;
	
BEGIN
	WRITE('enter a:'); READ(a);
	WRITE('enter b:'); READ(b);
	
	IF (b > a) THEN 
		IF (a > 0) THEN
		  BEGIN
		    WRITE('a = ');
		    WRITELN(a)
	          END	
		ELSE
		  BEGIN
		    WRITE('b = ');
		    WRITELN(b)
	          END	
	ELSE
		IF (a < 0) THEN
		  BEGIN
		    WRITE('a = ');
		    WRITELN(a)
	          END 
		ELSE
		  BEGIN
		    WRITE('b = ');
		    WRITELN(b)
		  END
END.
