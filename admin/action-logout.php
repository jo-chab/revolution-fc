<?php    session_start();    mysqli_close();    session_destroy();    $websiteUrl = 'https://www.revolutionfc.ca/';        header('Location: '.$websiteUrl.'?m=12');    exit();?>