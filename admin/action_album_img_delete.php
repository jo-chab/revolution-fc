<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        unset($_GET);        $image = $_POST['image'];    $album = $_POST['album'];        // Get the file URL from the database for the given element    $stmt = $db->prepare("SELECT image_url FROM ALBUMS_images WHERE id_image = ?");    $stmt->execute([$image]);    $result = $stmt->fetch(PDO::FETCH_ASSOC);        // Check if a file URL was found    if ($result) {        $fileRelativePath = urldecode($result['image_url']);        $fileAbsoluteURL = $_SERVER['DOCUMENT_ROOT'] . $fileRelativePath;                if (file_exists($fileAbsoluteURL)) {            unlink($fileAbsoluteURL);        }    }        // Delete the record from the 'images' table    $stmt3 = $db->prepare("DELETE FROM ALBUMS_images WHERE id_image = ?");    $execute3 = $stmt3->execute([$image]);        if ($execute3) {        $stmt3->closeCursor();        header('Location: https://www.revolutionfc.ca/admin/index.php?p=68&album=' . $album . '&m=1');    } else {        header('Location: https://www.revolutionfc.ca/admin/index.php?p=68&album=&' . $album . 'm=2');    }?>