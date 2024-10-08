/*
	BÀI THỰC HÀNH SỐ 3
	==================

	**NOTES: Khởi tạo Cơ sở Dữ liệu ở Script INITQLDA.SQL

	SV. HUỲNH VŨ NHẬT LINH | 051205008812 | CN2304CLCB
	GITHUB : https://github.com/linhhuynhcoding/UTH-assignment/tree/master/DBMS
*/


USE QLDA;
-- Chỉnh sửa cột thời gian trong bảng PHANCONG
UPDATE PHANCONG SET THOIGIAN=15.321547 WHERE MA_NVIEN = '001' AND MADA = 20 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=20.5 WHERE MA_NVIEN = '001' AND MADA = 30 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=20 WHERE MA_NVIEN = '003' AND MADA = 1 AND STT = 2;
UPDATE PHANCONG SET THOIGIAN=20 WHERE MA_NVIEN = '003' AND MADA = 2 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=40.7 WHERE MA_NVIEN = '004' AND MADA = 3 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=10 WHERE MA_NVIEN = '005' AND MADA = 3 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=10 WHERE MA_NVIEN = '005' AND MADA = 10 AND STT = 2;
UPDATE PHANCONG SET THOIGIAN=10 WHERE MA_NVIEN = '005' AND MADA = 20 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=30 WHERE MA_NVIEN = '006' AND MADA = 20 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=10.7 WHERE MA_NVIEN = '007' AND MADA = 10 AND STT = 2;
UPDATE PHANCONG SET THOIGIAN=30 WHERE MA_NVIEN = '007' AND MADA = 30 AND STT = 2;
UPDATE PHANCONG SET THOIGIAN=35.2 WHERE MA_NVIEN = '008' AND MADA = 10 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=5 WHERE MA_NVIEN = '008' AND MADA = 30 AND STT = 2;
UPDATE PHANCONG SET THOIGIAN=32.54 WHERE MA_NVIEN = '009' AND MADA = 1 AND STT = 1;
UPDATE PHANCONG SET THOIGIAN=8.9 WHERE MA_NVIEN = '009' AND MADA = 2 AND STT = 3;

USE QLDA;
SELECT * FROM PHANCONG;
SELECT * FROM DEAN;


-- Với mỗi đề án, liệt kê tên đề án và tổng số giờ làm việc một tuần của tất cả các nhân viên tham dự đề án đó.

-- o Xuất định dạng “tổng số giờ làm việc” kiểu decimal với 2 số thập phân.
-- o Xuất định dạng “tổng số giờ làm việc” kiểu varchar

DECLARE @PHANCONGTABLE TABLE(MADA INT, TENDEAN NVARCHAR(50), TONGGIOLAM FLOAT);

INSERT INTO @PHANCONGTABLE 
	SELECT 
		A.MADA,
		B.TENDEAN,
		SUM(A.THOIGIAN) AS TONGTHOIGIAN 
	FROM 
		PHANCONG A
		INNER JOIN DEAN B ON A.MADA = B.MADA
	GROUP BY
		B.TENDEAN, A.MADA;

DECLARE @index int = 1;
DECLARE @max int;
SELECT @max = COUNT(*) FROM @PHANCONGTABLE;

WHILE (@index <= @max)
	BEGIN
		DECLARE @tendean NVARCHAR(50), @sogiolam FLOAT;
		SET @tendean = (SELECT TENDEAN FROM @PHANCONGTABLE ORDER BY MADA ASC OFFSET (@index - 1) ROWS FETCH NEXT 1 ROWS ONLY);
		SET @sogiolam = (SELECT TONGGIOLAM FROM @PHANCONGTABLE ORDER BY MADA ASC OFFSET (@index - 1) ROWS FETCH NEXT 1 ROWS ONLY);

		PRINT + N'Tổng số giờ làm việc của tất cả các nhân viên tham dự đề án "' + @tendean + N'" là ' + CAST(ROUND(@sogiolam, 2) AS NVARCHAR(10)) + N' giờ/ tuần!';
		SET @index = @index + 1;
	END

-- Với mỗi phòng ban, liệt kê tên phòng ban và lương trung bình của những nhân viên làm việc cho phòng ban đó.

-- o Xuất định dạng “luong trung bình” kiểu decimal với 2 số thập phân, sử dụng dấu phẩy để phân biệt phần nguyên và phần thập phân.
-- o Xuất định dạng “luong trung bình” kiểu varchar. Sử dụng dấu phẩy tách cứ mỗi 3 chữ số trong chuỗi ra, gợi ý dùng thêm các hàm Left, Replace

DECLARE @LUONGTABLE TABLE(MAPNG INT, TENPNG NVARCHAR(50), LUONGTRUNGBINH FLOAT);

INSERT INTO @LUONGTABLE 
	SELECT 
		A.MAPNG,
		A.TENPNG,
		B.LUONGTRUNGBINH
	FROM 
		PHONGBAN A
		INNER JOIN (
			SELECT 
				PHG,
				AVG (LUONG) AS LUONGTRUNGBINH
			FROM NHANVIEN
			GROUP BY PHG
		) AS B ON A.MAPNG = B.PHG

