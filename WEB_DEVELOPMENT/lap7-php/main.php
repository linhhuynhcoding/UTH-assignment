<html>
    <head></head>
    <body>
        <?php 
        $page = $_GET['page'];
        switch($page){
            case "blog": require_once "tintuc.php"; break;
            case "sp": require_once "sanpham.php"; break;
            case "gt": require_once "gioithieu.php"; break;
            case "lh": require_once "lienhe.php"; break;
            default: echo "Trang chủ";
        }
        ?>
    </body>
</html>