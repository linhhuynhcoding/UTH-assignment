<html>
    <head>
        <title>bai 3</title>
        <link rel="stylesheet" href="demo3-1.css">
    </head>
    <body>
        <?php 
        $ho = $_GET['ho'];
        $ten = $_GET['ten'];
        $ngaysinh = $_GET['ngaysinh'];
        $diem= $_GET['diem'];
        switch(true){
        case($diem >= 9 ) :$xeploai = "Xuất sắc";break;
        case($diem >=8): $xeploai = "Giỏi"; break;
        case($diem >=6.5): $xeploai = "Khá"; break;
        case($diem >=5): $xeploai = "Trung bình";break;
        case($diem >=3.5): $xeplooai = "Yếu";break;
        default: $xeploai = "Kém";
        ?>
        <div>
            <?php
        echo "<h2>Thông tin sinh viên</h2>";
        echo "<p>Họ tên: ". $ho ." ". $ten ."</p>";
        echo "<p>Ngày sinh: ". $ngaysinh."</p>";
        echo "<P>Điểm: ". $diem ."</P>";
        echo "<p>Xếp loại: ".$xeploai."</p>"; 
        }
        ?>
        </div>
    </body>
</html>
