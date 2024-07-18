PROGRAM whilearray;
 VAR  c : ARRAY [-5..5] OF LONGINT;
      a : LONGINT;
      
BEGIN
	a := -5;
	WHILE (a <= 5) DO BEGIN
	  c[a] := a;
	  a := a+1
	END;

  	a := -5;
	WHILE (a <= 5) DO BEGIN
	  IF (a > 0) THEN
	    WRITELN(0-c[a])
          ELSE
            WRITELN(0);
	  a := a+1
	END
END.
