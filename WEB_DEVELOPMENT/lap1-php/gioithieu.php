<html>
    <head>
        <title>bai 1</title>
        <link rel="stylesheet" href="demo1.css">
    </head>
    <body>
        <?php 
        $ho= "Nguyễn";
        $ten= "Tèo";
        $ngaysinh= "15/4/2000";
        $diem= 3;
        if($diem >=9) $xeploai= "Xuất sắc";
        else if($diem >=8) $xeploai = "Giỏi";
        else if($diem >=6.5) $xeploai = "Khá";
        else if($diem >=5) $xeploai = "Trung bình";
        else if($diem >=3.5) $xeploai = "Yếu";
        else $xeploai = "Kém";
        ?>
        <div id="gioithieu">
            <p style="color:aqua; background-color:red;">THÔNG TIN SINH VIÊN</p>
            <p><span>Họ tên </span> : <?php echo $ho. " ". $ten;?></p>
            <p><span>Ngày sinh</span> : <?php echo $ngaysinh;?></p>
            <p><span>Điểm </span>: <?php echo $diem;?></p>
            <p><span>Xếp loại </span> : <?php echo $xeploai;?></p>
        </div>
    </body>
</html>