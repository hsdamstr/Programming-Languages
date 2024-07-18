PROGRAM whileIf;
VAR s, i, a : LONGINT;
BEGIN
	WRITE('Enter a:');
	READ(a);

	IF (a DIV 2 * 2 = a) THEN
	BEGIN
          i := 1;
          s := 0;
	  WHILE (i <= a) DO
	    BEGIN
	       s := s + i;
               i := i + 1
            END
        END ELSE
 	BEGIN
          i := 1;
          s := 1;
	  WHILE (i <= a) DO
	    BEGIN
	       s := s * i;
               i := i + 1
            END
        END;
	WRITELN(s) 
END.
