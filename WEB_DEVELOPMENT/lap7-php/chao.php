<html>
    <head>
        <title> bai 2</title>
        <style>
            .sang{
                font-size: 20px;
                color: greenyellow;
            }
            .chieu{
                font-size: 20px;
                color: orange;
            }
            .toi{
                font-size: 20px;
                color: blue;
            }
        </style>
    </head>
    <body>
        <div id="chao">
            <?php 
            $h = gmdate("H") +7 ;
            if($h <=12){
                echo "<span class='sang'> Bây giờ là $h giờ sáng! Chúc một ngày an lành!</span>";
            }
            else if($h> 12 && $h <= 18){
            echo "<span class='chieu'> Lúc này là $h giờ chiều! Chúc bạn vui </span>";
            }
            else 
            echo "<span class='toi'> Lúc này là $h giờ tối! Chúc bạn ngủ ngon </span>";
        ?>
        </div>
    </body>
</html>