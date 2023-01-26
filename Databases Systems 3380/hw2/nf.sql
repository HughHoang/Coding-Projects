/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
/*checking if pk is null*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2 where k1 is null OR k2 is null;
/*counting total rows*/
SELECT COUNT(*) FROM hw2_1nf_invalidpkk1k2;
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k1'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'k2'
SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'hw2_1nf_invalidpkk1k2' AND COLUMN_NAME = 'a'
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT k1,k2 FROM hw2_1nf_invalidpkk1k2) AS t;
/*counting unique pks*/
SELECT COUNT(*) FROM (SELECT DISTINCT a FROM hw2_1nf_invalidpkk1k2) AS t;
/*check nf1*/
SELECT COUNT(*) FROM (SELECT k1,k2 FROM hw2_1nf_invalidpkk1k2 GROUP BY k1,k2,a) AS t;
/*check func between*/k1 and k2
SELECT k1, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT k2) > 1;
/*check func between*/k1 and a
SELECT k1, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k1 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/k2 and k1
SELECT k2, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/k2 and a
SELECT k2, COUNT(DISTINCT a) FROM hw2_1nf_invalidpkk1k2 GROUP BY k2 HAVING COUNT(DISTINCT a) > 1;
/*check func between*/a and k1
SELECT a, COUNT(DISTINCT k1) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k1) > 1;
/*check func between*/a and k2
SELECT a, COUNT(DISTINCT k2) FROM hw2_1nf_invalidpkk1k2 GROUP BY a HAVING COUNT(DISTINCT k2) > 1;
