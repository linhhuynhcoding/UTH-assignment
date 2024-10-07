<html>
    <head>
        <title>bai 4</title>
        <link rel="stylesheet" href="demo4.css">
    </head>
    <body>
        <?php 
        $soluong = [491 => 2, 501 => 3 , 495 => 5] ;
        $tensp = [491 => "HTC M10", 501 => "Galaxy S8" , 495 => "OPPO A92"] ;
        $gia = [491 => 2000000, 501 => 3000000 , 495 => 2500000] ;
        ?>
        <div style= "margin:10px;"><strong>GIỎ HÀNG CỦA BẠN <strong></div>
         <table border="1" width="500">
           <tr style= "background-color:blue; color: white;">
            <th>Tên sản phẩm</th>
            <th>Số lượng</th>
            <th>Giá</th>
            <th>Thành tiền</th>
           </tr>
            <?php // đưa con trỏ về đầu 3 mảng 
            reset($soluong);
            reset($tensp);
            reset($gia);
            ?>
            <?php while(key($soluong)!= null){ ?>
            <tr>
                <td><?php echo current($tensp);?> </td>
                <td><?php echo current($soluong);?> </td>
                <td><?php echo current($gia); ?> </td>
                <td><?php echo current($soluong) * current($gia);?></td>
            </tr>
            <?php //đưa con trỏ về phần tử kế của 3 array 
            next($soluong);
            next($tensp);
            next($gia);
            ?>
            <?php }?>
    </body>
</html>