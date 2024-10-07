CREATE DATABASE TEST;
USE TEST;

CREATE TABLE Nhanvien (
	Id INT IDENTITY(1, 1) PRIMARY KEY,
	TenNV NVARCHAR(100),
	Luong FLOAT
);

INSERT INTO NhanVien(TenNV, Luong) VALUES (N'A', 21000);
INSERT INTO NhanVien(TenNV, Luong) VALUES (N'B', 19500);
INSERT INTO NhanVien(TenNV, Luong) VALUES (N'C', 25000);

SELECT * FROM Nhanvien;

-- -------------------------------------------------------------

DECLARE @Max_luong float;
SELECT @Max_luong = Max(Luong) FROM Nhanvien;
PRINT 'The maximum salary is ' + CONVERT(VARCHAR(20), @Max_luong);

-- -------------------------------------------------------------

ALTER TABLE NhanVien ADD Dchi NVARCHAR(100);

UPDATE NhanVien SET Dchi = N'TP.HCM';
UPDATE NhanVien SET Dchi = N'VUNG TAU' WHERE id = 2 ;

SELECT * from NhanVien;

DECLARE @NhanVien TABLE (
	Id INT PRIMARY KEY,
	TenNV NVARCHAR(100),
	Luong FLOAT,
	Dchi NVARCHAR(100) 
);

INSERT INTO @NhanVien SELECT * FROM NhanVien WHERE Dchi like 'V%';

SELECT * FROM @NhanVien;


-- --------------------------------

DECLARE @a INT, @b INT, @tich INT, @GCD INT, @LCM INT;

Set @a = 6;
Set @b = 4;
Set @tich = @a * @b;

IF (@a < @b) 
	BEGIN 
		Set @a = @a + @b;
		Set @b = @a - @b;
		Set @a = @a - @b;
	END;


WHILE (@a % @b <> 0)
	BEGIN
		Set @a = @a % @b;
		IF (@a < @b) 
			BEGIN 
				Set @a = @a + @b;
				Set @b = @a - @b;
				Set @a = @a - @b;
			END;
	END;

print 'Uoc chung: ' + CAST(@b as nvarchar(30));
print 'Boi chung: ' + CAST((@tich / @b) as nvarchar(30));
