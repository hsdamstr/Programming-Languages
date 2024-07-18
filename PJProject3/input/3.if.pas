PROGRAM ifcompound;

VAR a,b : LONGINT;

BEGIN
	WRITE('Enter a:');
	READ(a);
	IF (a<0) THEN
	  BEGIN
	    b := 0 - a;
	    WRITELN(b)
	  END
	ELSE
          BEGIN 
	    b := a;
	    WRITELN(b)
	  END  
END.
