<html>
    <head>
        <title>Hiển thị mảng</title>
        <link rel="stylesheet" href="demo1.css">
    </head>
    <body>
    <h4>Các thứ trong tuần</h4>
    <?php 
        $thu=[
    "1"=>"Chủ nhật",
    "2"=>"Thứ hai",
    "3"=>"Thứ ba",
    "4"=>"Thứ tư",
    "5"=>"Thứ năm",
    "6"=>"Thứ sáu",
    "7"=>"Thứ bảy"
    ];
    reset($thu);
    while(key($thu) !=null){
        echo "<p>" . key($thu). ".". current($thu) ."</p>";
        next($thu);
    }
    ?>
    </body>
</html>