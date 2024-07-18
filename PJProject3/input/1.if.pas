PROGRAM iftest;
VAR a : LONGINT;
BEGIN
	WRITE('Enter a:');
	READ(a);
	IF (a <> 0) THEN
          WRITELN(1);
	WRITELN('Complete!')
END.
