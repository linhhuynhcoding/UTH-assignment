<html>
    <head>
        <title>bai 3</title>
        <style>
            #ngay{
                width: 100px;
                margin-right: 10px;
                background-color: orange;
            }
            #thang{
                width: 100px;
                margin-right: 10px;
                background-color: aqua;
            }
            #nam{
                width: 100px;
                background-color:pink;
            }
            legend{
                text-align: center;
            }
            body{
                width: 500px;
                height:100px;
            }
        </style>
    </head>
    <body>
        <fieldset style="border:1px solid red;">
        <legend>Chọn ngày tháng năm sinh</legend>
        <select id="ngay">
            <option value="0">Chọn ngày</option>
            <?php 
            for($i= 1; $i <=31; $i++) {
                echo "<option value='$i'>Ngày $i</option>";
            }
            ?>
        </select>
        <select id="thang">
            <option value="0">Chọn tháng</option>
            <?php
            for($i= 1; $i <=12; $i++) {
                echo "<option value='$i'>Tháng $i</option>";
            }
            ?>
        </select>
        <select id="nam">
            <option value="0">Chọn năm</option>
            <?php
            for($i= 2020; $i >= 1930; $i--) {
                echo "<option value='$i'>Năm $i</option>";
            }
            ?>
            </fieldset>
        </select>
    </body>
</html>