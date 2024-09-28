<!DOCTYPE html>
<html>
<head>
    <title>Hiển thị mảng</title>
    <link rel="stylesheet" type="text/css" href="demo1.css">
</head>
<body>
    <h4>Các thứ trong tuần</h4>
    <?php
    $thu = ["Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"];
    for ($i = 0; $i < count($thu); $i++) { ?>
        <p><?php echo $i + 1 . ". " . $thu[$i]; ?></p>
    <?php } ?>
</body>
</html>