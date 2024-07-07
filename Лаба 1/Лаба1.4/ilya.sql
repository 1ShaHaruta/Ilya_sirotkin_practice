PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE ilya (id integer primary key, name text);
INSERT INTO ilya VALUES(1,'Lera Kishkurno');
INSERT INTO ilya VALUES(2,'Sirotkin Ilya');
INSERT INTO ilya VALUES(3,'Boris Britva');
INSERT INTO ilya VALUES(4,'Gena Kudin');
COMMIT;
