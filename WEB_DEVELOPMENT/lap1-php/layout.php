<html>
    <head>
        <title>bai 5</title>
        <link rel="stylesheet" href="c1.css">
        <link rel="stylesheet" href="c2.css">
    </head>
    <body>
        <div class="container">
            <header class="row"><?php require_once("header.php"); ?></header>
            <nav class="row"><?php require_once("menu.php"); ?></nav>
            <div class="row">
                <main class="col-9"><?php require_once("main.php"); ?></main>
                <aside class="col-3"><?php require_once("aside.php"); ?></aside>
            </div>
            <footer class="row"><?php require_once("footer.php");?> </footer>
        </div>
        <?php if(date("w") % 2 == 0) { ?>
            <link rel="stylesheet" href="c2.css">;
            <?php }else { ?>
            <link rel="stylesheet" href="c1.css">;
            <?php }?>
    </body>
</html>