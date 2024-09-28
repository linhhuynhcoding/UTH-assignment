<html>
    <head>
        <style>
            .time{
                position: absolute;
                bottom: 10px;
                right: 10px;
                color: greenyellow;
                padding: 5px 10px;
                border-radius: 5px;
                font-size: 14px;
            }
        </style>
    </head>
    <body>
        <div>
        <p style="color:red;font-size:150px;">tin tức</p>
        <div class="time">
        <?php 
        $h= gmdate("H") +7 ;
        if($h <=12){
            echo "<span class='sang'> Bây giờ là $h giờ sáng! Chúc một ngày an lành!</span>";
        }else if($h> 12 && $h <= 18){
        echo "<span class='chieu'> Lúc này là $h giờ chiều! Chúc bạn vui </span>";
        }
        else 
        echo "<span class='toi'> Lúc này là $h giờ tối! Chúc bạn ngủ ngon </span>";
    ?>
    </div>
    </div>
    </body>
</html>