DECLARE @index int = 1;
DECLARE @max int;
SELECT @max = COUNT(*) FROM @LUONGTABLE;

WHILE (@index <= @max)
	BEGIN
		DECLARE @tenphongban NVARCHAR(50), @ltb DECIMAL(10, 2);
		SET @tenphongban = (SELECT TENPNG FROM @LUONGTABLE ORDER BY MAPNG ASC OFFSET (@index - 1) ROWS FETCH NEXT 1 ROWS ONLY);
		SET @ltb = (SELECT LUONGTRUNGBINH FROM @LUONGTABLE ORDER BY MAPNG ASC OFFSET (@index - 1) ROWS FETCH NEXT 1 ROWS ONLY);

		PRINT + N'Lương trung bình của những nhân viên làm việc cho phòng ban "' + @tenphongban + N'" là ' + CONVERT(NVARCHAR, CAST(@ltb AS VARCHAR), 10) + N'!';
		SET @index = @index + 1;
	END


	--Bài 3
WITH Employee_Family_Count AS (
    SELECT NV.MANV, NV.HONV, NV.TENLOTNV, NV.TENNV, NV.DCHI, COUNT(TN.TENTN) AS FamilyCount
    FROM NHANVIEN NV
    JOIN THANNHAN TN ON NV.MANV = TN.MA_NVIEN
    GROUP BY NV.MANV, NV.HONV, NV.TENLOTNV, NV.TENNV, NV.DCHI
)
SELECT 
    UPPER(EFC.HONV) AS HONV, 
    LOWER(EFC.TENLOTNV) AS TENLOTNV, 
    LOWER(SUBSTRING(EFC.TENNV, 1, 1))+ UPPER(SUBSTRING(EFC.TENNV, 2, 1))  + LOWER(SUBSTRING(EFC.TENNV, 3, LEN(EFC.TENNV) - 2)) AS TENNV,
   
    CASE 
        WHEN CHARINDEX(',', EFC.DCHI) > 0 
        THEN LTRIM(RTRIM(SUBSTRING(EFC.DCHI, CHARINDEX(' ', EFC.DCHI) + 1, CHARINDEX(',', EFC.DCHI) - CHARINDEX(' ', EFC.DCHI) - 1)))
        ELSE LTRIM(RTRIM(SUBSTRING(EFC.DCHI, CHARINDEX(' ', EFC.DCHI) + 1, LEN(EFC.DCHI))))
    END AS DCHI
FROM Employee_Family_Count EFC
WHERE EFC.FamilyCount > 2;
-- Tên trưởng phòng thay thế
WITH DepartmentEmployeeCount AS (
    SELECT PB.MAPNG, PB.TENPNG, COUNT(NV.MANV) AS EmployeeCount, PB.TRPNG
    FROM PHONGBAN PB
    JOIN NHANVIEN NV ON PB.MAPNG = NV.MANV
    GROUP BY PB.MAPNG, PB.TENPNG, PB.TRPNG
)
SELECT TOP 1 
    DEC.TENPNG AS DepartmentName, 
    NV.HONV + ' ' + NV.TENLOTNV + ' ' + NV.TENNV AS DepartmentHead, 
    'Fpoly' AS NewDepartmentHead 
FROM DepartmentEmployeeCount DEC
JOIN NHANVIEN NV ON DEC.TRPNG = NV.MANV
ORDER BY DEC.EmployeeCount DESC; 

--Bài 4 
--1. NV sinh năm 60 - 65 
SELECT HONV, TENLOTNV, TENNV, NGSINH
FROM NHANVIEN
WHERE YEAR(NGSINH) BETWEEN 1960 AND 1965;
--2. Tuổi nhân viên đến tính hiện tại
SELECT HONV, TENLOTNV, TENNV,
       DATEDIFF(YEAR, NGSINH, GETDATE()) AS Tuoi
FROM NHANVIEN;
--3. Dựa vào dữ liệu NGSINH, cho biết nhân viên sinh vào thứ mấy
SELECT HONV, TENLOTNV, TENNV, NGSINH,
       DATENAME(WEEKDAY, NGSINH) AS NgaySinh
FROM NHANVIEN;
--4. Cho biết số lượng nhân viên, tên trưởng phòng, ngày nhận chức trưởng phòng và ngày nhận chức trưởng phòng hiển thị theo định dạng dd-mm-yy
SELECT COUNT(NV.MANV) AS SoLuongNV,
       PB.TENPNG AS TenPhong,
       NV.HONV + ' ' + NV.TENLOTNV + ' ' + NV.TENNV AS TenTruongPhong,
       CONVERT(VARCHAR(10), PB.NG_NHANCHUC, 105) AS NgayNhanChuc -- Định dạng dd-mm-yyyy
FROM PHONGBAN PB
JOIN NHANVIEN NV ON PB.TRPNG = NV.MANV
GROUP BY PB.TENPNG, NV.HONV, NV.TENLOTNV, NV.TENNV, PB.NG_NHANCHUC;
