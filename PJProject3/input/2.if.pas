PROGRAM ifelse;
VAR a : LONGINT;
BEGIN
	WRITE('Enter a:');
	READ(a);
	IF (a > 0) THEN
          WRITELN(1)
	ELSE
          WRITELN(0);  
	WRITELN('Complete!')
END.
